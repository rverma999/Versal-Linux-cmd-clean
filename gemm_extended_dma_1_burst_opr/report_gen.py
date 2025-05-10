#!/usr/bin/python3

import os
import subprocess
import re
import json
import datetime
import csv
import argparse
from pathlib import Path
import matplotlib.pyplot as plt
import pandas as pd

class AIEPerformanceCollector:
    def __init__(self, output_dir="./perf_data", project_dir="."):
        self.output_dir = output_dir
        self.project_dir = project_dir
        self.timestamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
        self.data_file = os.path.join(output_dir, "aie_performance_data.csv")
        self.config_file = os.path.join(output_dir, "aie_config_history.json")
        self.summary_file = os.path.join(output_dir, "aie_summary_report.md")
        
        # Create output directory if it doesn't exist
        os.makedirs(output_dir, exist_ok=True)
        
        # Initialize CSV file with headers if it doesn't exist
        if not os.path.exists(self.data_file):
            with open(self.data_file, 'w', newline='') as f:
                writer = csv.writer(f)
                writer.writerow([
                    "Timestamp", "Run_ID", "Matrix_M", "Matrix_K", "Matrix_N", 
                    "Mult_X", "Mult_Y", "Mult_Z", "Compute_Iterations",
                    "Total_Cycles", "Cycles_Per_Operation", "Memory_Stall_Time", 
                    "Memory_Stall_Count", "Lock_Stall_Time", "Lock_Stall_Count",
                    "Total_Instructions", "Total_Tiles_Used", "Max_Tile_Utilization",
                    "DMA_Transfer_Time", "DMA_Bandwidth", "Speedup_vs_Baseline"
                ])
                
        # Initialize config history if it doesn't exist
        if not os.path.exists(self.config_file):
            with open(self.config_file, 'w') as f:
                json.dump([], f)
        
        self.run_id = self._get_next_run_id()
                
    def _get_next_run_id(self):
        """Get the next run ID by checking the existing data"""
        try:
            with open(self.data_file, 'r') as f:
                reader = csv.reader(f)
                next(reader)  # Skip header
                max_id = 0
                for row in reader:
                    if len(row) > 1:
                        max_id = max(max_id, int(row[1]))
                return max_id + 1
        except:
            return 1
            
    def collect_config_parameters(self):
        """Extract configuration parameters from include.h and other files"""
        config_params = {}
        
        # Parse include.h for matrix dimensions and multipliers
        include_file = os.path.join(self.project_dir, "aie/kernels/include.h")
        if os.path.exists(include_file):
            with open(include_file, 'r') as f:
                content = f.read()
                
                # Extract matrix dimensions
                matrix_m = re.search(r'#define\s+single_M\s+(\d+)', content)
                matrix_k = re.search(r'#define\s+single_K\s+(\d+)', content)
                matrix_n = re.search(r'#define\s+single_N\s+(\d+)', content)
                
                # Extract multipliers
                mult_x = re.search(r'#define\s+mult_X\s+(\d+)', content)
                mult_y = re.search(r'#define\s+mult_Y\s+(\d+)', content)
                mult_z = re.search(r'#define\s+mult_Z\s+(\d+)', content)
                
                # Extract API dimensions
                api_m = re.search(r'#define\s+M_API\s+(\d+)', content)
                api_k = re.search(r'#define\s+K_API\s+(\d+)', content)
                api_n = re.search(r'#define\s+N_API\s+(\d+)', content)
                
                if matrix_m: config_params['Matrix_M'] = int(matrix_m.group(1))
                if matrix_k: config_params['Matrix_K'] = int(matrix_k.group(1))
                if matrix_n: config_params['Matrix_N'] = int(matrix_n.group(1))
                if mult_x: config_params['Mult_X'] = int(mult_x.group(1))
                if mult_y: config_params['Mult_Y'] = int(mult_y.group(1))
                if mult_z: config_params['Mult_Z'] = int(mult_z.group(1))
                if api_m: config_params['API_M'] = int(api_m.group(1))
                if api_k: config_params['API_K'] = int(api_k.group(1))
                if api_n: config_params['API_N'] = int(api_n.group(1))
        
        # Parse kernel file for compute iterations
        kernel_file = os.path.join(self.project_dir, "aie/kernels/kernels.cc")
        if os.path.exists(kernel_file):
            with open(kernel_file, 'r') as f:
                content = f.read()
                compute_iter = re.search(r'#define\s+COMPUTE_ITERATIONS\s+(\d+)', content)
                if compute_iter:
                    config_params['Compute_Iterations'] = int(compute_iter.group(1))
                else:
                    config_params['Compute_Iterations'] = 1
        
        # Add any missing parameters with default values
        for param in ['Matrix_M', 'Matrix_K', 'Matrix_N', 'Mult_X', 'Mult_Y', 'Mult_Z', 'Compute_Iterations']:
            if param not in config_params:
                if param in ['Mult_X', 'Mult_Y', 'Mult_Z', 'Compute_Iterations']:
                    config_params[param] = 1
                else:
                    config_params[param] = 0
        
        return config_params
    
    def parse_simulation_results(self):
        """Parse the simulation results from aiesimulator_output"""
        results = {}
        
        # Parse summary file
        summary_file = os.path.join(self.project_dir, "aiesimulator_output/default.aierun_summary")
        if not os.path.exists(summary_file):
            print(f"Warning: Summary file {summary_file} not found")
            return results
            
        # Use grep or similar to extract key metrics
        try:
            # Total cycles
            cmd = f"grep -A 1 'Total cycle count' {summary_file}"
            output = subprocess.check_output(cmd, shell=True).decode('utf-8')
            cycles_match = re.search(r':\s+(\d+)', output)
            if cycles_match:
                results['Total_Cycles'] = int(cycles_match.group(1))
                
            # Memory stalls
            memory_stall_file = os.path.join(self.project_dir, "aiesimulator_output/memory_stalls.csv")
            if os.path.exists(memory_stall_file):
                with open(memory_stall_file, 'r') as f:
                    reader = csv.DictReader(f)
                    total_stall_time = 0
                    total_stall_count = 0
                    for row in reader:
                        if 'Stall Time (ps)' in row and 'Count' in row:
                            total_stall_time += int(row['Stall Time (ps)'])
                            total_stall_count += int(row['Count'])
                    results['Memory_Stall_Time'] = total_stall_time
                    results['Memory_Stall_Count'] = total_stall_count
            
            # Lock stalls
            lock_stall_file = os.path.join(self.project_dir, "aiesimulator_output/lock_stalls.csv")
            if os.path.exists(lock_stall_file):
                with open(lock_stall_file, 'r') as f:
                    reader = csv.DictReader(f)
                    total_lock_time = 0
                    total_lock_count = 0
                    for row in reader:
                        if 'Stall Time (ps)' in row and 'Count' in row:
                            total_lock_time += int(row['Stall Time (ps)'])
                            total_lock_count += int(row['Count'])
                    results['Lock_Stall_Time'] = total_lock_time
                    results['Lock_Stall_Count'] = total_lock_count
            
            # If the specific files don't exist, try to parse from the summary file directly
            if 'Memory_Stall_Time' not in results:
                mem_stall_pattern = r'Memory Stall Time.*?(\d+)\s+ps.*?(\d+)'
                mem_match = re.search(mem_stall_pattern, open(summary_file).read(), re.DOTALL)
                if mem_match:
                    results['Memory_Stall_Time'] = int(mem_match.group(1))
                    results['Memory_Stall_Count'] = int(mem_match.group(2))
                else:
                    results['Memory_Stall_Time'] = 0
                    results['Memory_Stall_Count'] = 0
                    
            if 'Lock_Stall_Time' not in results:
                lock_stall_pattern = r'Lock Stall Time.*?(\d+)\s+ps.*?(\d+)'
                lock_match = re.search(lock_stall_pattern, open(summary_file).read(), re.DOTALL)
                if lock_match:
                    results['Lock_Stall_Time'] = int(lock_match.group(1))
                    results['Lock_Stall_Count'] = int(lock_match.group(2))
                else:
                    results['Lock_Stall_Time'] = 0
                    results['Lock_Stall_Count'] = 0
            
            # Instructions executed
            instr_pattern = r'Total instruction count.*?(\d+)'
            instr_match = re.search(instr_pattern, open(summary_file).read(), re.DOTALL)
            if instr_match:
                results['Total_Instructions'] = int(instr_match.group(1))
            else:
                results['Total_Instructions'] = 0
                
            # Count tiles used
            tiles_used_pattern = r'Tile\[(\d+),(\d+)\]'
            tile_matches = list(re.finditer(tiles_used_pattern, open(summary_file).read()))
            results['Total_Tiles_Used'] = len(set([(m.group(1), m.group(2)) for m in tile_matches]))

            # Calculate max tile utilization percentage
            # This is a simplification - real implementation would parse detailed utilization data
            results['Max_Tile_Utilization'] = 0
            if 'Total_Cycles' in results and results['Total_Cycles'] > 0:
                # Calculate based on time spent not stalled
                if results['Memory_Stall_Time'] + results['Lock_Stall_Time'] < results['Total_Cycles']:
                    compute_time = results['Total_Cycles'] - (results['Memory_Stall_Time'] + results['Lock_Stall_Time'])
                    results['Max_Tile_Utilization'] = round(compute_time / results['Total_Cycles'] * 100, 2)
            
            # DMA metrics - simplified approximation
            results['DMA_Transfer_Time'] = 0  # Would parse from DMA traces
            results['DMA_Bandwidth'] = 0      # Would calculate from transfer size and time
            
        except Exception as e:
            print(f"Error parsing simulation results: {e}")
        
        # Calculate cycles per operation (for GEMM this is cycles per multiply-accumulate)
        if 'Total_Cycles' in results and 'Matrix_M' in self.collect_config_parameters():
            params = self.collect_config_parameters()
            total_ops = params['Matrix_M'] * params['Matrix_N'] * params['Matrix_K']
            if total_ops > 0:
                results['Cycles_Per_Operation'] = round(results['Total_Cycles'] / total_ops, 4)
            else:
                results['Cycles_Per_Operation'] = 0
        else:
            results['Cycles_Per_Operation'] = 0
            
        return results
    
    def calculate_speedup(self, current_results):
        """Calculate speedup compared to baseline (first run)"""
        try:
            with open(self.data_file, 'r') as f:
                reader = csv.reader(f)
                headers = next(reader)
                cycle_idx = headers.index("Total_Cycles")
                
                first_row = next(reader, None)
                if first_row and len(first_row) > cycle_idx and first_row[cycle_idx].isdigit():
                    baseline_cycles = int(first_row[cycle_idx])
                    if baseline_cycles > 0 and 'Total_Cycles' in current_results:
                        return round(baseline_cycles / current_results['Total_Cycles'], 2)
        except Exception as e:
            print(f"Error calculating speedup: {e}")
        
        return 1.0  # Default to no speedup
        
    def save_run_data(self):
        """Save current run data to CSV and config history"""
        config_params = self.collect_config_parameters()
        results = self.parse_simulation_results()
        
        # Calculate speedup
        speedup = self.calculate_speedup(results)
        
        # Prepare row for CSV
        row = [
            self.timestamp,
            self.run_id,
            config_params.get('Matrix_M', 0),
            config_params.get('Matrix_K', 0),
            config_params.get('Matrix_N', 0),
            config_params.get('Mult_X', 1),
            config_params.get('Mult_Y', 1),
            config_params.get('Mult_Z', 1),
            config_params.get('Compute_Iterations', 1),
            results.get('Total_Cycles', 0),
            results.get('Cycles_Per_Operation', 0),
            results.get('Memory_Stall_Time', 0),
            results.get('Memory_Stall_Count', 0),
            results.get('Lock_Stall_Time', 0),
            results.get('Lock_Stall_Count', 0),
            results.get('Total_Instructions', 0),
            results.get('Total_Tiles_Used', 0),
            results.get('Max_Tile_Utilization', 0),
            results.get('DMA_Transfer_Time', 0),
            results.get('DMA_Bandwidth', 0),
            speedup
        ]
        
        # Save to CSV
        with open(self.data_file, 'a', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(row)
        
        # Save config to history
        config_history = []
        with open(self.config_file, 'r') as f:
            try:
                config_history = json.load(f)
            except json.JSONDecodeError:
                config_history = []
        
        # Add current config with results
        config_entry = {
            "run_id": self.run_id,
            "timestamp": self.timestamp,
            "config": config_params,
            "results": results,
            "speedup": speedup
        }
        config_history.append(config_entry)
        
        with open(self.config_file, 'w') as f:
            json.dump(config_history, f, indent=2)
            
        print(f"Run #{self.run_id} data saved successfully.")
        return row
        
    def generate_charts(self):
        """Generate performance analysis charts"""
        try:
            # Load data
            df = pd.read_csv(self.data_file)
            
            if len(df) < 1:
                print("Not enough data to generate charts")
                return
                
            # Create output directory for charts
            charts_dir = os.path.join(self.output_dir, "charts")
            os.makedirs(charts_dir, exist_ok=True)
            
            # 1. Speedup over runs
            plt.figure(figsize=(10, 6))
            plt.plot(df['Run_ID'], df['Speedup_vs_Baseline'], marker='o', linestyle='-')
            plt.title('Speedup vs Baseline Over Optimization Runs')
            plt.xlabel('Run ID')
            plt.ylabel('Speedup (x)')
            plt.grid(True)
            plt.savefig(os.path.join(charts_dir, 'speedup_chart.png'))
            plt.close()
            
            # 2. Cycles per operation trend
            plt.figure(figsize=(10, 6))
            plt.plot(df['Run_ID'], df['Cycles_Per_Operation'], marker='o', linestyle='-')
            plt.title('Cycles Per Operation Over Optimization Runs')
            plt.xlabel('Run ID')
            plt.ylabel('Cycles per Operation')
            plt.grid(True)
            plt.savefig(os.path.join(charts_dir, 'cycles_per_op_chart.png'))
            plt.close()
            
            # 3. Stall time distribution
            plt.figure(figsize=(12, 6))
            
            # Calculate compute time (approximation)
            df['Compute_Time'] = df['Total_Cycles'] - df['Memory_Stall_Time'] - df['Lock_Stall_Time']
            
            # Create stacked bar chart
            runs = df['Run_ID']
            compute = df['Compute_Time']
            mem_stall = df['Memory_Stall_Time']
            lock_stall = df['Lock_Stall_Time']
            
            plt.bar(runs, compute, label='Compute Time')
            plt.bar(runs, mem_stall, bottom=compute, label='Memory Stall Time')
            plt.bar(runs, lock_stall, bottom=compute+mem_stall, label='Lock Stall Time')
            
            plt.title('Time Distribution by Run')
            plt.xlabel('Run ID')
            plt.ylabel('Cycles')
            plt.legend()
            plt.savefig(os.path.join(charts_dir, 'time_distribution_chart.png'))
            plt.close()
            
            # 4. Tile utilization
            plt.figure(figsize=(10, 6))
            plt.plot(df['Run_ID'], df['Total_Tiles_Used'], marker='o', linestyle='-')
            plt.title('Number of AIE Tiles Used')
            plt.xlabel('Run ID')
            plt.ylabel('Tiles')
            plt.grid(True)
            plt.savefig(os.path.join(charts_dir, 'tiles_used_chart.png'))
            plt.close()
            
            # 5. Matrix size vs Cycle count
            if len(df) > 1:
                plt.figure(figsize=(10, 6))
                # Calculate total matrix elements (M*N*K)
                df['Matrix_Size'] = df['Matrix_M'] * df['Matrix_N'] * df['Matrix_K']
                plt.scatter(df['Matrix_Size'], df['Total_Cycles'])
                
                # Add run IDs as labels
                for i, run_id in enumerate(df['Run_ID']):
                    plt.annotate(str(run_id), (df['Matrix_Size'].iloc[i], df['Total_Cycles'].iloc[i]))
                
                plt.title('Matrix Size vs Execution Cycles')
                plt.xlabel('Matrix Elements (M×N×K)')
                plt.ylabel('Total Cycles')
                plt.grid(True)
                plt.savefig(os.path.join(charts_dir, 'matrix_size_vs_cycles.png'))
                plt.close()
            
            print(f"Charts generated in {charts_dir}")
            
        except Exception as e:
            print(f"Error generating charts: {e}")
            
    def generate_summary_report(self):
        """Generate markdown summary report with key findings"""
        try:
            # Load data
            df = pd.read_csv(self.data_file)
            
            if len(df) < 1:
                print("Not enough data to generate report")
                return
                
            # Generate report content
            report = [
                "# AIE Performance Optimization Report\n",
                f"Generated: {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n",
                "## Summary of Optimization Runs\n",
                f"Total runs analyzed: {len(df)}\n",
                f"Best performance (lowest cycles): Run #{df.loc[df['Total_Cycles'].idxmin()]['Run_ID']} with {df['Total_Cycles'].min()} cycles\n",
                f"Maximum speedup achieved: {df['Speedup_vs_Baseline'].max()}x\n\n",
                "## Key Performance Metrics\n",
                "| Run ID | Matrix Size | Tiles Used | Total Cycles | Cycles/Op | Mem Stalls | Lock Stalls | Speedup |\n",
                "|--------|-------------|------------|--------------|-----------|------------|-------------|---------|"
            ]
            
            # Add row for each run
            for _, row in df.iterrows():
                matrix_size = f"{int(row['Matrix_M'])}×{int(row['Matrix_K'])}×{int(row['Matrix_N'])}"
                report.append(f"| {int(row['Run_ID'])} | {matrix_size} | {int(row['Total_Tiles_Used'])} | " + 
                             f"{int(row['Total_Cycles'])} | {row['Cycles_Per_Operation']:.4f} | " +
                             f"{int(row['Memory_Stall_Count'])} | {int(row['Lock_Stall_Count'])} | {row['Speedup_vs_Baseline']:.2f}x |")
            
            # Add observations and insights
            report.extend([
                "\n## Performance Observations\n",
                
                "### Scaling Analysis\n",
                f"- Matrix size scaling effect: {self._analyze_matrix_scaling(df)}\n",
                f"- Tile count scaling effect: {self._analyze_tile_scaling(df)}\n",
                
                "### Bottleneck Analysis\n",
                f"- Dominant bottleneck: {self._identify_bottleneck(df)}\n",
                
                "### Optimization Impact\n",
                f"- Most effective optimization: {self._most_effective_optimization(df)}\n",
                
                "\n## Charts\n",
                "The following charts have been generated in the 'charts' directory:\n",
                "1. Speedup vs Baseline\n",
                "2. Cycles Per Operation\n",
                "3. Time Distribution by Run\n",
                "4. Tiles Used\n",
                "5. Matrix Size vs Execution Cycles\n"
            ])
            
            # Write report
            with open(self.summary_file, 'w') as f:
                f.write("\n".join(report))
                
            print(f"Summary report generated: {self.summary_file}")
            
        except Exception as e:
            print(f"Error generating summary report: {e}")
    
    def _analyze_matrix_scaling(self, df):
        """Analyze how performance scales with matrix size"""
        if len(df) < 2:
            return "Insufficient data for analysis"
            
        df['Matrix_Elements'] = df['Matrix_M'] * df['Matrix_N'] * df['Matrix_K']
        
        # Find runs with different matrix sizes but same tile configuration
        df_sorted = df.sort_values('Matrix_Elements')
        
        if df['Matrix_Elements'].nunique() < 2:
            return "No matrix size variation found in experiments"
            
        # Simple linear regression on matrix elements vs cycles
        try:
            from scipy import stats
            slope, intercept, r_value, p_value, std_err = stats.linregress(
                df['Matrix_Elements'], df['Total_Cycles'])
                
            if r_value**2 > 0.8:
                return f"Strong correlation (R²={r_value**2:.2f}) between matrix size and cycles. " + \
                       f"Each additional matrix element adds approximately {slope:.2f} cycles."
            else:
                return "Weak correlation between matrix size and execution cycles. " + \
                       "Other factors may dominate performance."
        except:
            # Fallback if scipy not available
            max_elem = df['Matrix_Elements'].max()
            min_elem = df['Matrix_Elements'].min()
            max_cycles = df.loc[df['Matrix_Elements'].idxmax()]['Total_Cycles']
            min_cycles = df.loc[df['Matrix_Elements'].idxmin()]['Total_Cycles']
            
            if max_elem > min_elem:
                scaling = (max_cycles - min_cycles) / (max_elem - min_elem)
                return f"Matrix size scaling factor: ~{scaling:.2f} cycles per element"
            else:
                return "Unable to determine matrix scaling factor"
    
    def _analyze_tile_scaling(self, df):
        """Analyze how performance scales with tile count"""
        if len(df) < 2:
            return "Insufficient data for analysis"
            
        df['Total_Multiplier'] = df['Mult_X'] * df['Mult_Y'] * df['Mult_Z']
        
        if df['Total_Multiplier'].nunique() < 2:
            return "No variation in tile count configuration"
            
        # Find ideal scaling - execution time should decrease linearly with more tiles
        try:
            ideal_scaling = []
            for mult, group in df.groupby('Total_Multiplier'):
                if len(group) > 0:
                    avg_cycles = group['Total_Cycles'].mean()
                    ideal_scaling.append((mult, avg_cycles))
            
            if len(ideal_scaling) >= 2:
                ideal_scaling.sort()
                base_mult, base_cycles = ideal_scaling[0]
                
                scaling_efficiency = []
                for mult, cycles in ideal_scaling[1:]:
                    ideal = base_cycles * (base_mult / mult)
                    actual = cycles
                    efficiency = ideal / actual if actual > 0 else 0
                    scaling_efficiency.append(efficiency)
                
                avg_efficiency = sum(scaling_efficiency) / len(scaling_efficiency)
                
                if avg_efficiency > 0.8:
                    return f"Excellent tile scaling efficiency: {avg_efficiency:.2f}. " + \
                           "Performance scales nearly linearly with tile count."
                elif avg_efficiency > 0.5:
                    return f"Good tile scaling efficiency: {avg_efficiency:.2f}. " + \
                           "Some overhead when adding more tiles."
                else:
                    return f"Poor tile scaling efficiency: {avg_efficiency:.2f}. " + \
                           "Significant overhead when adding more tiles."
            else:
                return "Insufficient variation in tile count for analysis"
        except:
            return "Unable to determine tile scaling efficiency"
    
    def _identify_bottleneck(self, df):
        """Identify the primary bottleneck in performance"""
        if len(df) < 1:
            return "Insufficient data for analysis"
            
        # Calculate average proportions of time
        df['Total_Time'] = df['Total_Cycles']
        df['Compute_Time'] = df['Total_Cycles'] - df['Memory_Stall_Time'] - df['Lock_Stall_Time']
        
        avg_compute_pct = (df['Compute_Time'] / df['Total_Time']).mean() * 100
        avg_memory_pct = (df['Memory_Stall_Time'] / df['Total_Time']).mean() * 100
        avg_lock_pct = (df['Lock_Stall_Time'] / df['Total_Time']).mean() * 100
        
        if avg_compute_pct >= max(avg_memory_pct, avg_lock_pct):
            return f"Compute-bound ({avg_compute_pct:.1f}% of time spent computing). " + \
                   "Focus on algorithmic optimizations and vectorization."
        elif avg_memory_pct >= avg_lock_pct:
            return f"Memory-bound ({avg_memory_pct:.1f}% of time in memory stalls). " + \
                   "Focus on memory access patterns and DMA optimizations."
        else:
            return f"Synchronization-bound ({avg_lock_pct:.1f}% of time in lock stalls). " + \
                   "Focus on reducing lock contention and improving parallelism."
    
    def _most_effective_optimization(self, df):
        """Identify which optimization had the biggest impact"""
        if len(df) < 2:
            return "Insufficient data for analysis"
            
        # Calculate improvement between consecutive runs
        improvements = []
        
        for i in range(1, len(df)):
            prev_cycles = df.iloc[i-1]['Total_Cycles']
            curr_cycles = df.iloc[i]['Total_Cycles']
            
            if prev_cycles > 0:
                improvement = (prev_cycles - curr_cycles) / prev_cycles * 100
                run_id = df.iloc[i]['Run_ID']
                
                # Identify what changed
                changes = []
                for param in ['Matrix_M', 'Matrix_K', 'Matrix_N', 'Mult_X', 'Mult_Y', 'Mult_Z', 'Compute_Iterations']:
                    prev_val = df.iloc[i-1][param]
                    curr_val = df.iloc[i][param]
                    
                    if curr_val != prev_val:
                        changes.append(f"{param}: {prev_val} → {curr_val}")
                
                if changes and improvement != 0:
                    improvements.append((run_id, improvement, changes))
        
        if improvements:
            # Find the most effective optimization
            best_run, best_improvement, best_changes = max(improvements, key=lambda x: x[1])
            
            if best_improvement > 0:
                return f"Run #{best_run} improved performance by {best_improvement:.1f}% " + \
                       f"with changes: {', '.join(best_changes)}"
            else:
                return f"No positive improvements found between consecutive runs"
        else:
            return "No measurable optimization impact detected"

'''
# Approach for Persistent Data Collection with report_gen.py

## How the Script Works
- The script will collect performance data from each run and append it to a CSV file
- Each run's data is stored with a timestamp and configuration parameters
- The data file is stored OUTSIDE the build directory to prevent it from being deleted by 'make clean'

## Implementation Steps

1. **Create the Script Location**
   - Create a 'scripts' directory at the same level as your project directories
   - Place report_gen.py in this directory to keep it separate from build artifacts

2. **Modify the Makefile**
   - Add a script call to each relevant make target
   - Example addition to Makefile targets that run benchmarks:
     ```
     analyze: $(TARGET)
         $(VPP) -p -t $(TARGET) -r $(REPORT_DIR)/$(basename $(notdir $(TARGET))).run_summary
         cd $(dir $(TARGET)) && XCL_EMULATION_MODE=$(MODE) ./$(notdir $(TARGET)) $(ARGS)
         ../../scripts/report_gen.py --project gemm --mode $(MODE) --report $(REPORT_DIR)/$(basename $(notdir $(TARGET))).run_summary
     ```

3. **Data Storage**
   - The script stores data in '../performance_data.csv' (relative to project dir)
   - This file location is outside build directories so 'make clean' won't remove it
   - Each run appends a new row with timestamp, project name, and performance metrics

4. **Visualization Support**
   - The CSV format makes it easy to import into Excel, Python, or other visualization tools
   - Script includes a '--generate-charts' option to create basic visualization of collected data
   - For publication-quality charts, import the CSV into specialized data visualization tools

5. **Usage Examples**
   - Manual run: `./scripts/report_gen.py --project gemm --mode hw`
   - Automatic run: Triggered by make targets as configured above
   - Generate charts: `./scripts/report_gen.py --generate-charts`
'''

def main():
    parser = argparse.ArgumentParser(description="AIE Performance Data Collection Tool")
    parser.add_argument("--dir", default=".", help="Directory containing the AIE project")
    parser.add_argument("--output", default="./perf_data", help="Directory to store performance data and reports")
    parser.add_argument("--action", choices=["collect", "report", "charts", "all"], default="all",
                        help="Action to perform: collect data, generate report, generate charts, or all")
    parser.add_argument("--comment", default="", help="Optional comment to add to this run's metadata")
    parser.add_argument("--baseline", type=int, help="Run ID to use as baseline for speedup calculation")
    parser.add_argument("--list", action="store_true", help="List all recorded runs")
    args = parser.parse_args()
    
    collector = AIEPerformanceCollector(output_dir=args.output, project_dir=args.dir)
    
    if args.list:
        # List all recorded runs
        try:
            df = pd.read_csv(os.path.join(args.output, "aie_performance_data.csv"))
            print("\nRecorded Optimization Runs:")
            print("===========================")
            for _, row in df.iterrows():
                matrix_size = f"{int(row['Matrix_M'])}×{int(row['Matrix_K'])}×{int(row['Matrix_N'])}"
                tiles = f"{int(row['Mult_X'])}×{int(row['Mult_Y'])}×{int(row['Mult_Z'])}"
                print(f"Run #{int(row['Run_ID'])}: [{row['Timestamp']}] Matrix: {matrix_size}, Tiles: {tiles}, " + 
                     f"Cycles: {int(row['Total_Cycles'])}, Speedup: {row['Speedup_vs_Baseline']:.2f}x")
            return
        except Exception as e:
            print(f"Error listing runs: {e}")
            return
    
    if args.action in ["collect", "all"]:
        print(f"Collecting performance data from {args.dir}...")
        row = collector.save_run_data()
        
        # Display summary of collected data
        config = collector.collect_config_parameters()
        results = collector.parse_simulation_results()
        print("\nSummary of Run #{}:".format(collector.run_id))
        print("=====================")
        print(f"Matrix Dimensions: {config.get('Matrix_M', 0)}×{config.get('Matrix_K', 0)}×{config.get('Matrix_N', 0)}")
        print(f"Tile Configuration: {config.get('Mult_X', 1)}×{config.get('Mult_Y', 1)}×{config.get('Mult_Z', 1)}")
        print(f"Total Cycles: {results.get('Total_Cycles', 0):,}")
        print(f"Cycles per Operation: {results.get('Cycles_Per_Operation', 0):.4f}")
        print(f"Memory Stalls: {results.get('Memory_Stall_Count', 0)} ({results.get('Memory_Stall_Time', 0):,} ps)")
        print(f"Lock Stalls: {results.get('Lock_Stall_Count', 0)} ({results.get('Lock_Stall_Time', 0):,} ps)")
        print(f"Speedup vs Baseline: {collector.calculate_speedup(results):.2f}x")
        
        # Record user comment if provided
        if args.comment:
            config_history = []
            config_file = os.path.join(args.output, "aie_config_history.json")
            with open(config_file, 'r') as f:
                try:
                    config_history = json.load(f)
                except json.JSONDecodeError:
                    config_history = []
            
            # Add comment to the last entry (current run)
            if config_history:
                config_history[-1]["comment"] = args.comment
                with open(config_file, 'w') as f:
                    json.dump(config_history, f, indent=2)
                print(f"Added comment: '{args.comment}'")
    
    if args.action in ["charts", "all"]:
        print("\nGenerating performance charts...")
        collector.generate_charts()
    
    if args.action in ["report", "all"]:
        print("\nGenerating summary report...")
        collector.generate_summary_report()
        print(f"Report saved to {os.path.join(args.output, 'aie_summary_report.md')}")
    
    if args.action == "all":
        print("\nAll tasks completed. Use '--list' to see all recorded runs.")

if __name__ == "__main__":
    main()

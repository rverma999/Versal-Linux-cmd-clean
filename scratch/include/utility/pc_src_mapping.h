// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689

#include<string>
#include<map>
#include<list>
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include <algorithm>

using namespace std;


class PcSrcInfo {
private:
    string work_dir;
    map<string, int> activeCores; 
    map<string, std::map<unsigned long long , std::vector< std::pair<std::string, unsigned long long>>>> pc_src_mapping;
    map<string, std::map<string ,multimap< unsigned long long , unsigned long long>>> rev_pc_src_mapping;
    map<std::string, std::vector<std::tuple<unsigned long long, unsigned long long, std::string>>> funtion_src_mapping;
public:
    PcSrcInfo(string dir): work_dir(dir)
    {
	setActiveCores(work_dir);
	setPcSrcMapping(work_dir);	
	setRevPcSrcMapping(work_dir);
    }
    void setActiveCores(const string &work_dir);
    void setPcSrcMapping(const string &work_dir);
    void setRevPcSrcMapping(const string &work_dir);
    std::vector<unsigned long long>getPCfromSrc(std::string coreID, std::string filename, unsigned long long line_num);
    std::vector<std::pair<std::string, unsigned long long>> getSrcfromPC(std::string core_ID, unsigned long long pc_val);
    void setFuncSrcMapping(const string &src_info_file);
    std::vector< std::string > getFunctionFromPC(unsigned long long pc_val);

    map<string, int>& getActiveCores(void) {
         //cout << "ObjectInfo::getActivevCores entered: " << &(activeCores) <<endl;
         return activeCores;
    }
};

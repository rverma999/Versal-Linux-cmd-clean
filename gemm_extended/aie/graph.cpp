
#include <adf.h>
#include "kernels.h"
#include "graph.h"

using namespace adf;

simpleGraph mygraph;

int main(void) {
  mygraph.init();
  mygraph.run(2);
  mygraph.end();
  return 0;
}

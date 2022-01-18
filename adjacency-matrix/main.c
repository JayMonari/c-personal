#include "adj_mat.h"

int main() {
  graph *g1 = create_graph(5);
  print_graph(g1);
  destroy_graph(g1);
}

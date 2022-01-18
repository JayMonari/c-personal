#include "adj_mat.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct mygraph {
  int numnodes;
  bool **edges;
};

graph *create_graph(int numnodes) {
  graph *g = malloc(sizeof(*g));
  if (g == NULL) {
    return NULL;
  }
  g->numnodes = numnodes;

  g->edges = calloc(sizeof(bool *), g->numnodes);
  if (g->edges == NULL) {
    free(g);
    return NULL;
  }

  for (int i = 0; i < g->numnodes; i++) {
    g->edges[i] = calloc(sizeof(bool), g->numnodes);
    if (g->edges[i] == NULL) {
      destroy_graph(g);
      return NULL;
    }
  }
  return g;
}

void destroy_graph(graph *g) {
  if (g->edges == NULL) {
    free(g);
    return;
  }

  for (int i = 0; i < g->numnodes; i++) {
    if (g->edges[i] != NULL) {
      free(g->edges[i]);
    }
  }
  free(g->edges);
  free(g);
}

void print_graph(graph *g) {
  printf("digraph {\n");

  for (int from = 0; from < g->numnodes; from++) {
    for (int to = 0; to < g->numnodes; to++) {
      if (g->edges[from][to]) {
        printf("%d -> %d;\n", from, to);
      }
    }
  }
  printf("}\n");
}

bool add_edge(graph *g, unsigned int from_node, unsigned int to_node) {
  return false;
}

bool has_edge(graph *g, unsigned int from_node, unsigned int to_node) {
  return false;
}

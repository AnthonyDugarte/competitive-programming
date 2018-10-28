## Depth-first search (DFS)

it is a recursively search where you start at the root node of a graph,
and then call DFS(child) to each children of root node,
be careful, if graph is cyclic, you could enter to an infinite loop,
to avoid this you could have a kind of memory where you can to save the visited
nodes, if a node is already visited, you got a back edge.
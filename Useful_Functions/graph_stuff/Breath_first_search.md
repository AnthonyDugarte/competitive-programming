## Breath-first search (BFS)

It is a search by levels, you first check the root
then, in a priority queue, you add all its childrens, 
then you visit each of those children and 
create a new-lvl priority queue where you add all the grand-children
of your root, and so on...

if the graph if connected, then you just have to take vector of bools and there you
are going to be saving if a node was already visited, if it was, you don't add it
again on your priority queue, this way cycles are obtained.
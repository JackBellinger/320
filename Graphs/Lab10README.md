Cosc 320 Lab 10: Graph + Breadth First Search
Jackson Bellinger 12/4/2018

In this lab, we implemented the DFS algorithm in our graph class. We also used DFS to compute if the graph has cycles,
compute a tolopological sort on the graph, and compute the fully connected components of the graph.
I put the main code for cycle detection, topological sort, and detecting fully connected components into the DFS algorithm.
This may not have been the best approach, as when I was changing something for fully connected components, it caused the start element
not shwo up in the topological sort.
I used my standard manual testing menu to intereact with a graph.

          Best    Worst
addVertex    O(1) O(1) //I'm assuming map's insert is O(1)
addEdge    O(1) O(vector resizing)
BFS    O( |V| + |E| ) O( |V| + |E| )
DFS    O( |V| + |E| ) I think the way I did it the worst case is n^2
I would like to add some timing functions to test the searches. I tried to make the main loop take some inputs from a text file
so that I could automatically load test cases, but didn't get it working for this submission. I would like to figure out how to do that though.


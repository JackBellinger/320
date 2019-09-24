Cosc 320 Lab 9: Graph + Breadth First Search
Jackson Bellinger 11/20/2018

In this lab, we implemented a graph and the Bfs algorithm.
My graph class and bfs algo were written as per the project guidelines, using a map to store the vertexes and their the neighbors, and 
vectors for the colors, distances to, and parents of the vertexes. I also added a numElements varaible to make initailizing the parellel 
vectors easier. I also made the return types of addVertex and addEdge be bools to check if the vertex / edge was added correctly, but I 
didn't use that in the logic.
I used my standard manual testing menu to intereact with a graph.

          Best    Worst
addVertex    O(1) O(1) //I'm assuming map's insert is O(1)
addEdge    O(1) O(vector resizing)
Bfs    O( |V| + |E| ) O( |V| + |E| )

I would like to add some timing functions to test the bfs, and any future graph algorithms. Also I would like to either make this graph 
class templated, or make it store a graphable base class, so that I can use it for other applications. I think having some test cases for 
the graph would be good, as right now you have to test the operations manually.

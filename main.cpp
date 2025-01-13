#include "properties.h"
#include "Graph.h"
#include "BFS.h"
#include "Ford_Fulkerson.h"


/*
In order to carry out the project, you are required to exercise the department, among other things
A simple directed graph:
Basic operations:
MakeEmptyGraph(n) – creating an empty graph from arcs with n vertices.
GetAdjList(u) – returning a linked list of the neighbors of vertex u) in raise order.
AddEdge(c,v,u) – adding an arc (v,u (with capacity c). Additional fields are allowed)
RemoveEdge(u,v) – removing an arc (v,u).

A graph will contain arcs, where an arc will have a capacitance.
In addition, you can add additional fields (such as the flow in the request) and of course you can add
A class of an arch that has additional fields (eg parent if it is part of a path/
A tree of MCBs, or a pointer to its position in the graph and/or in the residual graph for the purpose of efficiency).
*/








//"""Ford-Felkerson algorithm:
//Input: graph G, arc capacities, source vertex and destination vertex
//* The graph will be built in neighborhood lists and each arc will hold a capacitance field and a current flow field.
//Output: flow f whose value is maximal in G
//Algorithm description:
//We will initialize flow 0 in all the arcs and build the residual graph which at the beginning is exactly like the original graph plus residual capacity 0 on each arc that is opposite to the original arcs and if there are already anti-parallel arcs between 2 vertices we will not add. As long as there are routes from s to t in the residual graph:
//We found with the help of BFS a route from s to t in the residual graph, then we calculated the residual capacity along the route and increased the flow in the original graph along the same route when for each arc in the route we added to the current flow in it the residual capacity we found and then we updated the flow in the opposite arc to be the flow we found Request above double (-1).
//Finally we will update the residual graph along the same route for each arc:
//Cnew(u,v)= C(u,v)- f(u,v)
//If there are no more routes we will return the flow value f.
//"""

//We will want in each iteration to find an improving path in the graph from our source to the target vertex.
//The search will be done using a BFS width search implemented by a queue.
//For each vertex we will initialize its delta to infinity and its parent to nan
//We will update the delta of our source vertex to 0 and put it in the queue
//As long as the queue is not empty - we will remove a vertex from the queue and for each of its neighbors if its delta is infinity we will update that it is now the delta of the vertex we removed plus 1 and the vertex we removed is its father. Then we will insert the same vertex that we updated into the queue. Finally, we will return the short route that we found as a list by traversing the vertices' parents from the target to the source vertex.


//Input: graph G, arc capacities, source vertex and destination vertex
//* The graph will be built in neighborhood lists and each arc will hold a capacitance field and a current flow field.
//Output: flow f whose value is maximal in G
//Algorithm description:
//We will initialize flow 0 in all the arcs and build the residual graph which at the beginning is exactly like the original graph plus residual capacity 0 on each arc that is opposite to the original arcs and if there are already anti-parallel arcs between 2 vertices we will not add. As long as there are routes from s to t in the residual graph:
//We found with the help of BFS a route from s to t in the residual graph, then we calculated the residual capacity along the route and increased the flow in the original graph along the same route when for each arc in the route we added to the current flow in it the residual capacity we found and then we updated the flow in the opposite arc to be the flow we found Request above double (-1).
//Finally we will update the residual graph along the same route for each arc:
//Cnew(u,v)= C(u,v)- f(u,v)
//If there are no more routes we will return the flow value f.




//test:
int main() {
   // Edge::_currentid = 0;

    Graph* graph = new Graph(6);

    graph->addEdge(0, 1, 5);
    graph->addEdge(0, 2, 4);
    graph->addEdge(1, 2, 3);
    graph->addEdge(1, 3, 2);
    graph->addEdge(2, 3, 1);
    graph->addEdge(2, 4, 0);
    graph->addEdge(3, 4, 5);
    graph->addEdge(3, 5, 4);
  /*  graph->addEdge(4, 5, 10);
    graph->addEdge(5, 0, 10);
    graph->addEdge(5, 1, 10);
    graph->addEdge(5, 2, 10);
    graph->addEdge(5, 3, 10);*/

    Ford_Fulkerson* ford_fulkerson = new Ford_Fulkerson(graph, 0, 5);
    int flow = ford_fulkerson->Ford_Fulkerson_Algorithm();
    cout << "flow: " << flow << endl;
    return 0;
}

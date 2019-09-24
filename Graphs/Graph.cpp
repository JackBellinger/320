#include "Graph.h"

	template <class T>
Graph<T>::Graph(bool isDir)
	:isDirectd(isDir)//not a typo, const var is misspelled so the getter function has the right spelling
{

}
	template <class T>
bool Graph<T>::addVertex(int v)
{
	if(v != numElements +1)
		cout << "add vertecies in order" << endl;
	else
	{
		//try to insert a vector of ints at 
		pair<map<int, vector<int>>::iterator, bool> ret;
		ret = verticies.insert(pair<int, vector<int>>(v, vector<int>()));

		if(ret.second == false)
			cout << v << " already in graph" << endl;
		else
			numElements++;

		return ret.second;
	}
}

	template <class T>
bool Graph<T>::addEdge(int from, int to)
{
	//find the two vertecies in the graph
	map<int, vector<int>>::iterator fromIter = verticies.find(from);
	map<int, vector<int>>::iterator toIter = verticies.find(to);

	if(fromIter != verticies.end() && toIter != verticies.end())//if the 2 vertexes are in the graph
	{
		//make sure the edge vectors are big enough
		if(to > verticies[from].max_size())
			verticies[from].resize(to);
		if(isDirectd)
			transpose[to].resize(from);
		else if(from > verticies[to].max_size())
			verticies[to].resize(from);

		//add the nodes to each other's edge list
		verticies[from].push_back(to);
		if(isDirectd)//if it's directed, add the reverse edge to the transpose
			transpose[to].push_back(from);
		else//if it's undirected, add the symmetrical edge
			verticies[to].push_back(from);

		return true;
	}
	return false;//if the node wasn't added
}

	template <class T>
vector<int> Graph<T>::printBfs(int start)
{
	vector<T> discovered;
	map<int, vector<int>>::iterator sIt = verticies.find(start);
	if(sIt != verticies.end())
	{
		cout << "#" << numElements << endl;
		color = vector<color_t>(numElements + 1, WHITE);//verticies.size(), WHITE);
		distance = vector<int>(numElements + 1, -1);//verticies.size(), -1);
		parent = vector<int>(numElements + 1, -1);//verticies.size(), -1);
		queue<int> neighbors = queue<int>();

		color[start] = GRAY;

		distance[start] = 0;
		neighbors.push(start);
		cout << "colors# " << color.size() << endl;
		while(!neighbors.empty())
		{
			int u = neighbors.front();
			neighbors.pop();
			cout << "deque" << u << " dist " << distance[u] << endl;

			for(int v : verticies[u])
			{
				cout << "v: " << v << endl;
				if(color[v] == WHITE)
				{
					color[v] = GRAY;
					distance[v] = distance[u] + 1;
					parent[v] = u;
					neighbors.push(v);
				}
			}
			color[u] = BLACK;
		}

		for(int i = 0; i < distance.size(); i++)
		{
			if(distance[i] != -1)
				cout <<  "Distance to " << i << " is " << distance[i] << endl;
		}
	}else
		cout << "start isn't in the graph" << endl;
	return discovered;
}

	template <class T>
vector<int> Graph<T>::Dfs(int start)
{
	return Dfs(start, verticies);
}
	template <class T>
vector<int> Graph<T>::Dfs(int start, map<int, vector<int>> adj)
{
	vector<int> topoSort;
	map<int, vector<int>>::iterator sIt = adj.begin();

	cout << "#" << numElements << endl;
	color = vector<color_t>(numElements + 1, WHITE);//adj.size(), WHITE);
	distance = vector<int>(numElements + 1, -1);//adj.size(), -1);
	parent = vector<int>(numElements + 1, -1);//adj.size(), -1);
	stack<int> neighbors = stack<int>();
	numCycles = 0;
	int time = 0;
	int current = start;
	while(sIt != adj.end())
	{
		if(color[sIt->first] != BLACK)//if the vertex was already discovered
		{
			current = sIt->first;
			int u = current;

			if(color[parent[u]] == WHITE)//there is a new subgraph 
			{
				cout << "new sub-graph " << sIt->first;
				vector<vector<int>>::iterator subGraphsIter = subGraphs.begin();
				subGraphs.insert(subGraphsIter, topoSort);
				topoSort.clear();
			}
		//	else//add node to current subgraph

				if(color[current] == WHITE)
				{
					color[current] = GRAY;
					if(distance[current])
						distance[current] = 0;
					neighbors.push(current);
				}
			int numNeighbors = adj[u].size();

			while(!neighbors.empty())
			{
				u = neighbors.top();
				neighbors.pop();
				cout << "stack pop " << u << " dist " << distance[u] << " at time " << time++ << endl;
				//cout << "color of # " << u << " is " << color[u] << endl;
				for(int v : adj[u])
				{
					cout << "neighbor: " << v << endl;

					if(color[v] == WHITE)
					{
						//cout << "white" << endl;
						color[v] = GRAY;
						distance[v] = distance[u] + 1;
						parent[v] = u;
						neighbors.push(v);
					}
					else if(color[v] == GRAY)
					{//there's a cycle
						cout << " There's a cycle" << endl;
						numCycles++;
					}
				}
			}
			cout << "time: " << time << " finished " << u << endl;
			if(color[u] != BLACK)
			{
				color[u] = BLACK;
				topoSort.insert(topoSort.begin(), u);
			}
		}	sIt++;
	}//end while
	for(int i = 0; i < distance.size(); i++)
	{
		if(distance[i] != -1)
			cout <<  "Distance to " << i << " is " << distance[i] << endl;
	}
	return topoSort;
}

	template <class T>
vector<int> Graph<T>::topoSort()
{
	vector<int> output;
	map<int, vector<int>>::iterator it = verticies.begin();
	if(isDAG() || numCycles < 0)//if cycles isn't computed it will still try dfs
	{
		output = Dfs(it->first);
	}else //it's not directed or has a cycle
	{
		cout << "The graph is not a DAG." << endl;
	}
	for(int i : output)
		cout << i << " ";
	cout << endl;
	return output;
}
	template <class T>
vector<vector<int>> Graph<T>::connectedComps()
{
	if(!isDAG() || numCycles < 0) //numcycles is -1 if it hasn't been computed
	{
		if(isDirected())
			Dfs(0);
	}
	vector<int> output = Dfs(1, transpose);

	return subGraphs;//calculated in DFS
}

	template <class T>
vector<int> Graph<T>::getTranspose()
{
	vector<int> t;
	vector<int>::reverse_iterator rit = parent.rbegin();
	for(; rit != parent.rend(); ++rit )
		t.push_back(*rit);
	return t;
}

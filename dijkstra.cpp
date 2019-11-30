// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include "bits/stdc++.h"
#include "fiboheap/fiboqueue.h"

#define INF 0x3f3f3f3f
#define DEBUG 0
#define CUSTOM_INPUT 1
#define multipleRuns 0

using namespace std;

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

struct triplet
{
	int x, y, z;
};

// This class represents a directed graph using
// adjacency list representation
class Graph
{
private:
	int V; // No. of vertices

	// In a weighted graph, we need to store vertex
	// and weight pair for every edge
	list<pair<int, int>> *adj;

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, int w);

	// prints shortest path from s
	void shortestPathPriorityQ(int s);
	void shortestPathFibHeap(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::shortestPathPriorityQ(int src)
{
	// Create a priority queue to store vertices that
	// are being preprocessed. This is weird syntax in C++.
	// Refer below link for details of this syntax
	// https://www.geeksforgeeks.org/implement-min-heap-using-stl/
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

	// Create a vector for distances and initialize all
	// distances as infinite (INF)
	vector<int> dist(V, INF);

	// Insert source itself in priority queue and initialize
	// its distance as 0.
	pq.push(make_pair(0, src));
	dist[src] = 0;

	/* Looping till priority queue becomes empty (or all 
	distances are not finalized) */
	while (!pq.empty())
	{
		// The first vertex in pair is the minimum distance
		// vertex, extract it from priority queue.
		// vertex label is stored in second of pair (it
		// has to be done this way to keep the vertices
		// sorted distance (distance must be first item
		// in pair)
		int u = pq.top().second;
		pq.pop();

		// 'i' is used to get all adjacent vertices of a vertex
		list<pair<int, int>>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			// Get vertex label and weight of current adjacent
			// of u.
			int v = (*i).first;
			int weight = (*i).second;

			// If there is shorted path to v through u.
			if (dist[v] > dist[u] + weight)
			{
				// Updating distance of v
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

#if DEBUG
	// Print shortest distances stored in dist[]
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
#endif
}

void Graph::shortestPathFibHeap(int src)
{
	// Create a priority queue to store vertices that
	// are being preprocessed. This is weird syntax in C++.
	// Refer below link for details of this syntax
	// https://www.geeksforgeeks.org/implement-min-heap-using-stl/
	// priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
	FibHeap<iPair, greater<iPair>> pq;

	// Create a vector for distances and initialize all
	// distances as infinite (INF)
	vector<int> dist(V, INF);

	// Insert source itself in priority queue and initialize
	// its distance as 0.
	pq.push(make_pair(0, src));
	dist[src] = 0;

	/* Looping till priority queue becomes empty (or all 
	distances are not finalized) */
	while (!pq.empty())
	{
		// The first vertex in pair is the minimum distance
		// vertex, extract it from priority queue.
		// vertex label is stored in second of pair (it
		// has to be done this way to keep the vertices
		// sorted distance (distance must be first item
		// in pair)
		int u = pq.top().second;
		pq.pop();

		// 'i' is used to get all adjacent vertices of a vertex
		list<pair<int, int>>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			// Get vertex label and weight of current adjacent
			// of u.
			int v = (*i).first;
			int weight = (*i).second;

			// If there is shorted path to v through u.
			if (dist[v] > dist[u] + weight)
			{
				// Updating distance of v
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

#if DEBUG
	// Print shortest distances stored in dist[]
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
#endif
}

// Driver program to test methods of graph class
int main()
{
	// create the graph given in above fugure
	int V, E;
	Graph g(V);

	cout << "Adding edges to Graph...\n";

#if CUSTOM_INPUT
	cin >> V >> E;
	triplet a;
	for (int i = 0; i < E; i++)
	{
		cin >> a.x >> a.y >> a.z;
		g.addEdge(a.x, a.y, a.z);
	}
#endif

#if !CUSTOM_INPUT
	// making above shown graph
	g.addEdge(0, 1, 2);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 11, 1);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 6, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(4, 1, 6);
	g.addEdge(9, 11, 12);
	g.addEdge(7, 3, 11);
	g.addEdge(6, 9, 2);
	g.addEdge(4, 8, 1);
	g.addEdge(8, 10, 9);
	g.addEdge(5, 7, 3);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);
#endif

	clock_t start, end;
	double time_taken;

	cout << "Running tests...\n";

#if multipleRuns
	for (int i = 0; i < 5; ++i)
#endif
	{
		start = clock();
		g.shortestPathPriorityQ(0);
		end = clock();
		time_taken = double(end - start) / double(CLOCKS_PER_SEC);
		cout << "STL PriorityQ: " << fixed << time_taken << setprecision(5) << endl;

		start = clock();
		g.shortestPathFibHeap(0);
		end = clock();
		time_taken = double(end - start) / double(CLOCKS_PER_SEC);
		cout << "Fib Heap: " << fixed << time_taken << setprecision(5) << endl;

		cout << endl;
	}

	return 0;
}

#include "dijkstra.hpp"

#define CUSTOM_INPUT 0
#define multipleRuns 0
int main()
{
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
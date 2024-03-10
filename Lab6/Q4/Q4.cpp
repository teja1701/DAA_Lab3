#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
private:
	int V; // number of vertices
	vector<vector<int> > adj; // adjacency list

public:
	Graph(int V)
	{
		this->V = V;
		adj.resize(V);
	}

	void addEdge(int v, int w) { adj[v].push_back(w); }

	bool isCyclic()
	{
		vector<int> inDegree(
			V, 0); // stores in-degree of each vertex
		queue<int>
			q; // queue to store vertices with 0 in-degree
		int visited = 0; // count of visited vertices

		// calculate in-degree of each vertex
		for (int u = 0; u < V; u++) {
			for (auto v : adj[u]) {
				inDegree[v]++;
			}
		}

		// enqueue vertices with 0 in-degree
		for (int u = 0; u < V; u++) {
			if (inDegree[u] == 0) {
				q.push(u);
			}
		}

		// BFS traversal
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			visited++;

			// reduce in-degree of adjacent vertices
			for (auto v : adj[u]) {
				inDegree[v]--;
				// if in-degree becomes 0, enqueue the
				// vertex
				if (inDegree[v] == 0) {
					q.push(v);
				}
			}
		}

		return visited != V; // if not all vertices are
							// visited, there is a cycle
	}
};

int main()
{
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(4, 1);
	g.addEdge(4, 5);
	g.addEdge(5, 3);

	if (g.isCyclic()) {
		cout << "Graph contains cycle." << endl;
	}
	else {
		cout << "Graph does not contain cycle." << endl;
	}

	return 0;
}

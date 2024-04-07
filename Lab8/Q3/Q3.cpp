#include <bits/stdc++.h>
using namespace std;

// Used to implement union-find algorithm
int parent[100005];

// To keep track of edges in MST
vector<int> present;

// To keep track of number of edges
// in spanning trees other than the MST
int edg;

// A structure to represent a weighted edge in graph
struct edge {
    int src, dest, weight;
} edges[100005];

// Compare two edges according
// to their weights.
// Used in sort() for sorting
// an array of edges
bool cmp(edge x, edge y) {
    return x.weight < y.weight;
}

// Initialising the array -
// each vertex is its own parent
// initially
void initialise(int n) {
    // 1-indexed
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

// Implementing the union-find algorithm
int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

// Function to find the union
// for the Minimum spanning Tree
int union1(int i, int sum) {
    int x, y;
    x = find(edges[i].src);
    y = find(edges[i].dest);
    if (x != y) {
        // parent of x = y (LCA) -
        // both are edge connected
        parent[x] = y;

        // keeping track of edges in MST
        present.push_back(i);

        // finding sum of weights
        // of edges in MST
        sum += edges[i].weight;
    }
    return sum;
}

// Function to find the second
// best minimum spanning Tree
int union2(int i, int sum) {
    int x, y;
    x = find(edges[i].src);
    y = find(edges[i].dest);
    if (x != y) {
        // parent of x = y (LCA) -
        // both are edge connected
        parent[x] = y;

        // sum of weights of edges
        // in spanning tree
        sum += edges[i].weight;
        edg++;
    }
    return sum;
}

// Driver Code
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // V-> Number of vertices,
    // E-> Number of edges
    int V, E;
    cin >> V >> E;

    // Initialising the array to
    // be used for union-find
    initialise(V);

    // Inputting edge details
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    // Sorting the array of edges
    // based on edge weights
    sort(edges, edges + E, cmp);

    int sum = 0;
    for (int i = 0; i < E; i++) {
        sum = union1(i, sum);
    }

    // Printing the cost of MST
    cout << "MST: " << sum << "\n";

    // Initialising cost of second best MST
    int sec_best_mst = INT_MAX;

    // Setting the sum to zero again.
    sum = 0;
    int j;
    for (j = 0; j < present.size(); j++) {
        initialise(V);
        edg = 0;
        for (int i = 0; i < E; i++) {
            // Excluding one edge of
            // MST at a time
            // and forming spanning tree
            // with remaining
            // edges
            if (i == present[j])
                continue;
            sum = union2(i, sum);
        }
        // Checking if number of edges = V-1 or not
        // since number of edges in a spanning tree of
        // graph with V vertices is (V-1)
        if (edg != V - 1) {
            sum = 0;
            continue;
        }

        // Storing the minimum sum
        // in sec_best_mst
        if (sec_best_mst > sum)
            sec_best_mst = sum;
        sum = 0;
    }

    // Printing the cost of second best MST
    cout << "Second Best MST: "
         << sec_best_mst << "\n";
    return 0;
}
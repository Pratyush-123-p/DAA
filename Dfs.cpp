#include <bits/stdc++.h>
using namespace std;

// Function to add an edge to the graph
void addEdge(vector<list<int>>& adj, int v, int w) {
    adj[v].push_back(w);
}

// Function to perform DFS traversal
void DFS(vector<list<int>>& adj, int V, int s) {
    vector<bool> visited(V, false);
    stack<int> stack;

    stack.push(s);

    while (!stack.empty()) {
        int s = stack.top();
        stack.pop();

        if (!visited[s]) {
            cout << s << " ";
            visited[s] = true;
        }

        for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                stack.push(*i);
            }
        }
    }
}

int main() {
    int V = 5;
    vector<list<int>> adj(V);

    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 5);

    cout << "Following is Depth First Traversal\n";
    DFS(adj, V, 0);

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfsTraversal(int start, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &res)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        res.push_back(node);

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

vector<int> bfsDisconected(vector<vector<int>> &adj, int startNode)
{
    int v = adj.size(); // v is the number of vertex
    vector<int> res;
    vector<bool> visited(v, false);

    if (!visited[startNode])
    {
        bfsTraversal(startNode, adj, visited, res);
    }

    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[i])
        {
            bfsTraversal(i, adj, visited, res);
        }
    }
    return res;
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    vector<vector<int>> adj(n);

     cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;
    vector<int> result = bfsDisconected(adj, startNode);
    for (int node : result)
    {
        cout << node << " ";
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Edge
{
    int u, v, cost;
};

bool compare(Edge a, Edge b)
{
    return a.cost < b.cost;
}

int parent[100];

int findParent(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]);
}

void unionSet(int u, int v)
{
    int a = findParent(u);
    int b = findParent(v);

    parent[a] = b;
}

int main()
{
    int n, m;
    string building[100];
    vector<Edge> edges;

    cout << "COLLEGE CABLE NETWORK\n";
    cout << "Using Kruskal's Algorithm\n\n";

    cout << "Enter number of buildings: ";
    cin >> n;

    if (n < 1 || n > 100)
    {
        cout << "Invalid number of buildings!\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name of building " << i + 1 << ": ";
        cin >> building[i];
        parent[i] = i;
    }

    cout << "\nEnter number of possible cable connections: ";
    cin >> m;

    if (m < 0 || m > 4950)
    {
        cout << "Invalid number of connections!\n";
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        Edge e;

        cout << "\nConnection " << i + 1 << ":\n";
        cout << "Enter two building numbers and cost: ";
        cin >> e.u >> e.v >> e.cost;

        if (e.u < 1 || e.u > n ||
            e.v < 1 || e.v > n ||
            e.u == e.v || e.cost < 0)
        {
            cout << "Invalid connection! Try again.\n";
            i--;
            continue;
        }

        e.u--;
        e.v--;
        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), compare);

    int totalCost = 0;
    int selected = 0;

    cout << "\nMINIMUM COST CABLE NETWORK\n";

    for (int i = 0; i < (int)edges.size(); i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (findParent(u) != findParent(v))
        {
            unionSet(u, v);

            cout << building[u] << " - "
                 << building[v] << " : Rs. "
                 << edges[i].cost << "\n";

            totalCost += edges[i].cost;
            selected++;
        }

        if (selected == n - 1)
            break;
    }

    if (selected == n - 1)
    {
        cout << "\nMinimum installation cost = Rs. "
             << totalCost << "\n";
    }
    else
    {
        cout << "\nAll buildings cannot be connected.\n";
        cout << "The network is disconnected.\n";
    }

    return 0;
}

#include <iostream>
#include <string>
#include <queue>
#include <list>

using namespace std;

class Graph
{
private:
    list<int>* adj;
    int maxV;
    int vCount;
    bool* visited;

    void dfsUtil(int v)
    {
        visited[v] = true;
        cout << v << " ";

        for (int nbr : adj[v])
        {
            if (!visited[nbr])
            {
                dfsUtil(nbr);
            }
        }
    }

public:
    Graph(int m, int c)
    {
        vCount = c;
        maxV = m;
        visited = new bool[maxV];
        adj = new list<int>[maxV];
    }

    Graph(const Graph& g)
    {
        vCount = g.vCount;
        maxV = g.maxV;
        visited = new bool[maxV];
        adj = new list<int>[maxV];

        for (int i = 0; i < vCount; i++)
        {
            adj[i] = g.adj[i];
            visited[i] = g.visited[i];
        }

        for (int i = vCount; i < maxV; i++)
        {
            visited[i] = false;
        }
    }

    ~Graph()
    {
        delete[] adj;
        delete[] visited;
    }

    bool addVertex(int& v)
    {
        if (vCount >= maxV)
        {
            v = -1;
            return false;
        }
        v = vCount;
        vCount++;
        return true;
    }

    bool addEdge(int u, int v)
    {
        if (u < 0 || u >= vCount || v < 0 || v >= vCount)
            return false;

        adj[u].push_back(v);
        adj[v].push_back(u);
        return true;
    }

    bool removeEdge(int u, int v)
    {
        if (u < 0 || u >= vCount || v < 0 || v >= vCount)
            return false;

        adj[u].remove(v);
        adj[v].remove(u);
        return true;
    }

    bool isEmpty()
    {
        for (int i = 0; i < vCount; i++)
        {
            if (!adj[i].empty())
                return false;
        }
        return true;
    }

    bool isComplete()
    {
        for (int i = 0; i < vCount; i++)
        {
            if (adj[i].empty())
                return false;
        }
        return true;
    }

    void clear()
    {
        for (int i = 0; i < vCount; i++)
        {
            adj[i].clear();
        }
    }

    void display()
    {
        for (int i = 0; i < vCount; i++)
        {
            cout << i << ": ";
            for (int nbr : adj[i])
                cout << nbr << " ";
            cout << endl;
        }
    }

    int degree(int v)
    {
        if (v < 0 || v >= vCount)
            return -1;

        return adj[v].size();
    }

    void DFS()
    {
        for (int i = 0; i < vCount; i++)
            visited[i] = false;

        int start;
        cout << "Enter starting vertex for DFS traversal (0-" << vCount - 1 << "): ";
        cin >> start;

        if (start < 0 || start >= vCount)
        {
            cout << "Invalid vertex! Starting from vertex 0." << endl;
            start = 0;
        }

        dfsUtil(start);

        for (int i = 0; i < vCount; i++)
        {
            if (!visited[i])
                dfsUtil(i);
        }
        cout << endl;
    }

    void bfsUtil(int s)
    {
        queue<int> q;
        visited[s] = true;
        q.push(s);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int nbr : adj[curr])
            {
                if (!visited[nbr])
                {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }

    void BFS()
    {
        for (int i = 0; i < vCount; i++)
            visited[i] = false;

        int start;
        cout << "Enter starting vertex for BFS traversal (0-" << vCount - 1 << "): ";
        cin >> start;

        if (start < 0 || start >= vCount)
        {
            cout << "Invalid vertex! Starting from vertex 0." << endl;
            start = 0;
        }

        cout << "BFS Traversal: ";
        bfsUtil(start);

        for (int i = 0; i < vCount; i++)
        {
            if (!visited[i])
                bfsUtil(i);
        }
        cout << endl;
    }
};

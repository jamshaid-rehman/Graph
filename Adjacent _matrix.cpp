#include <iostream>
#include <string>
#include <Queue>

using namespace std;

class Graph
{
private:
    int **adjMatrix;
    int maxVertices;
    int n;
    bool *visited;
    void DFS(int v)
    {
        visited[v] = true;
        cout << v << " ";
        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[v][i] != 0 && visited[i] == 0)
            {
                DFS(i);
            }
        }
    }

public:
    Graph(int maxV, int currV)
    {
        n = currV;
        maxVertices = maxV;
        visited = new bool[maxVertices];
        adjMatrix = new int *[maxVertices];
        for (int i = 0; i < maxVertices; i++)
        {
            adjMatrix[i] = new int[maxVertices];
        }
    }
    Graph(const Graph &other)
    {
        n = other.n;
        maxVertices = other.maxVertices;
        visited = new bool[maxVertices];
        adjMatrix = new int *[maxVertices];
        for (int i = 0; i < maxVertices; i++)
        {
            adjMatrix[i] = new int[maxVertices];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adjMatrix[i][j] = other.adjMatrix[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            visited[i] = other.visited[i];
        }
    }

    ~Graph()
    {
        for (int i = 0; i < maxVertices; i++)
        {
            delete[] adjMatrix[i];
            adjMatrix[i] = nullptr;
        }
    }
    bool addVertex(int &v)
    {
        if (n >= maxVertices)
        {
            v = -1;
            return false;
        }
        v = n;
        for (int i = 0; i < maxVertices; i++)
        {
            adjMatrix[n][i] = 0;
            adjMatrix[i][n] = 0;
        }
        n++;
        return true;
    }
    bool addEdge(int u, int v)
    {
        if (v < maxVertices && u < maxVertices)
        {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
            return true;
        }
        return false;
    }
    bool removeEdge(int u, int v) 
    {
        if (v < maxVertices && u < maxVertices)
        {
            adjMatrix[u][v] = 0;
            adjMatrix[v][u] = 0;
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (n == 0)
        {
            return true;
        }
        return false;
    }
    bool isComplete()
    {
        if (n >= maxVertices)
        {
            return true;
        }
        return true;
    }
    void clear()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }
    void display()
    {
        cout << "\nAdjacency Matrix\n\n";

        cout << "    ";
        for (int i = 0; i < n; i++)
            cout << i << "   ";
        cout << "\n";

        cout << "   ";
        for (int i = 0; i < n; i++)
            cout << "----";
        cout << "\n";

        for (int i = 0; i < n; i++)
        {
            cout << i << " | ";
            for (int j = 0; j < n; j++)
            {
                cout << adjMatrix[i][j] << "   ";
            }
            cout << "\n";
        }
    }

    int degree(int v)
    {
        if (v >= n)
        {
            return -1;
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[v][i] == 1)
            {
                count++;
            }
        }
        return count;
    }
    void DFS()
    {
        for (int i = 0; i < maxVertices; i++)
        {
            visited[i] = false;
        }
        int index;
        cout << "enter the number of vertex for DFS traversal.";
        cin >> index;
        DFS(index);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                DFS(i);
            }
        }
    }
    void BFShelper(int index)
    {
        queue<int> q;
        q.push(index);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int i = 0; i < n; i++)
            {
                if (adjMatrix[node][i] == 1 && visited[i] == 0)
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    void BFS()
    {
        for (int i = 0; i < maxVertices; i++)
        {
            visited[i] = false;
        }
        int index;
        cout << "enter the number of vertex for BFS traversal.";
        cin >> index;
        BFShelper(index);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                BFShelper(i);
            }
        }
    }
};
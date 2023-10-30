#include <iostream>
#include<vector>
#include<queue>
using namespace std;

///////////Graph Traversal  Algorithms

// Breadth-First Search (BFS) =>Level order

class Graph
{
    int v;
    vector<int>*adj;

public:
    Graph(int v) {
        this->v = v;
        adj = new vector<int>[v];
    }

    //repesent graph using adjacent list
    void add_edg(int x, int y) {

        //undirected graph
        adj[x].push_back(y); //directed graph 
        adj[y].push_back(x);
    }

    //********
    //search in graph using BFS
    void BFS(int s) {

        bool* visited = new bool[v];

        for (int i = 0; i < v; i++)
            visited[i] = false;

        queue<int>q;

        visited[s] = true;
        q.push(s);

        
        while (!q.empty()) {
            s = q.front();
            cout << s << " ";
            q.pop();

            for (int i = 0; i < v;i++) {
                for (auto x : adj[i]) {
                    if (!visited[x]) {
                        visited[x] = true;
                        q.push(x);
                    }
                }
            }
        }


    }

};
int main()
{
    Graph g(5);

    g.add_edg(0, 1);
    g.add_edg(0, 4);
    g.add_edg(1, 4);
    g.add_edg(1, 3);
    g.add_edg(2, 1);
    g.add_edg(3, 2);
    g.add_edg(4, 3);
    
    cout << "Visited Vertex: ";
    g.BFS(0);
    cout << endl;
       
    return 0;
}







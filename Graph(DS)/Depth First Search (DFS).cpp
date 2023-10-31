#include <iostream>
#include<vector>
#include<stack>

using namespace std;


/////////// Graph Traversal  Algorithms

// Depth-First Search (DFS) => Preorder


class Graph {

    int v;
    vector<int>* adj;
    bool* visited;

public:

    Graph(int v) {

        this->v = v;
        adj = new vector<int>[v];
       visited = new bool[v];
        
       for (int i = 0; i < v; i++)
            visited[i] = false;
    }


    //repesent graph using adjacent list
    void add_edg(int x, int y) {
        
        //Undirected graph
        adj[x].push_back(y);  //directed graph
        adj[y].push_back(x);
    }


    //********
   //search in graph using DFS

    /*
    //1-DFS using recursive  (back tracking)
    void dfs_r(int r) {

        visited[r] = true;
        cout << r << " ";

        for (int i = 0; i < v; i++) {
            for (auto x : adj[i]) {
                if (!visited[x])
                    dfs_r(x);
            }
        }
    }*/


    //************
    //2-DFS without recursive
    void dfs(int r) {

        stack<int>s;
        visited[r] = true;
        s.push(r);
        
        while (!s.empty()) {
            
            int z = s.top();
            cout << z << " ";
            s.pop();

            for (int i = 0; i < v; i++) {
                for (auto x : adj[i]) {
                    if (!visited[x]) {
                        visited[x] = true;
                        s.push(x);
                    }
                }
            }
        }
    }
};


int main()
{
    Graph g(4);

    g.add_edg(0, 1);
    g.add_edg(0, 2);
    g.add_edg(1, 2);
    g.add_edg(2, 3);
    g.add_edg(3, 3);
    

    //g.dfs_r(2);
    
    cout << "Visited Vertex : ";
    g.dfs(2);
    cout <<endl;
    
    return 0;
}


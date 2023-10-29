#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

//  Repersentation Graph In Memory

// Two Way To Repersentation Graph
// 1-Using adjacency Matrix
// 2-Using adjacency List

int adj_mat[100][100];


void add_edg(vector<int>adj[], int u, int v) {

    adj[u].push_back(v);    //directed graph
    adj[v].push_back(u);
}

void print_graph(vector<int>adj[], int s) {
   
    for (int i = 0; i < s; i++) {
        cout << i << " { ";
        for (auto x : adj[i]) 
            cout << x << " ";
        cout << "}" << endl;
    }
}

int main()
{

    //1- using adjacency Matrix
 
   /*
    int V,E;
    cin >> V>>E;
    adj_mat[V][V];

  for (int i = 1; i <= E; i++) {
        
      int x, y,w;     cin >> x >> y;  
      
      //cout << "weight=";  cin >> w;  weight=> value in it edges
    
      // adj_mat[x][y]=1   //directed graph
        
        adj_mat[x][y] = adj_mat[y][x] = 1;   //undirected graph
    }

    cout << " Matrix " << endl;
    
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {

            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
 
    */
    
    //******************************************
  
    //2- Using adjacency List
    
    const int v = 5;
    
    int e;  cin >> e;
    
    vector<int>adj[v];
    
    for (int i = 1; i <= e; i++) {

        int u, v;   cin >> u >> v;
        add_edg(adj, u, v);
    }

    /*
    add_edg(adj, 0, 1);      
    add_edg(adj, 0, 4);
    add_edg(adj, 1, 2);
    add_edg(adj, 1, 3);
    add_edg(adj, 1, 4);
    add_edg(adj, 2, 3);
    add_edg(adj, 3, 4); 
    */

    cout << " Adjacency list" << endl;
    print_graph(adj, v);
    
    return 0;
}


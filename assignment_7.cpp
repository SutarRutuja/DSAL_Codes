/*You have a business with several offices; you want to lease phone lines to
connect them up with each other; and the phone company charges
different amounts of money to connect different pairs of cities. You want
a set of lines that connects all your offices with a minimum total cost.
Solve the problem by suggesting appropriate data structures.*/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
   //Function to find sum of weights of edges of the Minimum Spanning Tree.
   int spanningTree(int V, vector<vector<int>> adj[])
   {
       priority_queue<pair<int, int>,
                      vector<pair<int, int> >, greater<pair<int, int>>> pq;


       vector<int> vis(V, 0);
       // {wt, node}
       pq.push({0, 0});
       int sum = 0;
       while (!pq.empty()) {
           auto it = pq.top();
           pq.pop();
           int node = it.second;
           int wt = it.first;


           if (vis[node] == 1) continue;
           // add it to the mst
           vis[node] = 1;
           sum += wt;
           for (auto it : adj[node]) {
               int adjNode = it[0];
               int edW = it[1];
               if (!vis[adjNode]) {
                   pq.push({edW, adjNode});
               }
           }
       }
       return sum;
   }
};




int main() {
   // {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};


   int V ;
   int E;
     
   vector<vector<int>> edges;
   cout<<"Enter number of nodes of graph: "<<endl;
   cin>>V;
   cout<<"Enter number of edges of graph: "<<endl;
   cin>>E;


   for(int i=0;i<E;i++){
        int x,y,z;
        cout<<"Enter value of 2 nodes and weight sequentially ";
        cin>>x>>y>>z;


       vector<int>a;
       a.clear();


       a.push_back(x);
       a.push_back(y);
       a.push_back(z);
       edges.push_back(a);


   }

   vector<vector<int>> adj[V];
  

   // make adj list
   for (auto it : edges) {
       vector<int> tmp(2);
       tmp[0] = it[1];
       tmp[1] = it[2];
       adj[it[0]].push_back(tmp);


       tmp[0] = it[0];
       tmp[1] = it[2];
       adj[it[1]].push_back(tmp);
   }


   Solution obj;
   int sum = obj.spanningTree(V, adj);
   cout << "The sum of all the edge weights: " << sum << endl;


   return 0;
}



/*You have a business with several offices; you want to lease phone lines to
connect them up with each other; and the phone company charges
different amounts of money to connect different pairs of cities. You want
a set of lines that connects all your offices with a minimum total cost.
Solve the problem by suggesting appropriate data structures.*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //using prims algo
      int mst(int V,vector<vector<int>>adj[]){
          vector<bool>visited(V,0);
          int sum=0;
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
          pq.push({0,0});
          while(!pq.empty()){
               auto it=pq.top();
               pq.pop();
               int node=it.second;
               int wt=it.first;

               if(visited[node]==true) continue;

               visited[node]=true;
               sum+=wt;

               for(auto nbr: adj[node]){
                if(!visited[nbr[0]]){
                    pq.push({nbr[1],nbr[0]});
                    // visited[nbr[0]]=1;


                }
               }


          }

       return sum;

      }

    static  bool compare(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
      }

      int findparent(vector<int>&parent,int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findparent(parent,parent[node]);
      }

      void initialize1(vector<int>&parent,vector<int>&rank,int n){
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
      }
      void unionset(int x,int y,vector<int>&parent,vector<int>&rank){
        int u=findparent(parent,x);
        int v=findparent(parent,y);

        if(rank[u]<rank[v]){
            parent[u]=v;

        }
        else if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;

        }
      }
      //using kruskal's algorithm

      int mst2(vector<vector<int>>edges,int n){
          sort(edges.begin(),edges.end(),Solution::compare);
          vector<int>parent(n);
          vector<int>rank(n);
          initialize1(parent,rank,n);
          int result=0;

          for(int i=0;i<edges.size();i++){
                int u=findparent(parent,edges[i][0]);
                int v=findparent(parent,edges[i][1]);
                int wt=edges[i][2];

                if(u!=v){
                    result+=wt;
                    unionset(u,v,parent,rank);
                }



          }
          return result;


      }

};

int main(){

    Solution s1;
    cout<<"Enter vertices: ";
    int v;
    int e;
    cin>>v;
    cout<<"Enter edges: ";
    cin>>e;
    // {0, 1, 10}, {1, 3, 15}, {2, 3, 4}, {2, 0, 6}, {0, 3, 5}
   vector<vector<int>>edges;
   vector<vector<int>>adj[v];
   for(int i=0;i<e;i++){
    cout<<"Enter nodes and wt: ";
    int x,y,z;
    cin>>x>>y>>z;
    vector<int>a(3);
    a[0]=x;
    a[1]=y;
    a[2]=z;
    edges.push_back(a);
    vector<int>temp(2);
    temp[0]=y;
    temp[1]=z;
    adj[x].push_back(temp);
    temp[0]=x;
    temp[1]=z;
    adj[y].push_back(temp);

   }
   cout<<"sum: "<<s1.mst(v,adj)<<endl;
    cout<<"krusals: "<<s1.mst2(edges,v)<<endl;

    return 0;
}

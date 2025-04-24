/*Represent a given graph using adjacency list to perform DFS and BFS.
Use the map of the area around the college as the graph. Identify the
prominent land marks as nodes and perform DFS and BFS on that.*/

#include<bits/stdc++.h>


using namespace std;




class graph{
public:
int v;
unordered_map<int,list<int>>adj;
graph(int k){
   v=k;


}
void makelist(int u,int v)
{
adj[u].push_back(v);


adj[v].push_back(u);


}
void printadjlist(){
 for(auto i : adj){
       cout<<i.first<<" --> ";
 for(auto j: i.second){
   cout<<j<<" ";
 }
 cout<<endl;
 }
 cout<<endl;






}


void dfs(int src,unordered_map<int,bool>&visited){
cout<<src<<" ";
visited[src]=true;
for(auto nbr:adj[src]){
if(!visited[nbr]){
   dfs(nbr,visited);
}


}






}
//function for dfs
void dfsprint(int src){
   unordered_map<int,bool>visited;
   for(int i=0;i<v;i++){
       visited[i]=false;
   }
  
   dfs(src,visited);


  cout<<endl;


}
void bfs(int src){
   unordered_map<int,bool>visited;
   for(int i=0;i<v;i++){
       visited[i]=false;
   }


   queue<int>q;
   q.push(src);
   visited[src]=true;
   while(!q.empty()){
       int front=q.front();
       q.pop();
       cout<<front<<" ";


       for(int i: adj[front]){
           if(!visited[i]){
               q.push(i);
               visited[i]=true;
           }
       }


   }


cout<<endl;




}


};


int main(){


   cout<<"Enter the number of nodes in the undirected graph"<<endl;
   int k;
   cin>>k;
   graph g(k);
   cout<<"Enter how many edges graph have: ";
   int m;
   cin>>m;
   for(int i=0;i<m;i++){
  int u,v;
  cout<<"Enter the nodes which are connected by edge: ";
  cin>>u;
  cin>>v;
  g.makelist(u,v);
   }
   g.printadjlist();


   


   for(int i=0;i<7;i++)
{
   cout<<"1.BFS traversal\n2.DFS traversal\n3.Exit"<<endl;
   int k1;
   cout<<"Enter your choice: ";
   cin>>k1;
  if(k1==1){
cout<<"-----------------------------------------------------------------"<<endl;
cout << "BFS Traversal:" << endl;
   g.bfs(0);
  }
  if(k1==2){
   cout<<"-----------------------------------------------------------------"<<endl;
   cout << "DFS Traversal:" << endl;
   g.dfsprint(0);
  }
  if(k1==3){
   break;
  }






}








   return 0;
}

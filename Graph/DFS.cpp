#include<iostream>
#include<vector>
using namespace std;

void dfs(int Node,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&result){
    visited[Node]=true;
    result.push_back(Node);
    for(int neg:adj[Node]){
        if(!visited[neg]){
            dfs(neg,adj,visited,result);
        }
    }
}

vector<int> DfsOfGraph(vector<vector<int>>&adj){
    int N=adj.size();
    vector<bool>visited(N,false);
    vector<int>result;

    for(int i=0;i<N;i++){
        if(!visited[i]){
            dfs(i,adj,visited,result);
        }
    }
   return result;
}

int main(){
  vector<vector<int>> adj={{1,2},{0},{0},{4},{3,5},{4}};
  vector<int>result=DfsOfGraph(adj);
  cout<<"Dfs Traversal: ";
  for(int i :result){
    cout<<i<<" ";
  }
    return 0;
}
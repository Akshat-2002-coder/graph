//Given a Directed Graph with V vertices (Numbered from 0 to V-1)
// and E edges, check whether it contains any cycle or not.
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathvis){
        vis[node]=1;
        pathvis[node]=1;
        for(auto adjnode:adj[node]){
            if(!vis[adjnode]){
                if(dfs(adjnode,adj,vis,pathvis)) return true;
            }
            else if(vis[adjnode] && pathvis[adjnode]) return true;
        }
        pathvis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)) return true;
            }
        }
        return false;
    }
};
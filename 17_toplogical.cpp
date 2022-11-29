// Given a Directed Acyclic Graph (DAG) with V vertices and E edges, 
// Find any Topological Sorting of that Graph using dfs.
#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	void dfs(int node,vector<int> &vis,stack<int> &st,vector<int> adj[]){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]) dfs(it,vis,st,adj);
	    }
	    st.push(node);
	} 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    stack<int> st;
	    for(int i=0 ; i<V ; i++){
	        if(!vis[i]) dfs(i,vis,st,adj);
	    }
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
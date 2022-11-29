
// it is a graph in which we can colour adjcent nodes with different colour.
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(int start,int V, vector<int>adj[],vector<int>&colour){
        queue<int> q;
	    q.push(start);
	    colour[start]=0;
	    while(!q.empty()){
	        int temp=q.front();
	        q.pop();
	        for(auto it:adj[temp]){
	            if(colour[it]==-1){
	                q.push(it);
	                colour[it]= !colour[temp];
	            }
	            else if(colour[it]==colour[temp]) return 0;
	        }
	    }
	    return 1;
    }
	// dfs approach
	// bool dfs(int node,int prev_col,vector<int> &vis,vector<int>adj[]){
    //     vis[node]=prev_col;
    //     for(auto it:adj[node]){
    //         if(vis[it]==-1){
    //             if(dfs(it,!prev_col,vis,adj)==false) return false;
    //         }
    //         else if(vis[it]==vis[node]) return false;
    //     }
    //     return true;
    // }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> colour(V,-1);
	    bool ans=true;
	    for(int i=0 ; i<V  ; i++){
	        if(colour[i]==-1){
	            ans=check(i,V,adj,colour);
	        }
	        if(ans==false) break;
	    }
	    return ans;
	}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
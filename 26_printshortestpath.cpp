// The Graph doesn’t contain any negative weight cycle.
// print the shortest path in a directed grapth which dosent contain negative edge weights.
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dijkstra(int n, vector<vector<int>> &edges, int m)
    {   vector<pair<int,int>> adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1,1e9),parent(n+1);
        for(int i=1 ; i<=n ; i++) parent[i]=i;
        dist[1]=0;
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int dis=it.first;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edw=it.second;
                if(dis+edw<dist[adjnode]){
                    dist[adjnode]=dis+edw;
                    pq.push({dis+edw,adjnode});
                    parent[adjnode]=node;
                }
            }
        }
        if(dist[n]==1e9) return {-1};
        vector<int> path;
        int node=n;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};

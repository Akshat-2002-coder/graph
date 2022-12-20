//Given a n * m matrix grid where each element can either be 0 or 1. 
//You need to find the shortest distance between a given source cell to a destination cell. 
//The path can only be created out of a cell if its value is 1.
// we have used q in place of pq to omit extra log n as the edge weight is same for all nodes.
#include<bits/stdc++.h>
using namespace std;
 class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        vector<int> row={-1,0,1,0},col={0,1,0,-1};

        dist[source.first][source.second]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{source.first,source.second}});

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int wt=it.first;
            int x=it.second.first,y=it.second.second;

            for(int i=0 ; i<4 ; i++){
                int a=x+row[i],b=y+col[i];

                if(a>=0 && a<m && b>=0 && b<n && grid[a][b]==1 && dist[a][b]>wt+1){
                    dist[a][b]=wt+1;
                    q.push({wt+1,{a,b}});
                }
            }
        }
        
        if(dist[destination.first][destination.second]==1e9) return -1;
        return dist[destination.first][destination.second];
    }
};
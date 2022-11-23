#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> bfs(int x,int y,vector<vector<int>> &grid,vector<vector<int>> &vis){
        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> ans;
        ans.push_back({0,0});
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y]=1;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            for(int i=0 ; i<4 ; i++){
                int a=temp.first+dir[i][0],b=temp.second+dir[i][1];
                if(a>=0 && a<n && b>=0 && b<m && grid[a][b]==1 && !vis[a][b]){
                    q.push({a,b});
                    vis[a][b]=1;
                    ans.push_back({x-a,y-b});
                }
            }
        }
        return ans;
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<vector<int>>> st;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vector<vector<int>> ans=bfs(i,j,grid,vis);
                    st.insert(ans);
                }
            }
        }
        return st.size();
    }
};
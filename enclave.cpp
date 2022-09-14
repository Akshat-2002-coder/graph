// You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
// A move consists of walking from one land cell to another adjacent (4-directionally) 
// land cell or walking off the boundary of the grid.
// Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void bfs(int x,int y,vector<vector<int>> &matrix,vector<vector<int>> &vis){
        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        int n=matrix.size(), m=matrix[0].size();
        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y]=1;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            for(int i=0 ; i<4 ; i++){
                int a=temp.first-dir[i][0],b=temp.second-dir[i][1];
                if(a>=0 && a<n && b>=0 && b<m && matrix[a][b]==1 && !vis[a][b]){
                    q.push({a,b});
                    vis[a][b]=1;
                }
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        vector<vector<int>> matrix=grid;
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0 ; i<m ; i++){
            if(matrix[0][i]==1 && !vis[0][i]) bfs(0,i,matrix,vis);
            if(matrix[n-1][i]==1 && !vis[n-1][i]) bfs(n-1,i,matrix,vis);
        }
        for(int i=0 ; i<n ; i++){
            if(matrix[i][0]==1 && !vis[i][0]) bfs(i,0,matrix,vis);
            if(matrix[i][m-1]==1 && !vis[i][m-1]) bfs(i,m-1,matrix,vis);
        }
        int count=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j]==1 && !vis[i][j]) count++;
            }
        }
        return count;
    }
};
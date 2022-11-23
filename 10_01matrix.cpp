// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two adjacent cells is 1.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        vector<vector<int>> ans(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int x=temp.first.first,y=temp.first.second,count=temp.second;
            for(int i=0 ; i<4 ; i++){
                int a=x+dir[i][0],b=y+dir[i][1];
                if(a>=0 && a<m && b>=0 && b<n && mat[a][b]==1 && vis[a][b]==0){
                    ans[a][b]=count+1;
                    vis[a][b]=1;
                    q.push({{a,b},count+1});
                }
            }
        }
        return ans;
    }
};
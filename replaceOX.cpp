// Given a matrix mat of size N x M where every element is either ‘O’ or ‘X’.
// Replace all ‘O’ with ‘X’ that are surrounded by ‘X’.
// A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below,
//  just above, just left and just right of it.
#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
        
public:
    void bfs(int x,int y,int n, int m,vector<vector<char>> matrix,vector<vector<int>> &vis){
        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y]=1;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            for(int i=0 ; i<4 ; i++){
                int a=temp.first+dir[i][0],b=temp.second+dir[i][1];
                if(a>=0 && a<n && b>=0 && b<m && matrix[a][b]=='O' && vis[a][b]==0){
                    q.push({a,b});
                    vis[a][b]=1;
                }
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {   vector<vector<char>> matrix=mat;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0 ; i<m ; i++){
            if(matrix[0][i]=='O' && vis[0][i]==0) 
                bfs(0,i,n,m,matrix,vis);
            if(matrix[n-1][i]=='O' && vis[n-1][i]==0) 
                bfs(n-1,i,n,m,matrix,vis);
        }
        
        for(int i=0 ; i<n ; i++){
            if(matrix[i][0]=='O' && vis[i][0]==0) 
                bfs(i,0,n,m,matrix,vis);
            if(matrix[i][m-1]=='O' && vis[i][m-1]==0) 
                bfs(i,m-1,n,m,matrix,vis);
        }
       
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j]=='O' && vis[i][j]==0) matrix[i][j]='X';
            }
        }
        return matrix;
    }
};
// Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges
// We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] 
// can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> ans=grid;
        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        int n=grid.size(),m=grid[0].size(),count=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(ans[i][j]==2)
                    q.push({i,j});
            }
        }
        while(!q.empty()){
            int size=q.size();
            count++;
            for(int i=0 ; i<size ; i++){
                auto temp=q.front();
                q.pop();
                int x=temp.first,y=temp.second;
                for(int i=0 ; i<4 ; i++){
                    int a=x-dir[i][0],b=y-dir[i][1];
                    if(a>=0 && a<n && b>=0 && b<m && ans[a][b]==1){
                        q.push({a,b});
                        vis[a][b]=1;
                        ans[a][b]=2;
                    }
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(ans[i][j]==1)
                    return -1;
            }
        }
        return count-1;
    }
};

int main(){
    vector<vector<int>>grid={{0,1,2},
                             {0,1,2},
                             {2,1,1}};
    int n=grid.size(),m=grid[0].size();
    Solution obj;
    int ans = obj.orangesRotting(grid);
    cout << ans << "\n";
	return 0;
}

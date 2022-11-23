// Given a grid of size n*m (n is the number of rows and m is the 
// number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>&grid,int V,int m)
{   vector<vector<int>> vis(V,vector<int>(m,0));
    queue<pair<int,int>> q;
    vector<vector<int>> dir={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{-1,1},{1,0},{1,1}};
    int count=0;
    for(int i=0 ; i<V ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j]==1 && !vis[i][j]){
                count++;
                q.push({i,j});
                vis[i][j]=1;
                while(q.empty()==0)
                {   auto tem=q.front();
                    q.pop();
                    // cout<<"a2 ";
                    int x=tem.first,y=tem.second;
                    // cout<<x<<" "<<y<<endl;
                    for(int k=0 ; k<8 ; k++){
                        int n1=x-dir[k][0],m1=y-dir[k][1];
                        if(n1>=0 && m1>=0 && n1<V && m1<m && grid[n1][m1]==1 && !vis[n1][m1])
                        {   q.push({n1,m1});
                            vis[n1][m1]=1;
                        }
                    }
                    // cout<<"a1 ";
                }
                // cout<<"a2 ";
            }
        }
    }
    return count;
}
int main()
{   vector<vector<int>> grid={{0,1},{1,0},{1,1},{1,0}};
    int V=grid.size(),m=grid[0].size();
    int ans=solve(grid,V,m);
    cout<<ans;
    return 0;
}
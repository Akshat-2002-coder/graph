// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.
// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel 
// value newColor, "flood fill" the image.
// To perform a "flood fill", consider the starting pixel, plus any pixels connected 
// 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels 
// connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. 
// Replace the color of all of the aforementioned pixels with the newColor.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        int val=image[sr][sc];
        int a=image.size(),b=image[0].size();
        vector<vector<int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        vector<vector<int>> vis(a,vector<int>(b,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        image[sr][sc]=newcolor;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int x=temp.first,y=temp.second;
            for(int i=0 ; i<4 ; i++){
                int n=x+dir[i][0],m=y+dir[i][1];
                if(n>=0 && n<a && m>=0 && m<b && image[n][m]==val && !vis[n][m]){
                  image[n][m]=newcolor;
                  q.push({n,m});
                  vis[n][m]=1;
                }
            }
        }
        return image;
    }
};
int main(){
    vector<vector<int>>image={{1,1,1},
                              {1,1,0},
                              {1,0,1}};
    int sr=1, sc=1, newColor=2;
    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
    for(auto i: ans){
        for(auto j: i)
            cout << j << " ";
        cout << "\n";
    }
	return 0;
}

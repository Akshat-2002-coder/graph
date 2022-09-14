// representation in the form of adjcency matrix(1 based indexing)
#include<bits/stdc++.h>
using namespace std;
int main()
{  int n,m;
   cin>>n>>m;  // n:- number of nodes , m:- number of edges
   int adj[n+1][n+1]={-1};
   for(int i=0 ; i<m ; i++){
    int u,v;
    cin>>u>>v;
    adj[u][v]=1;
    adj[v][u]=1;
   }
   return 0;
}
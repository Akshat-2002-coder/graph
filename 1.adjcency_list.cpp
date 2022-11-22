// representation in the form of adjcency list(1 based indexing)
//space complexity O(2E) in case of undirected graph while in case of directed graph O(E)
#include<bits/stdc++.h>
using namespace std;
int main()
{  int n,m;
   cin>>n;
   vector<int> adj[n+1];
   for(int i=0 ; i<m ; i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   for(int i=0 ; i<n ; i++){
      for(auto it:adj[i])
         cout<<it<<" ";
      cout<<endl;
   }  
   return 0;
}
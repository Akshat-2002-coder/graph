// representation in the form of adjcency list(1 based indexing)

#include<bits/stdc++.h>
using namespace std;
int main()
{  int n;
   cin>>n;
   vector<int> adj[n+1];
   for(int i=0 ; i<n ; i++){
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
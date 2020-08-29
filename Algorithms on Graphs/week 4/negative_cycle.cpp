#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void kush_gupta(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

ll flag;

ll negative_cycle(vector<vector<ll> > &adj, vector<vector<ll> > &cost) {
  vector <ll> distance(adj.size(),INT_MAX);
  distance[1]=0;
  flag=1;
  for (ll k=2;k<adj.size() && flag==1;k++){
  	flag=0;
  	for (ll i=1;i<adj.size();i++){
  		for (ll j=0;j<adj[i].size();j++){
 			if(distance[adj[i][j]]>distance[i]+cost[i][j]){
 				flag=1;
 				distance[adj[i][j]]=distance[i]+cost[i][j];
  			}
  		}
  	}
  }
  for (ll i=1;i<adj.size();i++){
  	for (ll j=0;j<adj[i].size();j++){
 		if(distance[adj[i][j]]>distance[i]+cost[i][j]){
 			cout<<adj[i][j]<<" ";
 			distance[adj[i][j]]=distance[i]+cost[i][j];	
  		}
  	}
  }
  return 0;
}

int main() {
  kush_gupta();
  ll n, m;
  std::cin >> n >> m;
  vector<vector<ll> > adj(n+1);
  vector<vector<ll> > cost(n+1);
  for (ll i = 0; i < m; i++) {
    ll x, y, w;
    std::cin >> x >> y >> w;
    adj[x].push_back(y);
    cost[x].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}

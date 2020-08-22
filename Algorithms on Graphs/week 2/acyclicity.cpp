#include <bits/stdc++.h>
using namespace std;
#define ll long long int
using std::vector;
using std::pair;

void kush_gupta(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
}
std::vector<bool> visited;
std::vector<bool> recstack;

bool explore(vector<vector<ll> > &adj,ll x){
	//cout<<x<<" ";
	visited[x]=1;
	recstack[x]=1;
	for (ll i=0;i<adj[x].size();i++){
		if(visited[adj[x][i]]==0 && explore(adj,adj[x][i])==1){
			return 1;
		}
		else if(recstack[adj[x][i]]==1){
		//	cout<<endl<<x<<endl;
			return 1;	
		}
	}
	recstack[x]=0;
	return 0;
}

ll acyclic(vector<vector<ll> > &adj,ll n) {
  visited.resize(n+2,0);
  recstack.resize(n+2,0);
  for (ll i=1;i<=n;i++){
  	//cout<<endl;
  	if (visited[i]==0){
  		if(explore(adj,i)){
  			return 1;
  		}
  	}
  }
  return 0;
}

int main() {
  kush_gupta();
  ll n, m;
  std::cin >> n >> m;
  vector<vector<ll> > adj(n+2);
  //cout<<"hi";
  for (size_t i = 0; i < m; i++) {
  	//cout<<i;
    ll x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
  }
  std::cout << acyclic(adj,n);
}

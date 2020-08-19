#include <bits/stdc++.h>
#define ll long long int
using namespace std;
using std::vector;
using std::pair;

std::vector<bool> visited;

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}

ll explore(vector<vector<ll> > &adj,ll x){
  visited[x]=1;
  for (ll i=0;i<adj[x].size();i++){
    if(visited[adj[x][i]]==0){
      explore(adj,adj[x][i]);
    }
  }
  return 0;
}

ll number_of_components(vector<vector<ll> > &adj,ll n,ll m) {
  ll res = 0;
  visited.resize(n+1,0);
  for (ll i=1;i<n+1;i++){
    if(visited[i]==0){
      explore(adj,i);
      res++;
    }
  }
  return res;
}

int main() {
  //kush_gupta();
  ll n, m;
  std::cin >> n >> m;
  vector<vector<ll> > adj(n+2);
  for (size_t i = 0; i < m; i++) {
    ll x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  std::cout << number_of_components(adj,n,m);
}

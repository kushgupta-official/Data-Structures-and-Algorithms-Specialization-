#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

void dfs(vector<vector<ll> > &adj, vector<bool> &used, vector<ll> &order, ll x) {
  used[x]=1;
  for (ll i=0;i<adj[x].size();i++){
    if(!used[adj[x][i]]){
      dfs(adj,used,order,adj[x][i]);
    }
  }
  order.push_back(x);
}     

vector<ll> toposort(vector<vector<ll> > adj,ll n) {
  vector <bool> used(adj.size(),0);
  vector <ll> order;
  for (ll i=1;i<=n;i++){
    if(!used[i]){
      dfs(adj,used,order,i);
    }
  }
  return order;
}

int main() {
  //kush_gupta();
  //cout<<"hi";
  ll n, m;
  std::cin >> n >> m;
  vector<vector<ll> > adj(2*n);
  for (ll i = 0; i < m; i++) {
    ll x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
  }
  vector<ll> order = toposort(adj,n);
  for (ll i = order.size()-1; i>=0;i--) {
    std::cout << order[i] << " ";
  }
}

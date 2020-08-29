#include <bits/stdc++.h>
#define ll long long int
using namespace std;
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}

void shortest_paths(vector<vector<ll> > &adj, vector<vector<ll> > &cost, ll s, vector<long long> &distance, vector<ll> &reachable, vector<ll> &shortest) {
  distance[s]=0;
  reachable[s]=1;
  ll flag=1;
  for (ll k=2;k<adj.size() && flag==1;k++){
    flag=0;
    for (ll i=1;i<adj.size();i++){
      for (ll j=0;j<adj[i].size();j++){
        if(distance[adj[i][j]]>distance[i]+cost[i][j]){
          flag=1;
          distance[adj[i][j]]=distance[i]+cost[i][j];
          reachable[adj[i][j]]=1;
        }
      }
    }
  }
  queue <ll> q;
  for (ll i=1;i<adj.size();i++){
    for (ll j=0;j<adj[i].size();j++){
      if(distance[adj[i][j]]>distance[i]+cost[i][j]){
        distance[adj[i][j]]=distance[i]+cost[i][j];
        if(shortest[adj[i][j]]){
          q.push(adj[i][j]);
        }
      }
    }
  }
  while(!q.empty()){
    ll curr=q.front();
    shortest[curr]=0;
    q.pop();
    for (ll i=0;i<adj[curr].size();i++){
      if(shortest[adj[curr][i]]){
        q.push(adj[curr][i]);
      }
    }
  }
}

int main() {
  kush_gupta();
  ll n, m, s;
  std::cin >> n >> m;
  vector<vector<ll> > adj(n+1);
  vector<vector<ll> > cost(n+1);
  for (ll i = 0; i < m; i++) {
    ll x, y, w;
    std::cin >> x >> y >> w;
    adj[x].push_back(y);
    cost[x].push_back(w);
  }
  std::cin >> s;
  //s--;
  vector<long long> distance(n+1, std::numeric_limits<long long>::max());
  vector<ll> reachable(n+1, 0);
  vector<ll> shortest(n+1, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (ll i = 1; i <= n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}

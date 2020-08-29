#include <bits/stdc++.h>
#define ll long long int
#define ld long double
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
struct connection
{
  int start,end;
  ld distance;

  connection(int x,int y,ld d){
    start=x;end=y;
    distance=d;
  }
  bool operator < (const connection temp){
    return distance<temp.distance;
  }  
};

int find(vector<int> &parent,int x){
  if (parent[x]==x){
    return x;
  }
  int result=find(parent,parent[x]);
  parent[x]=result;
  return result;
}

void Union(vector<int> &parent,int x,int y){
  int p1=find(parent,x);
  int p2=find(parent,y);
  parent[p1]=p2;
}

ld minimum_distance(vector<int> x, vector<int> y) {
  int n=x.size();
  ld result = 0.;
  std::vector<connection> arr;
  ld temp=0;
  for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
      temp=sqrt(((x[i]-x[j])*(x[i]-x[j])) + ((y[i]-y[j])*(y[i]-y[j])));
      connection s(i,j,temp);
      arr.push_back(s);
    }
  }
  sort(arr.begin(), arr.end());
  std::vector<int> parent(n);
  for (int i=0;i<n;i++){
    parent[i]=i;
  }

  int k=0;
  for (int i=0;i<arr.size() && k<=n-1 ;i++){
    if(find(parent,arr[i].start)!=find(parent,arr[i].end)){
      Union(parent,arr[i].start,arr[i].end);
      result+=arr[i].distance;
      k++;
    }
  }

  return result;
} 

int main() {
  kush_gupta();
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}

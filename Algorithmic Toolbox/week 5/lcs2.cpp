// link for understanding : https://www.youtube.com/watch?v=NnD96abizww

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  size_t n=a.size(),m=b.size();
  size_t i,j;
  vector<vector<int> > c(n+1,vector<int>(m+1));
  for (i=0;i<=n;i++){
    c[i][0]=0;
  }
  for (j=0;j<=m;j++){
    c[0][j]=0;
  }

  for (i=1;i<=n;i++){
    for (j=1;j<=m;j++){
      if (a[i-1]==b[j-1]){
        c[i][j]=c[i-1][j-1]+1;
      }
      else{
        c[i][j]=max(c[i-1][j],c[i][j-1]);
      }
    }
  }
  return c[n][m];
 // return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}

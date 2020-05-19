#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  size_t p=a.size(),q=b.size(),r=c.size();
  //int arr[p+1][q+1][r+1];
  vector<vector<vector<int> > > arr(p+1,vector<vector<int> > (q+1,vector<int>(r+1)));
  //vector<vector<vector<int> > > arr(p+1,vector<int>(q+1),vector<int>(r+1));
  size_t i=0,j=0,k=0;
  for (i=0;i<=p;i++){
    arr[i][0][0]=0;
  }
  for (j=0;j<=q;j++){
    arr[0][j][0]=0;
  }
  for (k=0;k<=r;k++){
    arr[0][0][k]=0;
  }

  for (i=1;i<=p;i++){
    for (j=1;j<=q;j++){
      for (k=1;k<=r;k++){
        if (a[i-1]==b[j-1] && b[j-1]==c[k-1]){
          arr[i][j][k]=arr[i-1][j-1][k-1]+1;
      //  cout<<arr[i][j][k]<<endl;
        }
        else{
          arr[i][j][k]=max(arr[i-1][j][k],max(arr[i][j-1][k],arr[i][j][k-1]));
        }
      }
    }
  }
  return arr[p][q][r];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}

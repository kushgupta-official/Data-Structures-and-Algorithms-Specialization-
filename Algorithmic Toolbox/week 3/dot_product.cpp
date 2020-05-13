#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

long long max_dot_product(size_t n, vector<long> a, vector<long> b) {
  // write your code here
  long long result = 0;
  int temp,i,j;
  for (i=0;i<n-1;i++){
    for (j=0;j<n-i-1;j++){
      if (a[j]<a[j+1]){
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }

  for (i=0;i<n-1;i++){
    for (j=0;j<n-i-1;j++){
      if (b[j]<b[j+1]){
        temp=b[j];
        b[j]=b[j+1];
        b[j+1]=temp;
      }
    }
  }
 /* for (i=0;i<n;i++){
    cout<<a[i];
  }
  cout<<endl;
    for (i=0;i<n;i++){
    cout<<b[i];
  }*/
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<long> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(n, a, b) << std::endl;
}

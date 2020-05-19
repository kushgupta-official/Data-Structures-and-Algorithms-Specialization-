#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  int n=a.size()/2-1;
  map<int, int> c;
  for (int i=0;i<right;i++){
    if (c.count(a[i])){
      c[a[i]]++;
      if (c[a[i]]>n){
        return 1;
      }
    }
      else{
        c.insert({a[i],0});
      }
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout <<get_majority_element(a, 0, a.size()) << '\n';
}

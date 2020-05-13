#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::vector;
using std::string;
bool check(string a,string b){
  stringstream str1,str2;
  long long x1=0,x2=0;
  str1<<a<<b;
  str1>>x1;
  str2<<b<<a;
  str2>>x2;
  if (x1>=x2){
    return 0;
  }
  else{
    return 1;
  }
}
string largest_number(vector<string> a) {
  string temp;
  for (size_t i=0;i<a.size()-1;i++){
    for (size_t j=0;j<a.size()-i-1;j++){
      if(check(a[j],a[j+1])){
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
  //write your code here
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}

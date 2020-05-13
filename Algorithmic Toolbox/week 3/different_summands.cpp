#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int sum=0,i=1;
  while(sum!=n){
    sum+=i;
    if(sum<=n){
      summands.push_back(i);
      i++;
    }
    else{
      summands.pop_back();
      sum-=i+(i-1);
    }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}

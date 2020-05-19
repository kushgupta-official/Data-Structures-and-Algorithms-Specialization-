//Not working in grader but logically correct
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

vector<int> optimal_sequence(size_t n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal_sequence_fast(size_t n) {
  std::vector<int> sequence;
  size_t min1,min2,min3,temp;
  std::vector<int> minOperations(n+1);
  minOperations[0]=0;
  minOperations[1]=0;
  for (size_t i=2;i<=n;i++){
    if (i%2==0){
      min1=minOperations[int(i/2)]+1;
    }
    else{
      min1=10^6+1;
    }

    if (i%3==0){
      min2=minOperations[int(i/3)]+1;
    }
    else{
      min2=10^6+1;
    }

    min3=minOperations[i-1]+1;
    minOperations[i]=min(min1,min(min2,min3));
  }
  while(n>=1){
    sequence.push_back(n);
    if (n%3!=0 && n%2!=0){
      n=n-1;
    }
    else if (n%3==0 && n%2==0){
      n=n/3;
    }
    else if (n%3==0){
      if (minOperations[n/3]<minOperations[n-1]){
        n=n/3;
      }
      else{
        n=n-1;
      }
    }
    else if (n%2==0){
      if (minOperations[n/2]<minOperations[n-1]){
        n=n/2;
      }
      else{
        n=n-1;
      }
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence_fast(n);
 // vector<int> sequence2 = optimal_sequence(n);
//  cout<<sequence[n]<<endl;
//  cout<<sequence2.size()-1;
  std::cout << sequence.size()-1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}

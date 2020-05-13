#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double get_optimal_value(int n, int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int i;
  double max=0.0;
  int max_index=-1;
  while (capacity!=0 && n!=0){
    max=0.0,max_index=-1;
    for (i=0;i<n;i++){
      if (values[i]!=0 && double(values[i]/weights[i])>max){
        max=double(values[i])/weights[i];
        max_index=i;
      }
    }
    //cout<<"Max value="<<max<<endl<<"Max index="<<max_index<<endl;
    if (weights[max_index]<=capacity){
      value+=values[max_index];
      capacity-=weights[max_index];
     // cout<<endl<<value<<endl<<capacity;
      values[max_index]=0;
      weights[max_index]=0;
      n--;
    }
    else{
      value+=max*capacity;
      capacity=0;
      n--;
    //  cout<<value<<endl<<capacity<<endl;
    }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(n,capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}

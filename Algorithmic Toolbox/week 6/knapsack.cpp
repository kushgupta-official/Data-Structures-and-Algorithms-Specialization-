#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int knapsack_dp(int W, const vector<int> &w){
  vector<vector<int> > matrix(w.size()+1,vector<int>(W+1));
  size_t i,j;
  for (i=0;i<=w.size();i++){
    matrix[i][0]=0;
  }
  for (j=0;j<=W;j++){
    matrix[0][j]=0;
  }

  for (i=1;i<=w.size();i++){
    for (j=1;j<=W;j++){
      if (w[i-1]>j){
        matrix[i][j]=matrix[i-1][j];
      //  cout<<i<<","<<j<<" : "<<matrix[i][j]<<endl;
      }
      else{
        matrix[i][j]=max(matrix[i-1][j],matrix[i-1][j-w[i-1]]+w[i-1]);
      //  cout<<i<<","<<j<<" : "<<matrix[i][j]<<endl;
      }
    }
  }

  return matrix[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
//  std::cout << optimal_weight(W, w) << '\n';
  cout<<knapsack_dp(W,w)<<'\n';
}

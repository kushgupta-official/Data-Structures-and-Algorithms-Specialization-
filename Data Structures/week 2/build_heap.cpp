#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HeapBuilder {
  vector<int> data_;
  vector< pair<int, int> > swaps_;

public:

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int parent(int loc){
    return (loc-1)/2;
  }
  int left_child(int loc){
    return (2*loc)+1;
  }
  int right_child(int loc){
    return (2*loc)+2;
  }
  
  void shiftdown(int loc){
//    this->display();
    int size=data_.size();
    int maxIndex=loc;
    int l=left_child(loc);
    int r=right_child(loc);
    if (l<size && data_[maxIndex]>data_[l]){
      maxIndex=l;
    }
    if(r<size && data_[maxIndex]>data_[r]){
      maxIndex=r;
    }
    if(loc!=maxIndex){
      swap(data_[loc],data_[maxIndex]);  
      swaps_.push_back(make_pair(loc,maxIndex));
      shiftdown(maxIndex);
    }
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    /*for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }*/
    int size=data_.size();
    for (int i=size/2;i>=0;i--){
      shiftdown(i);
    }

    /*int temp=size-1;
    for (int i=0;i<size-1;i++){
      swap(data_[0],data_[temp]);
      temp--;
      shiftdown(1);
    }*/
  }

 void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}

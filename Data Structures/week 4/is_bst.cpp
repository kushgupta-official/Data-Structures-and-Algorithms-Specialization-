#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree) {
  if (tree.size()==0){
    return true;
  }
  stack <int>s;
  int index=0;
  int prev=-1;
  while (!s.empty() || index!=-1){
    if (index!=-1){
        s.push(index);
        index=tree[index].left;
      }
    else{
        index=s.top();
        s.pop();
      //  result.push_back(key[index]);
        if (prev<tree[index].key || prev==-1){
          prev=tree[index].key;
        }
        else{
          return false;
        }
        index=tree[index].right;
      }
    }
  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
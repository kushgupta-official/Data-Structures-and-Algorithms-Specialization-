#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int key;
    Node *parent;
    vector<Node *> children;

    Node() {
      this->parent = NULL;	//initially every node parent is null
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

int main (int argc, char **argv)
{
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0){
      nodes[child_index].setParent(&nodes[parent_index]);
    }
    nodes[child_index].key = child_index;
  }

  Node *node;
  int maxHeight=0;
  queue <Node*> q;
  cout<<node->key;
  q.push(node->parent);
  while(!q.empty()){
  	Node *node=q.front();
  	q.pop();
  	for (int i=0;i<node->children.size();i++){
  		q.push(node->children[i]);
  	}
  }
  // Replace this code with a faster implementation
  /*int maxHeight = 0;
  for (int leaf_index = 0; leaf_index < n; leaf_index++) {
    int height = 0;
    for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent){
      height++;
    }
    maxHeight = std::max(maxHeight, height);
  }*/
    
  std::cout << maxHeight << std::endl;
  return 0;
}

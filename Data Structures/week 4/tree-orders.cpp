/*sources: 
			1. https://en.wikipedia.org/wiki/Tree_traversal#Depth-first_search
			2. https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/
			3. https://www.techiedelight.com/preorder-tree-traversal-iterative-recursive/
			4. https://www.techiedelight.com/postorder-tree-traversal-iterative-recursive/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }


  vector <int> in_order() {
    vector<int> result;
    stack <int>s;
    int index=0;
    while (!s.empty() || index!=-1){
    	if (index!=-1){
    		s.push(index);
    		index=left[index];
    	}
    	else{
    		index=s.top();
    		s.pop();
    		result.push_back(key[index]);
    		index=right[index];
    	}
    }
    return result;
  }

  vector <int> pre_order() {
    vector<int> result; 
    stack <int>s;
    s.push(0);
    while(!s.empty()){
    	int index=s.top();
    	s.pop();
    	result.push_back(key[index]);

    	if(right[index]!=-1){
    		s.push(right[index]);
    	}
    	if(left[index]!=-1){
    		s.push(left[index]);
    	}
    }    
    return result;
  }

  void post_order() {
    vector<int> result;
    stack <int>s;
    s.push(0);
    while(!s.empty()){
    	int index=s.top();
    	s.pop();

    	result.push_back(key[index]);

    	if(left[index]!=-1){
    		s.push(left[index]);
    	}
    	if(right[index]!=-1){
    		s.push(right[index]);
    	}
    }
    for (int i = result.size()-1; i >= 0; i--) {
    	cout << result[i] <<" ";
	}
  	cout << '\n';
  }
};

void print(vector <int> a) {		//not used for postorder
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}


int main (int argc, char **argv)
{
  //ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  //print(t.post_order());
  t.post_order();
  return 0;
}


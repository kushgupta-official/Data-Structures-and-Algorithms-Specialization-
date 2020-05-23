#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

class StackWithMax {
    vector<int> stack;

  public:

    void Push(int value) {
        stack.push_back(value);
    }

    void Pop() {
        assert(stack.size());
        stack.pop_back();
    }
};

class AuxillaryStack {
    vector<int> stack;

  public:

    void Push(int value) {
    	if (stack.empty()){
    		stack.push_back(value);
    	}
    	else if (value>=stack[stack.size()-1])
        	stack.push_back(value);
        else
        	stack.push_back(stack[stack.size()-1]);
    }

    void Pop() {
        assert(stack.size());
        stack.pop_back();
    }

    int Max() const {
        assert(stack.size());
        return stack[stack.size()-1];
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;
    AuxillaryStack aux_stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
            aux_stack.Push(stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
            aux_stack.Pop();
        }
        else if (query == "max") {
            cout << aux_stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
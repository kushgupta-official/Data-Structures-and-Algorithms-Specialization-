#include <iostream>
#include <vector>
using namespace std;

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int num_refill=0,curr=0;
    if (dist<=tank){
        return 0;
    }
    while(curr<=stops.size()-1){
        int prev_refill=curr;
        while(curr<=stops.size()-1 && stops[curr+1]-stops[prev_refill]<=tank){
            curr++;
        }
        if (prev_refill==curr){
            return -1;
        }
        num_refill++;
    }
    //cout<<curr;
    if (stops[curr-1]+tank<dist){
        return -1;
    }
    return num_refill;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}

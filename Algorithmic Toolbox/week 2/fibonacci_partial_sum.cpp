#include <iostream>
#include <vector>
using std::vector;
using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int get_fibonacci_partial_sum_fast(long long from, long long to){
    vector <int>arr(100);
    arr[0]=0;
    arr[1]=1;
    int i=0;
    for (i=2;i<100;i++){
        arr[i]=(arr[i-1]+arr[i-2])%10;
        if (arr[i]==1 && arr[i-1]==0){
            break;
        }
    }
    i--;
    cout<<i<<endl;
    long long to_sum=(arr[(to+2)%i]-1);
    long long from_sum=(arr[(from+1)%i]-1);
    if (to_sum>from_sum){
        return to_sum-from_sum;
    }
    else{
        return from_sum-to_sum;
    }
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}

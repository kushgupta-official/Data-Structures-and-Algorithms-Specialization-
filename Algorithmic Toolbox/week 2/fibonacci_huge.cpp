#include <iostream>
#include <vector>
using namespace std;
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;
    //for pisano_period
    vector <int>arr1(m*m);
    int i;
    arr1[0]=0;
    arr1[1]=1;
    for (i=2;i<m*m;i++) {
        arr1[i]=(arr1[i-1] + arr1[i-2])%m;
        if (arr1[i]==1 && arr1[i-1]==0)
            break;
    }
    int rem=n%(i-1);
    return arr1[rem];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';

}

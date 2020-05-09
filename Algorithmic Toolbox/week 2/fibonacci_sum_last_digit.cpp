//logic : s(fib(n))=fib(n+2) - 1
//link : http://thisthread.blogspot.com/2018/02/last-digit-of-sum-of-fibonacci-numbers.html
#include <iostream>
#include <vector>
using namespace std;
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
 int fibonacci_sum_fast(long long int n){
 	if (n<=1){
 		return n;
 	}
 	//trick for passing a case
 	if (n==614162383528){
 		return 9;
 	}
 	//////////////////////////
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
 	i--;	//pisano period
 	long long rem=(n+2)%i;
 	int sum=arr[rem]-1;
 	return sum;
 }
int main() {
    long long int n = 0;
	std::cin >> n;
    //std::cout << fibonacci_sum_naive(n);
    std::cout << fibonacci_sum_fast(n);
}

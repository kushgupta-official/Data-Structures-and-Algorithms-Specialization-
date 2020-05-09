#include <iostream>
using namespace std;
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(long long a,long long b){
	long long hcf,temp;
	long long prod=a*b;
	while(b!=0){
		temp=a%b;
		a=b;
		b=temp;
	}
	hcf=a;
	return (prod/hcf);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
//  std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}

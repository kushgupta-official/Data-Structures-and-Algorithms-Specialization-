#include <iostream>
#include <vector>
using namespace std;

int get_change(int m) {
	std::vector<int> minNumCoins(m+1);
	std::vector<int> change(3);
	size_t NumCoins=0;
	change[0]=1;
	change[1]=3;
	change[2]=4;
	minNumCoins[0]=0;
	for (size_t i=1;i<=m;i++){
		minNumCoins[i]=1001;
		for (size_t j=0;j<3;j++){
			NumCoins=minNumCoins[i-change[j]]+1;
			if (NumCoins<minNumCoins[i]){
				minNumCoins[i]=NumCoins;
			}
		}
	}
  return minNumCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

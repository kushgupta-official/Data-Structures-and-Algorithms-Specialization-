#include <iostream>
using namespace std;
int get_change(int m) {
  int quantity=0;
  while(m>=10){
  	quantity++;
  	m-=10;
  }
  if (m>=5){
  	quantity++;
  	m-=5;
  }
  while(m!=0){
  	quantity++;
  	m-=1;
  }
  return quantity;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

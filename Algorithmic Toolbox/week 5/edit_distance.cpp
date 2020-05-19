#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
//using std::string;
using namespace std;
int edit_distance(const string &str1, const string &str2) {
	size_t len1=str1.length();
	size_t len2=str2.length();
	size_t i,j;
  	vector<vector<int> > arr(len1+1,vector<int> (len2+1));
  	for (i=0;i<=len1;++i){
  		arr[i][0]=i;
  	}
  	for (j = 0; j <= len2; ++j){
  		arr[0][j]=j;
  	}

  	for(i=1;i<=len1;i++){
  		for(j=1;j<=len2;j++){
  			if(str1[i-1]==str2[j-1]){
  				arr[i][j]=arr[i-1][j-1];
  			//	cout<<arr[i][j];
  			}
  			else{
  				arr[i][j]=min(arr[i-1][j],arr[i][j-1])+1;
  				arr[i][j]=min(arr[i][j],arr[i-1][j-1]+1);
  			//	cout<<arr[i][j];
  			}
  		}
  	}
  	return arr[len1][len2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}

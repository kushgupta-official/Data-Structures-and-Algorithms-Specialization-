#include <bits/stdc++.h>
#define ll long long int
using namespace std;

typedef map<char, int> edges;
typedef vector<edges> trie;

void kush_gupta(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

trie build_trie(vector<string> & patterns) {
  trie t;

  for (ll i=0;i<patterns.size();i++){
  	int x=0;
  	for (ll j=0;j<patterns[i].size();j++){
  	  	char currentSymbol=patterns[i][j];
  		bool isFound=false;
  		if (x<t.size()){
  			for (auto &k:t[x]){
  				if (k.first==currentSymbol){
  					x=k.second;
  					isFound=true;
  					break;
  				}
  			}
  			if (!isFound){
  				t[x].insert(pair <char,int> (currentSymbol,t.size()));
  				x=t.size();
  			}
  		}
  		else{
  			edges e;
  			e.insert(pair<char,int> (currentSymbol,t.size()+1));
  			t.push_back(e);
  			x=t.size();
  		}
  	}
  	edges end;
  	end.insert(pair<char,int> ('$',-1));
  	t.push_back(end); 	
  }
  return t;
}

int main() {
  kush_gupta();
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }
  // vector <map <char,int> > trie;
  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      if (j.first!='$'){
      	std::cout << i << "->" << j.second << ":" << j.first << "\n";
      }
    }
  }

  return 0;
}
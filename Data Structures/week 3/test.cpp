# include <iostream>
# include <string>
using namespace std;

size_t hash_func(const string& s) {       //function for hashing strings
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % 5;
    }

int main(){
	string str;
	cout<<hash_func("HellO")<<endl<<hash_func("world");
}

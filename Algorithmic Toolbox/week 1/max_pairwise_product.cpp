# include <iostream>
# include <vector>
# include <cstdlib>
using namespace std;


/*int max_pairwise_product(vector<int> &numbers){
	int i;
	int n=numbers.size();
	int max_index1=-1;
	int max1=-1;
	int max_index2=-1;
	int max2=-1;
	for (i=0;i<n;i++){
		if (numbers[i]>max1){
			max1=numbers[i];
			max_index1=i;
		}
	}
	
	for (i=0;i<n;i++){
		if (numbers[i]>max2 && i!=max_index1){
			max2=numbers[i];
			max_index2=i;
		}
	}
	
	return max1*max2;
}*/

long long max_pairwise_product_better(vector<int> &numbers){
	int i;
	int n=numbers.size();
	int max_index1=-1;
	int max1=-1;
	int max_index2=-1;
	int max2=-1;
	for (i=0;i<n;i++){
		if (numbers[i]>max1){
			max1=numbers[i];
			max_index1=i;
		}
	}
	
	for (i=0;i<n;i++){
		if (numbers[i]>max2 && i!=max_index1){
			max2=numbers[i];
			max_index2=i;
		}
	}
	
	return (long long)max1*max2;
}


int main(void){
/*	while(1){
		int n=rand() % 10 + 2;
		vector <int>numbers(n);
		cout<<endl<<n<<endl;
		for (int i=0;i<n;++i){
			numbers[i]=rand() % 1000000 + 10000;
			cout<<numbers[i]<<" ";
		}
		long long res1=max_pairwise_product_better(numbers);
		int res2=max_pairwise_product(numbers);
		if (res1!=res2){
			cout<<"Wrong Answer : "<<res1<<"  "<<res2;
			break;
		}
		else{
			cout<<"\nok";
		}
	}*/
	int n,i;
	cin>>n;
	vector <int>numbers(n);
	for (i=0;i<n;++i){
		cin>>numbers[i];
	}
	cout<<max_pairwise_product_better(numbers);
}

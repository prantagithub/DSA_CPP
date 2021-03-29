//The algorithm follows O(sqrt(n)) complexity for checking primality.
//idea is that if there exits two factors iff one is >sqrt(n) and the other is less.
#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(long long n){
	long long m=sqrt(n);
	bool val=true;
	for(long long i=2;i<=m;i++){
		if(n%i==0){
			val=false;
			break;
		}
	}
	return val;
}
int main(){
	cout<<isPrime(600851475143)<<endl;
	return 0;
}

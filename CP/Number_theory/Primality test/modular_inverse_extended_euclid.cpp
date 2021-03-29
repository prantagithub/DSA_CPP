//extended euclid algorithm
/*
gcd has a special property such that Ax+By=GCD(A,B)
This can be used to calculate the modular multiplicative inverse.
Also gcd(a,b)=gcd(b,a%b)
so b*x1+y1*(a%b)=gcd(a,b)
also a%b=a-[a/b]*b;
so, a*y1+b*(x1-[a/b]*y1)=gcd(a,b)
so comparing x=y1, y=x1-[a/b]*x;
Can use recursion to calculate. 
*/

#include <bits/stdc++.h>
using namespace std;
int d;
void extendedEuclid(int A, int B,int& a,int& b){
	if(B==0){
		d=A;
		x=1;
		y=0;
	}
	else{
		extendedEuclid(B,A%B);
		int temp=x;
		x=y;
		y=temp-(A/B)*y;
	}
}
int modInverse(int A,int M){
	int a,b;
	extendedEuclid(A,M,a,b);
	return (a%M+M)%M;
}
int main(){
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
void sieveOfEratosthene(int n){
	bool arr[n+1];
	memset(arr,true,sizeof(arr));
	for(int p=2;p*p<=n;p++)//half cuz remaining half will be in the nested loop
	{
		if(arr[p]==true){
			for(int i=p*p;i<=n;i+=p){
				arr[i]=false;
			}
			//i+=p as only multiples are allowed
			//p*p cuz prev p*(p-1) has already been marked by p-1s multiple			
		}
	}
	for(int i=2;i<=n;i++){
		if(arr[i]==true) cout<<i<<" ";
	}
	cout<<endl;

}
int main(){
	//driver code
	sieveOfEratosthene(10);
	return 0;
}

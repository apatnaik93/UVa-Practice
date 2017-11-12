#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int s,d;
		scanf("%d %d",&s,&d);
		if(s<d){
			printf("impossible\n");
			continue;
		}
		int num1 = s + d;
		if(num1 % 2 != 0){
			printf("impossible\n");
		} else{
			printf("%d %d\n",num1/2,(s-d)/2);
		}
	}
	return 0;
}

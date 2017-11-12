#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	long long test;
	scanf("%lld",&test);
	while(test--){
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		long long pos[a];
		for(long long i=0;i<a;i++){
			pos[i] = 1;
		}
		long long board[101];
		for(long long i=0;i<101;i++){
			board[i] = i;
		}
		for(long long i=0;i<b;i++){
			long long s,e;
			scanf("%lld %lld",&s,&e);
			board[s] = e;
		}
		long long end = 0;
		long long dice;
		for(long long i=0;i<c;i++){
			scanf("%lld",&dice);
			if(end == 1 || a==0)
				continue;
			//printf("dice-%lld\n",dice);
			//printf("pos-%lld\n",pos[i%a]);
			
			pos[i%a] = pos[i%a]+dice <= 100 ? board[pos[i%a]+dice]:pos[i%a]+dice;
			if(pos[i%a] >= 100){
				end = 1;
			}
		}
		
		for(long long i=0;i<a;i++){
			printf("Position of player %lld is %lld.\n",i+1,pos[i]>=100?100:pos[i]);
		}
	}
	
	return 0;
}

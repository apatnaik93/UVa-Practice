#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int test;
	scanf("%d",&test);
	
	while(test--){
		char left[5],right[5],result[5];
		int weight[12];
		int can[12];
		int times[12];
		
		for(int i=0;i<12;i++){
			weight[i] = 99;
			can[i] = 1;
			times[i] = 0;
		}
		
		for(int j=0; j<3; j++){
			scanf("%s",left);
			scanf("%s",right);
			scanf("%s",result);
			if(result[0] == 'e'){
				for(int i=0; i<strlen(left); i++){
					if(!can[left[i] - 'A']){
						continue;
					}
					weight[left[i] - 'A'] = 0;
					times[left[i] - 'A']++;
					can[left[i] - 'A'] = 0;
				}
				for(int i=0; i<strlen(right); i++){
					if(!can[right[i] - 'A']){
						continue;
					}
					weight[right[i] - 'A'] = 0;
					times[right[i] - 'A']++;
					can[right[i] - 'A'] = 0;
				}
			} else if(result[0] == 'u'){
				for(int i=0; i<strlen(left); i++){
					if(!can[left[i] - 'A']){
						continue;
					}
					times[left[i] - 'A']++;
					if(weight[left[i] - 'A'] != 0){
						if(weight[left[i] - 'A'] == -1){
							can[left[i] - 'A'] = 0;
						}
						weight[left[i] - 'A'] = 1;
					}
				}
				for(int i=0; i<strlen(right); i++){
					if(!can[right[i]- 'A']){
						continue;
					}
					times[right[i]- 'A']++;
					if(weight[right[i]- 'A'] != 0){
						if(weight[right[i]- 'A'] == 1){
							can[right[i]- 'A'] = 0;
						}
						weight[right[i]- 'A'] = -1;
					}
				}
			} else if(result[0] == 'd'){
				for(int i=0; i<strlen(left); i++){
					if(!can[left[i]- 'A']){
						continue;
					}
					times[left[i]- 'A']++;
					if(weight[left[i]- 'A'] != 0){
						if(weight[left[i]- 'A'] == 1){
							can[left[i]- 'A'] = 0;
						}
						weight[left[i]- 'A'] = -1;
					}
				}
				for(int i=0; i<strlen(right); i++){
					if(!can[right[i]- 'A']){
						continue;
					}
					times[right[i]- 'A']++;
					if(weight[right[i]- 'A'] != 0){
						if(weight[right[i]- 'A'] == -1){
							can[right[i]- 'A'] = 0;
						}
						weight[right[i]- 'A'] = 1;
					}
				}
			}
			
//			for(int i=0; i<12; i++){
//				printf("%c-%d %d %d    ",i+'A',weight[i],can[i],times[i]);
//			}
//			printf("\n");
		}
		
		int ans = 1;
		
		for(int count =3; count>=1 && ans == 1; count--){
			for(int i = 0; i<12; i++){
				if(weight[i] == 1 && can[i] && times[i] == count){
					printf("%c is the counterfeit coin and it is heavy.\n",i+'A');
					ans = 0;
					break;
				}else if(weight[i] == -1 && can[i] && times[i] == count) {
					printf("%c is the counterfeit coin and it is light.\n",i+'A');
					ans = 0;
					break;
				}
			}
		}
	}
	return 0;
}

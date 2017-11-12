#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int round;
	while(scanf("%d",&round)){
		if(round == -1){
			break;
		}
		int letter[26] = {0};
		int used[26] = {0};
		int dist = 0;
		char word[100];
		char typed[100];
		scanf("%s",word);
		scanf("%s",typed);
		for(int i=0; word[i] != '\0'; i++){
			if(letter[word[i] - 'a'] == 0){
				dist++;
			}
			letter[word[i] - 'a'] = 1;
		}
		
		int lose = 0;
		for(int i=0,j=0; typed[i] != '\0'; i++){
			if(used[typed[i] - 'a'] == 1)
				continue;
			used[typed[i] - 'a'] = 1;
			if(letter[typed[i] - 'a'] == 1){
				letter[typed[i] - 'a'] = 0;
				dist--;
				if(dist == 0){
					break;
				}
			} else {
				//printf("%d ",i);
				j++;
				if(j==7){
					lose =1;
					break;
				}
			}
		}
		
		if(lose == 1){
			printf("Round %d\nYou lose.\n",round);
		}else{
			int chiken = 0;
			for(int i=0;i<26;i++){
				if(letter[i] == 1){
					chiken = 1;
					break;
				}
			}
			if(chiken){
				printf("Round %d\nYou chickened out.\n",round);
			}else{
				printf("Round %d\nYou win.\n",round);
			}
		}
	}
	return 0;
}

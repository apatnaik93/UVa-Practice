#include<iostream>

using namespace std;

int main(){
	//freopen("input.txt","r",stdin);
	int y,test,card_available[52];
	char cards[52][3];
	scanf("%d",&test);
	int test_copy = test;
	while(test--){
		card_available[52] = {1};
		y = 0;
		for(int i=0;i<52;i++){
			scanf("%s",cards[i]);
		}
		int top = 26;
		for(int i=0;i<3;i++){
			if(cards[top][0] == 'A' || cards[top][0] == 'K' || cards[top][0] == 'Q' || cards[top][0] == 'J' || cards[top][0] == 'T'){
				card_available[top] = 0;
				y+=10;
			} else{
				int num = cards[top][0] - '0';
				y+=num;
				num = 10 - num;
				card_available[top] = 0;
				while(num--){
					top--;
					card_available[top] = 0;
				}
			}
			top--;
			//printf("%d ",y);
		}
		if(y>top){
			printf("Case %d: %s\n",test_copy-test, cards[y-top+25]);
		}else{
			printf("Case %d: %s\n",test_copy-test, cards[y]);
		}
	}
	return 0;
}

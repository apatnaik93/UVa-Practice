#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	map<char, int> suit;
	suit['S'] = 0;
	suit['H'] = 1;
	suit['D'] = 2;
	suit['C'] = 3;
	char card[3];
	bool ace[4], king[4], queen[4], jack[4],stopped[4];
	int point,extra,card_count[4];
	
	while(scanf("%s",card) == 1){
		point=extra=0;
		for(int i=0;i<4;i++){
			ace[i]=king[i]=queen[i]=jack[i]=stopped[i]=false;
			card_count[i]=0;
		}
		
		for(int i=0; i<13; i++){
			if(i!=0){
				scanf("%s",card);	
			}
			
			int suit_selected = suit[card[1]];
			
			//printf("%d ",suit['H']);
			
			card_count[suit_selected]+=1;
			
			switch(card[0]){
				case 'A':
					ace[suit_selected] = true;
					point+=4;
					break;
					
				case 'K':
					king[suit_selected] = true;
					point += 3;
					break;
					
				case 'Q':
					queen[suit_selected] = true;
					point += 2;
					break;
					
				case 'J':
					jack[suit_selected] = true;
					point += 1;
					break;
			}
		}
		//printf("%d ",point);
		
		for(int i=0;i<4;i++){
			//printf("%d ",king[i]);
			if(ace[i]){
				//printf("%d ",i);
				stopped[i] = true;
			}
			if(king[i]){
				//printf("%d ",i);
				if(card_count[i] <= 1){
					point--;
				}else if(card_count[i] >= 2){
					stopped[i] = true;
				}
			}
			if(queen[i]){
				//printf("%d ",i);
				if(card_count[i] <= 2){
					point--;
				}else if(card_count[i] >= 3){
					stopped[i] = true;
				}
			}
			if(jack[i]){
				//printf("%d ",i);
				if(card_count[i] <= 3){
					point--;
				}
			}
			
			if(card_count[i] == 2){
				extra++;
			}
			
			if(card_count[i] <= 1){
				extra+=2;
			}
		}
		
		//printf("%d ",point);
		
		if(stopped[0] && stopped[1] && stopped[2] && stopped[3] && point>=16){
			printf("BID NO-TRUMP\n");
		}else if((point+extra)>=14){
			char start = 'S';
			int max = 0;
			for(int i=0; i<4; i++){
				if(card_count[i] > max){
					max = card_count[i];
					switch(i){
						case 0: start='S';break;
						case 1: start='H';break;
						case 2: start='D';break;
						case 3: start='C';break;
					}
				}
			}
			printf("BID %c\n",start);
		} else{
			printf("PASS\n");
		}
		
	}

	return 0;
}

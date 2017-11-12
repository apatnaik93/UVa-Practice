#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

bool inuse(int num, int b[], int s[]){
	for(int i=0;i<3;i++){
		if(s[i] == num){
			return true;
		}
	}
	for(int i=0;i<2;i++){
		if(b[i] == num){
			return true;
		}
	}
	return false;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int bro[2],sis[3];
	while(scanf("%d %d %d %d %d",&sis[0], &sis[1], &sis[2], &bro[0], &bro[1]),sis[0] || sis[1] || sis[2] || bro[0] || bro[1]){
		sort(sis,sis+3);
		sort(bro,bro+2);
		int lc =0;
		bool used[3]={false};
		for(int i=0;i<2;i++){
			for(int j=0;j<3;j++){
				if(sis[j]>bro[i] && !used[j]){
					lc++;
					used[j] = true;
					break;
				}
			}
		}
		
		int minbro = 0;
		
		if(lc == 2){
			printf("-1\n");
			continue;
		} else if(lc !=0 ) {
			for(int i=0;i<3;i++){
				if(!used[i]){
					minbro = sis[i];
				}
			}
		}
		
		minbro++;
		
		while(inuse(minbro,bro,sis)){
			minbro++;
		}
		
		if(minbro>52){
			printf("-1\n");
		}else{
			printf("%d\n",minbro);
		}
	}
	return 0;
}

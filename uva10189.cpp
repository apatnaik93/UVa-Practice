#include<iostream>
#include<cstdio>


using namespace std;

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int m,n,field = 0;
	while(scanf("%d %d",&m,&n)){
		if(m==0 && n==0){
			break;
		}
		field++;
		char mine[m+2][n+3];
		for(int i=0;i<m+2;i++){
			for(int j=0;j<n+3;j++){
				mine[i][j]='.';
			}
		}
		int mine_number[m][n];
		for(int i=0; i<m; i++){
			scanf("%s",&mine[i+1][1]);
		}
		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				mine_number[i][j] = 0;
				if(mine[i+1-1][j+1+1] == '*'){
					mine_number[i][j]++;
				}
				if(mine[i+1][j+1+1] == '*'){
					mine_number[i][j]++;
				}
				if(mine[i+1+1][j+1+1] == '*'){
					mine_number[i][j]++;
				}
				if(mine[i+1-1][j+1] == '*'){
					mine_number[i][j]++;
				}
				if(mine[i+1+1][j+1] == '*'){
					mine_number[i][j]++;
				}
				if(mine[i+1-1][j+1-1] == '*'){
					mine_number[i][j]++;
				}
				if(mine[i+1][j+1-1] == '*'){
					mine_number[i][j]++;
				}
				if(mine[i+1+1][j+1-1] == '*'){
					mine_number[i][j]++;
				}
			}
		}
		
		if(field == 1)
			printf("Field #%d:\n",field);
		else
			printf("\nField #%d:\n",field);
		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(mine[i+1][j+1] == '*'){
					printf("*");
				} else{
					printf("%d",mine_number[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}

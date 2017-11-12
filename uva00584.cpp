#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	char points[45];
	while(scanf("%[^\n]%*c",points),points[0]!='G'){
		//printf("%s\n",points);
		int point[24] = {0};
		int point_actual[24] = {0};
		for(int i=0,j=0;points[i]!='\0';i++){
			if(points[i] == 'X'){
				point[j] = 10;
				point_actual[j] = 1;
				point[++j] = 0;
				++j;
			} else if (points[i] == '/'){
				point[j] = 10 - point[j-1];
				point_actual[j] = 1;
				++j;
			} else if(points[i]>='0' && points[i]<='9'){
				point[j] = points[i] - '0';
				point_actual[j] = 1;
				++j;
			}
		}
		
//		for(int i=0;i<24;i++){
//			printf("%d ",point[i]);
//		}
//		printf("\n");
		
		int pts = 0;
		for(int i=0;i<20;i++){
			pts+= point[i];
		}
		
		//printf("%d\n",pts);
		
		for(int i=0;i<20;i+=2){
			if(point[i]+point[i+1] == 10 && point_actual[i] == 1 && point_actual[i+1] == 1){
				pts+= point[i+2];
			}
		}
		
		//printf("%d\n",pts);
		
		for(int i=0;i<20;i+=2){
			if(point[i] == 10){
				int cnt = 0, x=i+1;
				while(cnt<2){
					if(point_actual[x] == 1){
						pts+= point[x];
						cnt++;
						x++;
					}else{
						x++;
					}
				}
			}
		}
		printf("%d\n",pts);
	}
	return 0;
}

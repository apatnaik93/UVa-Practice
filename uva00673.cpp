#include <iostream>
#include<cstdio>

using namespace std;

int main(){
	int pages;
	while(scanf("%d",&pages), pages != 0){
		int total_pages;
		if(pages % 4 == 0){
			total_pages = pages/4;
		} else {
			total_pages = (pages/4) + 1;
		}
		printf("Printing order for %d pages:\n", pages);
		int end = total_pages * 4;
		int start = 1;
		for(int i=0; i<total_pages; i++){
			printf("Sheet %d, front: ",i+1);
			if(end > pages){
				printf("Blank, ");
				end--;
			}else{
				printf("%d, ",end--);
			}
			
			if(start > pages){
				printf("Blank\n");
				start++;
			}else{
				printf("%d\n",start++);
			}
			
			
			if(start-1 == pages)
				continue;
			
			printf("Sheet %d, back : ",i+1);
			
			if(start > pages){
				printf("Blank, ");
				start++;
			}else{
				printf("%d, ",start++);
			}
			
			if(end > pages){
				printf("Blank\n");
				end--;
			}else{
				printf("%d\n",end--);
			}
			
			
		}
	}
	return 0;
}

#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	float h,m;
	float ha,ma,diff;
	while(scanf("%f:%f",&h,&m)){
		if(h==0&&m==0){
			break;
		}
		ha = (30*h) + (m/2);
		ma = 6*m;
		if(ha>ma){
			diff = ha-ma;
		} else {
			diff = ma-ha;
		}
		
		if(diff>180){
			printf("%.3f\n",360-diff);
		}else{
			printf("%.3f\n",diff);
		}
	}
	
	return 0;
}

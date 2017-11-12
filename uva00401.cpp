#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>

using namespace std;

int main(){
	//("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	map<char,char> reverse;
	reverse['A'] = 'A';
	reverse['E'] = '3';
	reverse['H'] = 'H';
	reverse['I'] = 'I';
	reverse['J'] = 'L';
	reverse['L'] = 'J';
	reverse['M'] = 'M';
	reverse['O'] = 'O';
	reverse['S'] = '2';
	reverse['T'] = 'T';
	reverse['U'] = 'U';
	reverse['V'] = 'V';
	reverse['W'] = 'W';
	reverse['X'] = 'X';
	reverse['Y'] = 'Y';
	reverse['Z'] = '5';
	reverse['1'] = '1';
	reverse['2'] = 'S';
	reverse['3'] = 'E';
	reverse['5'] = 'Z';
	reverse['8'] = '8';
	char str[100];
	while(cin>>str){
		int pali = 1;
		int mir = 1;
		for(int i=0,j=strlen(str)-1;i<j;i++,j--){
			if(str[i] != str[j]){
				pali = 0;
				break;
			}
		}
		
		for(int i=0,j=strlen(str)-1;i<j;i++,j--){
			if(reverse[str[i]] != str[j]){
				mir = 0;
				break;
			}
		}
		
		if(strlen(str)%2 == 1){
			if(reverse[str[strlen(str)/2]] != str[strlen(str)/2]){
				mir = 0;
			}
		}
		
		if(pali == 0 && mir == 0){
			printf("%s -- is not a palindrome.\n",str);
		}else if(pali == 1 && mir == 0){
			printf("%s -- is a regular palindrome.\n",str);
		}else if(pali == 0 && mir == 1){
			printf("%s -- is a mirrored string.\n",str);
		}else if(pali == 1 && mir == 1){
			printf("%s -- is a mirrored palindrome.\n",str);
		}
		printf("\n");
	}
	return 0;
}

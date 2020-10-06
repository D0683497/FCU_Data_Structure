#include <stdio.h>

int main(){
	int table10[100]={0};
	
	for(int i=1; i<10; i++){
		for(int j=1; j<10; j++){
			table10[i*j]={i*j};
			printf("%d\t",table10[i*j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(int i=1; i<10; i++){
		for(int j=1; j<10; j++){
			printf("%o\t",table10[i*j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(int i=1; i<10; i++){
		for(int j=1; j<10; j++){
			printf("%x\t",table10[i*j]);
		}
		printf("\n");
	}
	
}

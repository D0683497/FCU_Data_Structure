#include <stdio.h>

int main(){

	printf("十進位\n");
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			printf("%3d ", i*j);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("八進位\n");
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			printf("%3o ", i*j);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("十六進位\n");
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			printf("%3x ", i*j);
		}
		printf("\n");
	}
	
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));
	char* word = (char*)malloc(sizeof(char)*20);
	int i, j;
	int n = 20;
	char temp;
	
	printf("原始字母:\n");
	for (i = 0; i < 20; i++) {
		word[i] = 'A' + (rand() % 26);
		printf("%3c", word[i]);
	}
	printf("\n");
	
	for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (word[i] > word[j]) {
            temp = word[i];
            word[i] = word[j];
            word[j] = temp;
         }
      }
   }
	
	printf("排序結果:\n");
	for (i = 0; i < 20; i++) {
		printf("%3c", word[i]);
	}
}


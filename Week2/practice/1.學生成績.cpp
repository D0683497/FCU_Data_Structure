#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct Student {
    char name[20];
    int a;
    int b;
    int c;
} stus;

void format_1() {
	srand(time(NULL));
	FILE *fp_r = fopen("name.txt", "r");
	char string[20];
	int num = 1;
	
	printf("學生姓名         號碼\n");
	printf("----------------------------");
	printf("\n");
	
	while (fscanf(fp_r, "%s", string)!=EOF) {
		printf("%-15s", string);
		printf("%5d\n", num);
		num++;
	}
	
	fclose(fp_r);
}

void format_2() {
	srand(time(NULL));
	FILE *fp_r = fopen("name.txt", "r");
	FILE *fp_w = fopen("student.txt", "w");
	char string[20];
	int num = 0;
	int random1, random2, i, j;
	int n = 50;
	stus stu[50];
	stus temp;
	
	while (fscanf(fp_r, "%s", string)!=EOF) {
		strcpy(stu[num].name, string);
		
		stu[num].a = (rand()%31)+70;
		stu[num].b = (rand()%31)+70;
		stu[num].c = (stu[num].a + stu[num].b) / 2;
		
		if (num == 49) {
			num = 1;
		} else {
			num++;
		}
	}
	
	fclose(fp_r);
	
	// 排序 
	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (stu[i].c == stu[j].c) {
				if (stu[i].a < stu[j].a) {
					temp = stu[i];
					stu[i] = stu[j];
					stu[j] = temp;
				}
			}
			else if (stu[i].c < stu[j].c) {
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}
	
	
	fprintf(fp_w, "學生姓名       計概成績 微積分成績 平均成績  名次\n");
	fprintf(fp_w, "----------------------------------------------------");
	fprintf(fp_w, "\n");
	for (num = 0; num < 50; num++) {
		fprintf(fp_w, "%-15s", stu[num].name);
		fprintf(fp_w, "%5d", stu[num].a);
		fprintf(fp_w, "%10d", stu[num].b);
		fprintf(fp_w, "%10d", stu[num].c);
		fprintf(fp_w, "%8d\n", num+1);
	}
	fclose(fp_w);
	
}

int main() {
	
	format_1();
	format_2();
	
	return 0;
}


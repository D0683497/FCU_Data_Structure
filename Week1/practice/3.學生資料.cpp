#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct stu{
	int name[3]={0};
	int itcf;
	int cf;
};

int main(){
	srand(time(NULL));
	
	struct stu a[25];
	
	int letter[26]={0};
	int name_reg=0;
	printf("學生姓名\t計概成績\t微積分成績\n------------------------------\n");
	for(int i=0;i<25;i++){
		while(1){
			name_reg=(rand()%26);
			if(letter[name_reg]==0){
				a[i].name[0]=name_reg+65;
				a[i].name[1]=name_reg+65;
				a[i].name[2]=name_reg+65;
				letter[name_reg]=1;
				break;
			}
		}
		a[i].cf=(rand()%60)+40;
		a[i].itcf=(rand()%60)+40;
		printf("%s\t%d\t%d\n",a[i].name,a[i].cf,a[i].itcf);
	}
	
	
}

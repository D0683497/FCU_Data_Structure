#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char string[6];
	
	printf("��J�r��:");
	scanf("%s", string);
	
	int len = strlen(string);
	int num, i;
	
	for (i = len; i > 0; i--)
	{
		if (i == len)
		{
			num = i;
		}
		else
		{
			num = i*num;
		}
	}
	
	printf("�r��%s��%d�زզX�r��:", string, num);
	
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char string[6];
	
	printf("輸入字串:");
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
	
	printf("字串%s有%d種組合字串:", string, num);
	
    return 0;
}

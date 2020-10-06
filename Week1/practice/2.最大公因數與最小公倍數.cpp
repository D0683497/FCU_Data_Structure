#include <stdio.h>

int division(int a, int b){	// a > b
	if (b == 0)
	{
		return a;
	}
	else
	{
		return division(b, a%b);
	}
}

int main(){
	
	int num1, num2, ans;
	
	while (1) {

		printf("輸入兩個數字 : ");
		scanf("%d %d", &num1, &num2);
		
		if (num1 == 0 && num2 == 0)
		{
			return 0;
		}
		else if (num1 > num2)
		{
			ans = division(num1, num2);
		}
		else
		{
			ans = division(num2, num1);
		}
		
		printf("最大公因數 : %d\n", ans);
		printf("最小公倍數 : %d\n", (num1 * num2) / ans);
	}
	
	
	return 0;
}


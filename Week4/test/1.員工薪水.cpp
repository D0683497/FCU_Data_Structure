#include<stdio.h>
#include<stdlib.h>

struct Staff {
	char name[15]; // 姓名 
	int a; // 平日工作時數
	int b; // 假日工作時數
};

int main()
{
	Staff s1, s2, s3;
	int s1w, s2w, s3w; // 每周總工作時數
	float s1s, s2s, s3s; // 每周薪水
	float s1m, s2m, s3m; // 每月薪水
	float s1a, s2a, s3a; // 所得稅額
	float s1d, s2d, s3d; // 實領薪水
	
	printf("請輸入第1位員工姓名: ");
	scanf("%s", s1.name);
	printf("請輸入平日工作時數: ");
	scanf("%d", &s1.a);
	printf("請輸入假日工作時數: ");
	scanf("%d", &s1.b);
	
	printf("請輸入第2位員工姓名: ");
	scanf("%s", s2.name);
	printf("請輸入平日工作時數: ");
	scanf("%d", &s2.a);
	printf("請輸入假日工作時數: ");
	scanf("%d", &s2.b);
	
	printf("請輸入第3位員工姓名: ");
	scanf("%s", s3.name);
	printf("請輸入平日工作時數: ");
	scanf("%d", &s3.a);
	printf("請輸入假日工作時數: ");
	scanf("%d", &s3.b);
	
	// 每周總工作時數 = 平日工作時數x5(天)+假日工作時數2(天)
	s1w = s1.a*5 + s1.b*2;
	s2w = s2.a*5 + s2.b*2;
	s3w = s3.a*5 + s3.b*2;
	
	// 每周薪水 = 平日工作時數x5(天)x平日時薪+假日工作時數2(天)x假日時薪
	s1s = s1.a*5*3.49 + s1.b*2*3.99;
	s2s = s2.a*5*3.49 + s2.b*2*3.99;
	s3s = s3.a*5*3.49 + s3.b*2*3.99;
	
	// 每月薪水 = 每周薪水x4(週)
	s1m = s1s * 4;
	s2m = s2s * 4;
	s3m = s3s * 4;
	
	// 所得稅額 = 每月薪水x7.5%
	s1a = s1m * 0.075;
	s2a = s2m * 0.075;
	s3a = s3m * 0.075;
	
	// 實領薪水 = 每月薪水 - 所得稅額
	s1d = s1m - s1a;
	s2d = s2m - s2a;
	s3d = s3m - s3a;
	
	printf("\n\n員工姓名 每周總工作時數 每周薪水 每月薪水 所得稅額 實領薪水\n");
	printf("======================================================================\n");
	printf("%-20s %d   %0.0f   %0.0f  %0.2f  %0.2f\n", s1.name, s1w, s1s, s1m, s1a, s1d);
	printf("%-20s %d   %0.0f   %0.0f  %0.2f  %0.2f\n", s2.name, s2w, s2s, s2m, s2a, s2d);
	printf("%-20s %d   %0.0f   %0.0f  %0.2f  %0.2f\n", s3.name, s3w, s3s, s3m, s3a, s3d);
	
    return 0;
}

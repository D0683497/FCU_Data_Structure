#include<stdio.h>
#include<stdlib.h>

struct Staff {
	char name[15]; // �m�W 
	int a; // ����u�@�ɼ�
	int b; // ����u�@�ɼ�
};

int main()
{
	Staff s1, s2, s3;
	int s1w, s2w, s3w; // �C�P�`�u�@�ɼ�
	float s1s, s2s, s3s; // �C�P�~��
	float s1m, s2m, s3m; // �C���~��
	float s1a, s2a, s3a; // �ұo�|�B
	float s1d, s2d, s3d; // ����~��
	
	printf("�п�J��1����u�m�W: ");
	scanf("%s", s1.name);
	printf("�п�J����u�@�ɼ�: ");
	scanf("%d", &s1.a);
	printf("�п�J����u�@�ɼ�: ");
	scanf("%d", &s1.b);
	
	printf("�п�J��2����u�m�W: ");
	scanf("%s", s2.name);
	printf("�п�J����u�@�ɼ�: ");
	scanf("%d", &s2.a);
	printf("�п�J����u�@�ɼ�: ");
	scanf("%d", &s2.b);
	
	printf("�п�J��3����u�m�W: ");
	scanf("%s", s3.name);
	printf("�п�J����u�@�ɼ�: ");
	scanf("%d", &s3.a);
	printf("�п�J����u�@�ɼ�: ");
	scanf("%d", &s3.b);
	
	// �C�P�`�u�@�ɼ� = ����u�@�ɼ�x5(��)+����u�@�ɼ�2(��)
	s1w = s1.a*5 + s1.b*2;
	s2w = s2.a*5 + s2.b*2;
	s3w = s3.a*5 + s3.b*2;
	
	// �C�P�~�� = ����u�@�ɼ�x5(��)x������~+����u�@�ɼ�2(��)x������~
	s1s = s1.a*5*3.49 + s1.b*2*3.99;
	s2s = s2.a*5*3.49 + s2.b*2*3.99;
	s3s = s3.a*5*3.49 + s3.b*2*3.99;
	
	// �C���~�� = �C�P�~��x4(�g)
	s1m = s1s * 4;
	s2m = s2s * 4;
	s3m = s3s * 4;
	
	// �ұo�|�B = �C���~��x7.5%
	s1a = s1m * 0.075;
	s2a = s2m * 0.075;
	s3a = s3m * 0.075;
	
	// ����~�� = �C���~�� - �ұo�|�B
	s1d = s1m - s1a;
	s2d = s2m - s2a;
	s3d = s3m - s3a;
	
	printf("\n\n���u�m�W �C�P�`�u�@�ɼ� �C�P�~�� �C���~�� �ұo�|�B ����~��\n");
	printf("======================================================================\n");
	printf("%-20s %d   %0.0f   %0.0f  %0.2f  %0.2f\n", s1.name, s1w, s1s, s1m, s1a, s1d);
	printf("%-20s %d   %0.0f   %0.0f  %0.2f  %0.2f\n", s2.name, s2w, s2s, s2m, s2a, s2d);
	printf("%-20s %d   %0.0f   %0.0f  %0.2f  %0.2f\n", s3.name, s3w, s3s, s3m, s3a, s3d);
	
    return 0;
}

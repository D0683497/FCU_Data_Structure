#include <stdio.h>

int division(int a,int b){	//a>b
	if(b==0){
		return a;
	}
	else{
		return division(b,a%b);
	}
	
}

int main(){
	
	int x=0;
	int y=0;
	
	while(1){
		printf("��J��ӼƦr :");
		scanf("%d %d",&x,&y);
		if(x==0 && y==0) return 0;
		
		int ans=0;
		
		if(x>y) ans=division(x,y);
		else ans=division(y,x);
		
		printf("�̤j���]�� : %d\n",ans);
		printf("�̤p������ :%d\n",(x*y)/ans);
	}
	
	
	
}


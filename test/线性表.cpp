#include<stdio.h>

void test(int &x,int &y){
	int z = x;
	x = y;
	y = z;
}

int main(){
	int x = 1;
	int y = 9;
	printf("����ǰx:%d;y:%d\n",x,y);
	test(x,y);
	printf("���ú�x:%d;y:%d\n",x,y); 
}

#include<stdio.h>

void test(int &x,int &y){
	int z = x;
	x = y;
	y = z;
}

int main(){
	int x = 1;
	int y = 9;
	printf("调用前x:%d;y:%d\n",x,y);
	test(x,y);
	printf("调用后x:%d;y:%d\n",x,y); 
}

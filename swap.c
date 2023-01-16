#include <stdio.h>
void swap(int x, int y);
void swap2(int *x, int *y);
void swap4(int **x, int **y);
void swap3(int *x, int *y);
int main(){
	int x=1, y=5;
	int *px, *py;
	px=&x;
	py=&y;
	printf("%d %d\n",x,y); // 1 5
	swap(x,y);
	printf("%d %d\n",x,y); // 1 5
	swap2(&x,&y);
	printf("%d %d\n",x,y); // 5 1
	swap3(px,py);
	printf("%d %d\n",*px,*py); // 5 1
	swap4(&px,&py);
	printf("%d %d\n",*px,*py); // 1 5
	
	return 0;
}
void swap3(int *x, int *y){
	int *t=x;
	x=y;
	y=t;
}

void swap4(int **x, int **y){
	int *t;
	t = *x;
	*x= *y;
	*y=t;
}

void swap(int x, int y){
	int t=x;
	x=y;
	y=t;
}
void swap2(int *x, int *y){
	int t=*x;
	*x=*y;
	*y=t;
}



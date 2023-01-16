#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int derece;
	double katsayi;
}TERIM;

typedef struct{
	TERIM *terimler;
	int terimsayisi;	
}POLINOM;
void polinomYaz(POLINOM p);
void polinomYazv2(const POLINOM *p);
void polinomOku(POLINOM p);
void polinomOkuv2(POLINOM *p);
void terimOku(TERIM t);

int main(){
	srand(time(NULL));
	int N;
	int i;
	TERIM tt[10];
	g(tt);
	TERIM t={4, 5.0};
	printf("%lf %d\n",t.katsayi,t.derece);
	terimOku(t);
	printf("%lf %d\n",t.katsayi,t.derece);
	
	POLINOM p1;
	printf("Terim sayisi giriniz"); scanf("%d",&N);
	p1.terimsayisi=N;
	p1.terimler = (TERIM*) malloc(p1.terimsayisi*sizeof(TERIM));
	
	//printf("%p %p",&p1,&p1.terimsayisi);
	polinomYaz(p1);
	polinomYazv2(&p1);
	
	polinomOku(p1);
	polinomYazv2(&p1);
	
	polinomOkuv2(&p1);
	polinomYazv2(&p1);
	
	f(p1->terimler);
	
}
void g(TERIM t[10]){
	
}

void f(TERIM *t){
	
}

void polinomYaz(POLINOM p){
	int i;
	//printf("\n%p %p",&p,&p.terimsayisi);
	for(i=0;i<p.terimsayisi-1;i++){
		printf("%2.1lf X ^ %d + ",p.terimler[i].katsayi, p.terimler[i].derece);
	}
	printf("%2.1lf X ^ %d\n",p.terimler[i].katsayi, p.terimler[i].derece);
}

void polinomYazv2(const POLINOM *p){
	int i;

	for(i=0;i<p->terimsayisi-1;i++){
		printf("%2.1lf X ^ %d + ",p->terimler[i].katsayi, p->terimler[i].derece);
	}
	printf("%2.1lf X ^ %d\n",p->terimler[i].katsayi, p->terimler[i].derece);
}

void polinomOku(POLINOM p){ // call by value
	int i;
	p.terimler=(TERIM*) malloc(p.terimsayisi*sizeof(TERIM));
	for(i=0;i<p.terimsayisi;i++){
		printf("%d. terimin katsayisi ve derecesi",i);
		scanf("%lf",&p.terimler[i].katsayi);
		scanf("%d",&p.terimler[i].derece);	
	}
	polinomYazv2(&p);
}

void polinomOkuv2(POLINOM *p){ // call by value
	int i;
	for(i=0;i<p->terimsayisi;i++){
		printf("%d. terimin katsayisi ve derecesi",i);
		scanf("%lf",&p->terimler[i].katsayi);
		scanf("%d",&p->terimler[i].derece);	
	}
	polinomYazv2(p);
}

void terimOku(TERIM t){
	printf("Katsayi ve derece giriniz");
	scanf("%lf %d",&t.katsayi,&t.derece);
	printf("%lf %d\n",t.katsayi,t.derece);
}

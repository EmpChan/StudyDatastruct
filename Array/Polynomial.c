#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#define MAXDEGREE 101 // 최대 차수는 100

typedef struct {
	double coef[MAXDEGREE];
	int maxdegree;
}Polynomial;

Polynomial* Zero() {
	Polynomial* a = (Polynomial*)calloc(sizeof(Polynomial), 1);
	return a;
}
// 완전히 빈 다항식 객체를 만듦 with calloc

Polynomial* NewPolynomial() {
	Polynomial* poly = Zero();
	int m, cup;
	printf("최대 차수를 입력해주세요 : ");
	scanf("%d", &m);
	poly->maxdegree = m;
	for (int i = 0; i < m; i++) {
		printf("x^%d : ", i);
		scanf("%d", poly->coef[i]);
	}
}
// 새로운 다항식 객체를 만듦

bool isZero(Polynomial poly) {
	for (int i = 0; i < poly.maxdegree; i++) {
		if (poly.coef[i] != 0)
			return 0;
	}
	return 1;
}
// 다항식이 비었는지 체크하는 함수 
int Coef(Polynomial poly, int expon) {
	return poly.coef[expon];
}
// 차수에 대한 계수 반환
int Lead_exp(Polynomial poly) {
	for (int i = poly.maxdegree; i >= 0; i--) {
		if (poly.coef[i]) // 계수가 0이아닌 가장큰 차수 
			return i;
	}
	return -1; //비었다는 것을 의미함
}

void Attach(Polynomial* poly, int coef, int expon) { // ADT와 다르게 반환하지않고 바로 값을 대입함
	if (poly->coef[expon]) {
		printf("이미 %d차수에는 항이 들어있습니다.\n", expon);
		return;
	}
	poly->coef[expon] = coef;
}
//새로운 항 추가 
void Remove(Polynomial* poly,int expon) {
	if (!poly->coef[expon]) { // 항이 존재하지 않는경우
		printf("%d차수에는 항이 존재하지 않습니다.\n", expon);
	}
	poly->coef[expon] = 0;
}
// 특정항을 삭제
void singleMult(Polynomial* poly, int coef, int expon) {
	if (isZero(*poly))return; // 이미 0 인 다항식에는 굳이 곱할필요가없음. 
	for (int i = poly->maxdegree; i >=0; i--) {
		poly->coef[i + expon] = poly->coef[i] * coef;
		poly->coef[i] = 0;
	}
	poly->maxdegree += expon;
}
// 해당 다항식에다가 계수가 coef고 차수가 expon인 (coef)x^(expon)을 곱해줌
Polynomial* Add(Polynomial poly1, Polynomial poly2) {
	Polynomial* a = Zero(); // 비어있는 새로운 Polynomial 생성
	for (int i = 0; i < MAXDEGREE; i++) {
		a->coef[i] = poly1.coef[i] + poly2.coef[i];
	}
	if (poly1.maxdegree > poly2.maxdegree) {
		a->maxdegree = poly1.maxdegree;
	}
	else {
		a->maxdegree = poly2.maxdegree;
	}
	return a;
}
// 두개의 다항식을 더한 후 새롭게 반환하는 함수 
Polynomial* Mult(Polynomial poly1, Polynomial poly2) {
	Polynomial* a = Zero();
	for (int i = 0; i < poly1.maxdegree; i++) {
		for (int j = 0; j < poly2.maxdegree; j++) {
			a->coef[i + j] = poly1.coef[i] * poly2.coef[j];
		}
	}
	a->maxdegree = poly1.maxdegree + poly2.maxdegree;
	return a;
}
//두개의 다항식을 곱하는 함수

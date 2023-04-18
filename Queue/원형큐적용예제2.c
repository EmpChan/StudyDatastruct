#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100

typedef char Element;

typedef struct Queue {
	Element data[MAX_QUEUE_SIZE][20];
	int front;
	int rear;
}Queue;

Queue boy[MAX_QUEUE_SIZE];
Queue girl[MAX_QUEUE_SIZE];

void error(char* str) {
	printf("%s\n", str);
	exit(1);
}

void init_queue(Queue* q) { q->front = q->rear = 0; }
int is_empty(Queue* q) { return q->front == q->rear; }
int is_full(Queue* q) { return q->front == (q->rear + 1) % MAX_QUEUE_SIZE; }
int size(Queue* q) { return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

Element* dequeue(Queue* q)
{
	if (is_empty(q))
		error(" 큐 공백 에러");
	q->front = (++q->front) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
Element* Mpeek(Queue* q)
{
	if (is_empty(q))
		error(" 큐 공백 에러");
	return q->data[(++q->front) % MAX_QUEUE_SIZE];
}
void enqueue(Element* val,Queue* q)
{
	if (is_full(q))
		error("큐 포화 에러");
	q->rear = (++q->rear) % MAX_QUEUE_SIZE;
	strcpy(q->data[q->rear], val);
}

void gethuman() {
	char name[10]={0};
	char gender;
	printf("  고객의 이름은?(종료는 -1) >> ");
	scanf("%s", name);
	getchar();
	if (!strcmp(name, "-1")) {
		printf("미팅 주선 프로그램을 종료합니다.\n");
		exit(1);
	}
	printf("  성별을 입력(남자는m 여자는f) >> ");
	scanf("%c", &gender);
	if (gender == 'm') {
		enqueue(name,boy);
	}
	else if (gender == 'f') {
		enqueue(name, girl);
	}
	else {
		printf("    잘못된 입력입니다.\n");
		return;
	}
	if (is_empty(boy) || is_empty(girl)) {
		printf("    아직 대상자가 없습니다.\n");
	}
	else {
		printf("    커플 탄생 : %s 와(과) %s\n", dequeue(boy), dequeue(girl));
	}
}

int main() {
	printf("미팅 주선 프로그램입니다.\n");

	while (1) {
		gethuman();
	}
	printf("미팅 주선 프로그램을 종료합니다.\n");
	return 0;
}

#include <stdio.h>
#include <malloc.h> // 동적할당을 위한 malloc 라이브러리
#include <stdbool.h> // bool 자료형을 위한 stdbool 라이브러리

typedef struct {
	int* s;
	int len;
	int maxsize;
}stack;
// 스택 스트럭트 생성 
stack* creates(int maxstacksize) {
	stack* a = (stack*)malloc(sizeof(stack));;
	a->s = (int*)malloc(sizeof(int) * maxstacksize);
	a->len = 0;
	a->maxsize = maxstacksize;
	return a;
}// 스택 생성 maxsize 만큼 크기로 만듦

bool isfull(stack a, int maxstacksize) {
	if (a.len == maxstacksize)
		return 1;
	else
		return 0;
}//스택이 가득찼는지 확인하는 함수 

bool isempty(stack a) {
	if (a.len == 0)
		return 1;
	else
		return 0;
}// 스택이 비었는지 확인하는 함수 

void push(stack* a, int item) {
	if (isfull(*a, a->maxsize)) {
		printf("The stack is full\n");
		return;
	}
	a->s[a->len++] = item;
} // 스택에 item을 푸쉬하는 함수 

int pop(stack* a) {
	if (isempty(*a)) {
		printf("The stack is empty\n");
		return -1;
	}
	return a->s[--a->len];
} // 스택에서 pop을 한 후 pop한 item을 가져오는 함수 

int main() {
	stack* s = creates(1); // 기본적으로 사이즈1짜리 스택을 만들어줌 
	int size,cup;
	while (1) { // 스택 테스트 코드 
		int ans;
		printf("-----MENU------\n 1. Create Stack\n 2. push On Stack\n 3. Pop from stack\n 4. End the program\n");
		scanf("%d", &ans);
		if (ans == 1) {
			printf("Create New Stack, How much big is that stack? : ");
			scanf("%d", &size);
			s = creates(size);
			printf("Success.\n");
		}
		else if (ans == 2) {
			printf("Push the new item on stack. What is the item? : ");
			scanf("%d", &cup);
			push(s, cup);
		}
		else if (ans == 3) {
			cup = pop(s);
			if (cup != -1) {
				printf("The result of pop from stack : %d\n", cup);
			}
		}
		else if (ans == 4) {
			printf("End the program\n\n");
			return 0;
		}
		else {
			printf("You answered the wrong number. Plz re-check your answer\n");
		}
	}

	return 0;
}

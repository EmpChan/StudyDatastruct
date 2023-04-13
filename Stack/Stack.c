#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct {
	int* s;
	int len;
	int maxsize;
}stack;

stack* creates(int maxstacksize) {
	stack* a = (stack*)malloc(sizeof(stack));;
	a->s = (int*)malloc(sizeof(int) * maxstacksize);
	a->len = 0;
	a->maxsize = maxstacksize;
	return a;
}

bool isfull(stack a, int maxstacksize) {
	if (a.len == maxstacksize)
		return 1;
	else
		return 0;
}

bool isempty(stack a) {
	if (a.len == 0)
		return 1;
	else
		return 0;
}

void push(stack* a, int item) {
	if (isfull(*a, a->maxsize)) {
		printf("The stack is full\n");
		return;
	}
	a->s[a->len++] = item;
}

int pop(stack* a) {
	if (isempty(*a)) {
		printf("The stack is empty\n");
		return -1;
	}
	return a->s[--a->len];
}

int main() {
	stack* s = creates(1);
	int size,cup;
	while (1) {
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

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct {
	int* items;
	int s, e;
	int maxsize;
}queue;

queue* createq(int maxqueuesize) {
	queue* q = (queue*)malloc(sizeof(queue));
	q->s = 0, q->e = 0;
	q->maxsize = maxqueuesize;
	q->items = (int*)malloc(sizeof(int) * q->maxsize);
	return q;
}

bool isfull(queue* que) {
	if (que->e - que->s == que->maxsize)
		return 1;
	else
		return 0;
}

bool isempty(queue* que) {
	if (!(que->e - que->s))
		return 1;
	else
		return 0;
}

void push(queue* que, int item) {
	if (isfull(que)) {
		printf("The queue is Full.\n");
		return;
	}
	que->items[(que->e++)%(que->maxsize)] = item;
	printf("%d %d\n", que->s, que->e);
}

int pop(queue* que) {
	if (isempty(que)) {
		printf("The queue is Empty.\n");
		return -1;
	}
	return que->items[(que->s++) % (que->maxsize)];
}

int main(void) {
	queue* q = createq(1);
	int size, cup;
	while (1) {
		int ans;
		printf("-----MENU------\n 1. Create Queue\n 2. push on queue\n 3. Pop from queue\n 4. End the program\n");
		scanf("%d", &ans);
		if (ans == 1) {
			printf("Create New Queue, How much big is that stack? : ");
			scanf("%d", &size);
			q = createq(size);
			printf("Success.\n");
		}
		else if (ans == 2) {
			printf("Push the new item on queue. What is the item? : ");
			scanf("%d", &cup);
			push(q, cup);
		}
		else if (ans == 3) {
			cup = pop(q);
			if (cup != -1) {
				printf("The result of pop from queue : %d\n", cup);
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

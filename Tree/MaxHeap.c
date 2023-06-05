#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//priority_queue

int priority_queue[1000001];//0번은 개수체크

void push(int v) {
    priority_queue[++priority_queue[0]] = v;
    int i = priority_queue[0],tmp=0;
    while(i > 1) {
        if (priority_queue[i] > priority_queue[i / 2]) {
            tmp = priority_queue[i];
            priority_queue[i] = priority_queue[i / 2];
            priority_queue[i / 2] = tmp;
            i /= 2;
        }
        else break;
    }
}

int pop() {
    if (priority_queue[0]<=0)return -1;//값이 존재하지 않스무니다. 
    int tmp,i=priority_queue[0],val = priority_queue[1];
    tmp = val;
    priority_queue[1] = priority_queue[i];
    priority_queue[i] = tmp;
    priority_queue[0]--;
    i = 1;
    while (1) {
        if (priority_queue[i * 2] >= priority_queue[i * 2 + 1]) {//왼쪽이 더 크네요
            if (priority_queue[i * 2] <= priority_queue[i] || i*2 > priority_queue[0])break;
            else {
                tmp = priority_queue[i];
                priority_queue[i] = priority_queue[i * 2];
                priority_queue[i * 2] = tmp;
                i *= 2;
            }
        }
        else {
            if (priority_queue[i * 2 + 1] <= priority_queue[i] || i * 2 + 1 > priority_queue[0])break;
            else {
                tmp = priority_queue[i];
                priority_queue[i] = priority_queue[i * 2 + 1];
                priority_queue[i * 2 + 1] = tmp;
                i = i * 2 + 1;
            }
        }
    }
    return val;
}

int main(void) {
    int n, m;
    while (1) {
        printf("1. Push\n2. Pop\n");
        scanf("%d" ,& n);
        if (n == 1) {
            scanf("%d", &m);
            push(m);
        }
        else if (n == 2) {
            printf("%d\n", pop());
        }
        else {
            break;
        }
    }
    return 0;
}

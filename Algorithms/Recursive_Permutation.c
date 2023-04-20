#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char arr[5] = { 'a','b','c','d','e' };
char tmp[5];

void printseq(int i, int l) {
	if (i == l) {
		for (int p = 0; p < 5; p++) {
			printf("%c", tmp[p]);
		}
		printf("\n");
	}
	else {
		for (int p = 0; p < 5; p++) { 
			int flag = 0;
			for (int q = 0; q < i; q++) { // tmp < - 출력용이라 문자열 넣어둠 
				if (tmp[q] == arr[p]) {
					flag = 1; // 문자열이 이미 tmp안에 들어있는 문자열인경우 
					break;
				}
			}
			if (flag) continue; // 다시 돌려  문자열이 겹치지 않도록 
			else {
				tmp[i] = arr[p];
				printseq(i + 1, l); 
			}
		}
	}
}

int main() {
	int l = 5;
	printseq(0, 2);

	return 0;
}

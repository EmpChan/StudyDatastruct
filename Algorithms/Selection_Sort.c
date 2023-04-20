#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void selection_sort(int arr[]) {
	for (int i = 0; i < 9; i++) {
		int p = i;
		for (int j = i+1; j < 9; j++) {
			if (arr[j] < arr[i])
				p = j;
		}
		int cup = arr[p]; // swap
		arr[p] = arr[i];
		arr[i] = cup;
	}
}

int main() {
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	selection_sort(arr);
	for (int i = 0; i < 9; i++) printf("%d ", arr[i]);
	return 0;
}

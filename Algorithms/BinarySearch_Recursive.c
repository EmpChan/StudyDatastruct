#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int BinarySearch(int arr[], int low,int high, int key) {
	if (low > high) return -1; 
	int mid = (low + high) / 2;
	if (arr[mid] == key) return mid;
	if (arr[mid] > key) return BinarySearch(arr, low, mid - 1, key);
	if (arr[mid] < key) return BinarySearch(arr, mid + 1, high, key);
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int key = 7;
	printf("%d ", BinarySearch(arr, 0, 8, key));
	return 0;
}

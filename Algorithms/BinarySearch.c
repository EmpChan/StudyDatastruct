#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int BinarySearch(int arr[], int n, int key) {
	int low = 0, high = n - 1;
	int mid = (low + high) / 2;
	while (low <= high) {
		if (arr[mid] == key)
			return mid; // key값을 찾았으므로 위치 반환
		if (arr[mid] > key) high = mid - 1;
		else if (arr[mid] < key) low = mid + 1;
		mid = (low + high) / 2;
	}
	return -1; // key값이 배열에 존재하지 않는다. 
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int key = 7;
	printf("%d ", BinarySearch(arr, 9, key));
	return 0;
}

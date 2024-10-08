#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_SIZE 100
#define MAX_STR_SIZE 255

void custom_swap(int* a, int* b) {
	double temp = *a;
	*a = *b;
	*b = temp;
}

void ShakerSort(int* arr, unsigned int size) {
	unsigned int n = size;
	unsigned int start = 0;
	unsigned int end = n;
	end -= 1;
	bool swapped;
	unsigned int i = start;
	unsigned int j = end;
	int* tmpi;
cycle_start:
	if (n <= 0) return;
	swapped = false;

	i = start;
cycle1_start:
	if (i >= end) goto cycle1_end;
	if (arr[i] > arr[i + 1]) {
		tmpi = arr;
		tmpi += i;
		custom_swap(tmpi, tmpi + 1);
		swapped = true;
	}
	i += 1;
	goto cycle1_start;

cycle1_end:
	if (swapped == false) return;
	end -= 1;
	n -= 1;
	if (n <= 0) return;

	j = end;
cycle2_start:
	if (j <= start) goto cycle2_end;
	if (arr[j] < arr[j - 1]) {
		tmpi = arr;
		tmpi += j;
		custom_swap(tmpi, tmpi - 1);
		swapped = true;
	}
	j -= 1;
	goto cycle2_start;
cycle2_end:
	start += 1;
	n -= 1;
	if (swapped == false) return;
	goto cycle_start;
}

unsigned int getLen(char* str) {
	unsigned int i = 0;
cycle_start:
	if (*(str + i) == '\0') return i;
	i += 1;
	goto cycle_start;
}

bool IsNumber(char* str, unsigned int len) {
	const char numbersAndDot[12] = { '-', '.', '0','1','2','3','4','5','6','7','8','9' };
	bool isNum = false;

	unsigned int i = 0;
	unsigned int j = 0;
cycle_start:
	if (i >= len) goto cycle_end;
	isNum = false;

	j = 0;
	cycle1_start:
		if (j >= 12) goto cycle1_end;
		if (*(str + i) != *(numbersAndDot + j))
		{
			j += 1;
			goto cycle1_start;
		}
		isNum = true;

	cycle1_end:
		if (!isNum) goto if_else;
			i += 1;
			goto cycle_start;
		if_else:
			return false;

cycle_end:
	return true;
}

void printArr(int* arr, unsigned int size) {
	printf("[");

	unsigned int i = 0;
cycle_start:
	if (i >= size) goto cycle_end;
	printf("%i; ", *(arr + i));
	i += 1;
	goto cycle_start;

cycle_end:
	printf("]");
}

int main() {

	printf("Enter an array of numbers using Enter.\nTo finish typing, enter /\n");
	int arr[MAX_NUM_SIZE];
	unsigned int len = 0;
	printf("\nEnter array length\n");
	scanf("%u", &len);

	unsigned int strLen = 0;
	int i = 0;
cycle_start:
	if (i >= len) goto cycle_end;
	char val[MAX_STR_SIZE];
	scanf("%s", val);
	strLen = getLen(val);

	if (*val != '/') goto if_else;
	goto cycle_end;

if_else:
	if(!IsNumber(val, strLen)) goto if_end;
	*(arr + i) = atoi(val);
	i += 1;
	goto cycle_start;

if_end:
	printf("You entered a string, not a number.\nEnter an array of numbers using Enter.\nTo finish typing, enter /\n");
	i -= 1;
	goto cycle_start;

cycle_end:

	ShakerSort(arr, len);
	printArr(arr, len);

	return 0;
}
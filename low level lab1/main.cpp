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
	size_t n = size;
	size_t start = 0;
	size_t end = n - 1;
	bool swapped;
	while (n > 0) {
		swapped = false;
		for (size_t i = start; i < end; ++i) {
			if (arr[i] > arr[i + 1]) {
				custom_swap((arr + i), (arr + i + 1));
				swapped = true;
			}
		}
		if (swapped == false) break;
		end--;
		n--;
		if (n <= 0) break;
		for (size_t i = end; i > start; --i) {
			if (arr[i] < arr[i - 1]) {
				custom_swap((arr + i), (arr + i - 1));
				swapped = true;
			}
		}
		start++;
		n--;
		if (swapped == false) break;
	}
}

unsigned int getLen(char* str) {
	unsigned int i;
	for (i = 0; *(str + i) != '\0'; i++) {}
	return i;
}

bool IsNumber(char* str, unsigned int len) {
	const char numbersAndDot[11] = { '.','0','1','2','3','4','5','6','7','8','9' };
	bool isNum = false;
	for (unsigned int i = 0; i < len; i++)
	{
		isNum = false;
		for (unsigned int j = 0; j < 11; ++j) {
			if (*(str + i) == *(numbersAndDot + j)) 
			{	isNum = true; break; }
		}
		if (isNum) continue;
		else return false;
	}
	return true;
}

void printArr(int* arr, unsigned int size) {
	printf("[");
	for (size_t i = 0; i < size; i++)
	{
		printf("%i; ", *(arr + i));
	}
	printf("]");
}

int main() {

	printf("Enter an array of numbers using Enter.\nTo finish typing, enter /\n");
	int arr[MAX_NUM_SIZE];
	unsigned int len = 0;
	printf("\nEnter array length\n");
	scanf("%u", &len);
	for (size_t i = 0; i < len; i++)
	{
		char val[MAX_STR_SIZE];
		unsigned int strLen = 0;
		scanf("%s", val);
		strLen = getLen(val);

		if (*val == '/') { break; }
		else if (IsNumber(val, strLen));
		else
		{
			printf("You entered a string, not a number.\nEnter an array of numbers using Enter.\nTo finish typing, enter /\n");
			continue;
		}

		*(arr + i) = atoi(val);
	}

	ShakerSort(arr, len);
	printArr(arr, len);

	return 0;
}
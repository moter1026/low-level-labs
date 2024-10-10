#include <stdio.h>
#include <stdlib.h>


int arr[100];
unsigned int len = 0;
unsigned int strLen = 0;
char val[255];
const char numbersAndDot[12] = { '-', '.', '0','1','2','3','4','5','6','7','8','9' };
bool isNum = false;
unsigned int n;
unsigned int start;
unsigned int end;
bool swapped;
int* tmpi;
int temp;

int main() {

	printf("Enter an array of numbers using Enter.\nTo finish typing, enter /\n");
	printf("\nEnter array length\n");
	scanf("%u", &len);

	int i = 0;
	int j = 0;
	int k = 0;
cycle_start:
	if (i >= len) goto cycle_end;
	scanf("%s", val);
	//strLen = getLen(val);
	strLen = 0;
	//unsigned int i = 0;
cycle_len_start:
	if (*(val + j) == '\0') goto cycle_len_end;
	j += 1;
	goto cycle_len_start;
cycle_len_end:

	if (*val != '/') goto if_else;
	goto cycle_end;

if_else:


	j = 0;
	k = 0;
cycle_num_start:
	if (k >= len) goto cycle_num_end;
	isNum = false;

	j = 0;
cycle1_num_start:
	if (j >= 12) goto cycle1_num_end;
	if (*(val + k) != *(numbersAndDot + j))
	{
		j += 1;
		goto cycle1_num_start;
	}
	isNum = true;

cycle1_num_end:
	if (!isNum) goto if_num_else;
	k += 1;
	goto cycle_num_start;
if_num_else:
	isNum = false;

cycle_num_end:
	isNum = true;


	if(!isNum) goto if_end;
	*(arr + i) = atoi(val);
	i += 1;
	goto cycle_start;

if_end:
	printf("You entered a string, not a number.\nEnter an array of numbers using Enter.\nTo finish typing, enter /\n");
	i -= 1;
	goto cycle_start;

cycle_end:

	//ShakerSort(arr, len);
	n = len;
	start = 0;
	end = n;
	end -= 1;
	i = start;
	j = end;
	
cycle_shaker_start:
	if (n <= 0) goto cycle_shaker_end;
	swapped = false;

	i = start;
cycle1_shaker_start:
	if (i >= end) goto cycle1_shaker_end;
	if (arr[i] > arr[i + 1]) {
		tmpi = arr;
		tmpi += i;
		temp = *tmpi;
		*tmpi = *(tmpi + 1);
		*(tmpi + 1) = temp;
		//custom_swap(tmpi, tmpi + 1);
		swapped = true;
	}
	i += 1;
	goto cycle1_shaker_start;

cycle1_shaker_end:
	if (swapped == false) goto cycle_shaker_end;
	end -= 1;
	n -= 1;
	if (n <= 0) goto cycle_shaker_end;

	j = end;
cycle2_shaker_start:
	if (j <= start) goto cycle2_shaker_end;
	if (arr[j] < arr[j - 1]) {
		tmpi = arr;
		tmpi += j;
		temp = *tmpi;
		*tmpi = *(tmpi - 1);
		*(tmpi - 1) = temp;
		//custom_swap(tmpi, tmpi - 1);
		swapped = true;
	}
	j -= 1;
	goto cycle2_shaker_start;
cycle2_shaker_end:
	start += 1;
	n -= 1;
	if (swapped == false) goto cycle_shaker_end;
	goto cycle_shaker_start;
cycle_shaker_end:


	//printArr(arr, len);
	printf("[");
	i = 0;
cycle_print_start:
	if (i >= len) goto cycle_print_end;
	printf("%i; ", *(arr + i));
	i += 1;
	goto cycle_print_start;

cycle_print_end:
	printf("]");
	return 0;
}
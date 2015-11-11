/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
int search(int *arr, int len,int key){
	int i;
	for (i = 0; i < len; i++){
		if (arr[i] == key)
			return 0;
	}
	return 1;
}

void * removeArrayDuplicates(int *Arr, int len)
{
	int i=1, j,flag=0;
	if (Arr == NULL || len < 0)
		return NULL;
	for (j = 1; j < len; j++){
		flag = search(Arr, i,Arr[j]);
		if (flag){
			Arr[i++] = Arr[j];
		}
	}
}
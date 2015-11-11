/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>
int binarySearch1(int *arr, int low, int high, int key){
	int mid, i;
	if (high>low){
		mid = (low + high) / 2;
		if (arr[mid] == key)
			return mid;
		else if (key < arr[mid])
			return binarySearch1(arr, low, mid - 1, key);
		else
			return binarySearch1(arr, mid + 1, high, key);
	}
	else
		return low;
}
int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int pos,temp1,temp2,i;
	if (Arr==NULL||len < 1)
		return NULL;
	Arr = (int *)realloc(Arr, (len + 1)*sizeof(int));
	pos = binarySearch1(Arr, 0, len - 1, num);
	if (pos != 0)
		pos = pos + 1;
	temp1 = Arr[pos];
	Arr[pos] = num;
	for (i = pos+1; i < len-1; i++){
		temp2 = Arr[i];
		Arr[i] = temp1;
		temp1 = temp2;
	}
	return Arr;
}
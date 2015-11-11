/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i,pos1=-1,pos2=-1;
	for (i = 0; i < len-1; i++){
		if (Arr[i]>Arr[i + 1]){
			pos1 = i;
			break;
		}

	}
	for (i = pos1 + 1; i < len - 1; i++){
		if (Arr[i]>Arr[i + 1]){
			pos2 = i+1;
		}
	}
	if (pos1 < 0 || pos2 < 0)
		return NULL;
	i = Arr[pos1];
	Arr[pos1] = Arr[pos2];
	Arr[pos2] = i;
	return Arr;
}
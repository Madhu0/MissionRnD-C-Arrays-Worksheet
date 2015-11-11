/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};
void strcpy(char *a, char *b){
	int i;
	for (i = 0; i < 10; i++)
		a[i] = b[i];
}
void quicksort(struct student *arr, int low,int high){
	int pivot, i, j;
	struct student temp;
	if (low < high){
		pivot = low;
		i = low;
		j = high;
		while (i < j){
			while (arr[i].score >= arr[pivot].score)
				i++;
			while (arr[j].score<arr[pivot].score)
				j--;
			if (i < j){
				strcpy(temp.name, arr[i].name);
				strcpy(arr[i].name, arr[j].name);
				strcpy(arr[j].name, temp.name);
				temp.score = arr[i].score;
				arr[i].score = arr[j].score;
				arr[j].score = temp.score;
			}
		}
		strcpy(temp.name, arr[pivot].name);
		strcpy(arr[pivot].name, arr[j].name);
		strcpy(arr[j].name, temp.name);
		temp.score = arr[pivot].score;
		arr[pivot].score = arr[j].score;
		arr[j].score = temp.score;
		quicksort(arr, low, j - 1);
		quicksort(arr, j + 1, high);
	}
}
void * scoresDescendingSort(struct student *students, int len) {
	int i;
	if (students == NULL||len<0)
		return NULL;
	for (i = 0; i < len; i++){
		if (students[i].score < 0)
			return NULL;
	}
	quicksort(students, 0, len - 1);
	return students;
}
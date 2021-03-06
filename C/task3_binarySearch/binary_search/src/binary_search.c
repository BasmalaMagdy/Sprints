/*
 ============================================================================
 Name        : binary_search.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define size 8

void swap(int *xp, int *yp);
void selectionSort(int arr[], int n);
int binarySearch();

int arr[size] = {10,2,5,7,6,12,1,20};

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int x = 30;
	selectionSort(arr , size);
	int result = binarySearch(arr , 0 , size - 1 , x);

	if(result == -1)
	{
		printf("not found");
	}
	else
	{
		printf("found");
	}

	return 0;
}


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

int binarySearch(int arr[], int l, int r, int x)
{

	if (r >= l) {
	        int mid = l + (r - l) / 2;

	        if (arr[mid] == x)
	            return mid;

	        if (arr[mid] > x)
	            return binarySearch(arr, l, mid - 1, x);

	        return binarySearch(arr, mid + 1, r, x);
	    }

	    return -1;
}

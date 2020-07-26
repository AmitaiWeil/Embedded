/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief manipulations on statistics data.
 * implemetion of sorting an array by descending order, 
 * finally printing the results.
 *
 * @author Amitai Weil
 * @date 26/07/2020
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
													114, 88,   45,  76, 123,  87,  25,  23,
													200, 122, 150, 90,   92,  87, 177, 244,
													201,   6,  12,  60,   8,   2,   5,  67,
													7,  87, 250, 230,  99,   3, 100,  90};
  /* Other Variable Declarations Go Here */
  int maximum, minimum, average, median;
  
  /* Statistics and Printing Functions Go Here */
  sort_array(test);
  maximum = find_maximum(test);
  minimum = find_minimum(test);
  average = find_mean(test);
  median = find_median(test);
  
  print_array(test);
  print_statistics(minimum, maximum, average, median);
  return;
}

// Given an array of data and a length, returns the median value
unsigned char find_median(unsigned char *arr)
{
		unsigned char median_rest;
		
		if (SIZE % 2)		// even
		{
		median_rest = (arr[SIZE / 2] + arr[(SIZE / 2) + 1] )/ 2;	// average of both middle numbers in the array
		}
		else
		{
			median_rest = arr[(SIZE / 2) + 1];
		}
		
		return median_rest;
} 		

// Given an array of data and a length, returns the mean
unsigned char find_mean(unsigned char *arr)
{
	int aver = 0;
	
	for(int i = 0; i < SIZE; i++)
	{
		printf("\n%d\n", aver);
		aver+= arr[i];
	}
	
	
	aver/= SIZE;
	
	return aver;
}

// - Given an array of data and a length, returns the minimum	
unsigned char find_minimum(unsigned char *arr) 		
{
	unsigned char min = arr[0];
	
	for(int i = 0; i < SIZE; i++)
	{
			min = (arr[i] < min) ? arr[i] : min;
	}
	
	return min;
	
}
// Given an array of data and a length, returns the maximum
unsigned char find_maximum(unsigned char *arr)
{
	unsigned char max = 0;
	
	for(int i = 0; i < SIZE; i++)
	{
			max = (arr[i] > max) ? arr[i] : max;
	}
	
	return max;
}

// Given an array of data and a length, prints the array to the screen
void print_array(unsigned char *arr)
{
	printf("The sorted array is:\n"); 
	
	for(int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}   			

// A function that prints the statistics of an array including minimum, maximum, mean, and median.
void print_statistics(int min, int max, int aver, int med)
{
	printf("maximum = %d\nminimum = %d\nmean =  %d\nmedian = %d\n", max, min, aver, med);
}

// Given an array of data and a length, sorts the array from largest to smallest
void sort_array(unsigned char *arr) 
{
	unsigned char temp_arr[SIZE];
	memset(temp_arr, 0, SIZE);

	int i = 0, j, k, counter = 0;

	temp_arr[0] = arr[0];

	for (i = 1; i < SIZE; i++)	// loop through original array
	{
		j = 0;
		while ((arr[i] < temp_arr[j]) & (temp_arr[j] > 0 )) // assuming there are no zeros in the original array, only positive numbers
		{
			j++;
		}
		if (temp_arr[j] > 0)
		{
            for (k = counter; k > j - 1; k--)
            {
                temp_arr[k + 1] = temp_arr[k];
            }
		}
		temp_arr[j] = arr[i];
		counter++;
	}

	for(i = 0; i < SIZE; i++)
	{
        arr[i] = temp_arr[i];
	}
}

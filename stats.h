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
 * @file stats.h
 * @brief manipulations on statistics data
 *
 * implemetion of sorting an array by descending order, 
 * finally printing the results.
 
 * @author Amitai Weil
 * @date 26/7/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
void sort_array(unsigned char *arr) ;
/**
 * @brief sorting given array in ascending order
 * @param arr - the original array
 * @return none, sorting done on the original
 */
void print_array(unsigned char *arr);
/**
 * @brief printint the ascending array
 * @param arr - the ascending array
 * @return none
 */
unsigned char find_maximum(unsigned char *arr);
/**
 * @brief finding the maxmial value in the array
 * @param arr - the array
 * @return maximal value
 */
unsigned char find_minimum(unsigned char *arr);
/**
 * @brief finding the minimal value in the array
 * @param arr - the array
 * @return result of minimal value
 */
unsigned char find_mean(unsigned char *arr);
/**
 * @brief finding the average of the array
 * @param arr - the array
 * @return the average result
 */
unsigned char find_median(unsigned char *arr);
/**
 * @brief finding the median of the given array
 * @param arr - the array
 * @return the median of the array
 */
void print_statistics(int min, int max, int aver, int med);
/**
 * @brief print to screen the statistical restults
 * @param min, max, aver, med - each of the tests - average, minimal, maximal and median
 * @return none
 */
 
#endif /* __STATS_H__ */

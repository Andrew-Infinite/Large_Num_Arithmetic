#include "stdlib.h"
#include "_uintd.h"


/**
 * This function convert string input into bitmap encoding. 
 * 
 * The func have zero error handling, it assume memory allocation is valid and sufficient for nbr->value. 
 * The value for nbr->size is also updated to be the correct value before running this function.
 * The str input is also assume to be valid with only positive numbers, and the nbr->num_digits is also
 * updated before calling.
 * 
 * @param nbr       The struct which hold the value in bitmap encoding.
 * @param str       Number as a string, assume only 0~9,
 * 
 */
void atoi_algorithm(uintd *nbr, char *str)
{
	unsigned int i = nbr->size;
	unsigned int j;
	int limit;
	unsigned str_size = nbr->num_digits;

	while(*str && --i >= 0)
	{
		j = -1;
		nbr->value[i] = 0;
		limit = str_size % MAX_UINT_DIGIT + (str_size % MAX_UINT_DIGIT == 0) * MAX_UINT_DIGIT;
		str_size -= limit;
		while(++j < limit)
		{
			nbr->value[i] = nbr->value[i] * 10 + *str - '0';
			str++;
		}
	}
}


/**
 * This function convert the number from bitmap encoding to string.
 * 
 * The func have zero error handling, it assume memory allocation is valid and sufficient for nbr->str.
 *
 * @param nbr       A struct which hold the bitmap encoding of the number.
 * 
 */

void itoa_algorithm(uintd *nbr)
{
	int j;
	unsigned int size_output = nbr->num_digits;

	nbr->str[size_output] = '\0';

	for(int i = 0; i < nbr->size; i++)
	{
		j = 0;
		//least significant number first
		//eg. num = 5648, output->str: 8 -> 48 -> 648 -> 5648 
		for(unsigned int num = nbr->value[i]; num > 0; num/=10)
		{
			nbr->str[--size_output] = (num % 10) + '0';
			j++;
		}
		//fill_zero
		//eg. Max_UINT_DIGIT = 3, output->str: 1|001|020|000|101 instead of 1|1|20|0|101
		while(size_output > 0 && j < MAX_UINT_DIGIT)
		{
			nbr->str[--size_output] = '0';
			j++;
		}
	}
}

void multiply(uintd *nbr1, uintd *nbr2)
{
	unsigned size = nbr1->size + nbr2->size;
	unsigned int *output = (unsigned int *)malloc(size * sizeof(unsigned int));
	unsigned int carry = 0;
	for(int i = 0;i<size;i++)
	{
		output[i] = 0;
	}

	for(int i = 0; i < nbr2->size;i++)
	{
		for(int j = 0;j < nbr1->size;j++)
		{
			unsigned long long temp = (unsigned long long)nbr1->value[j] * nbr2->value[i] + output[i+j] + carry;
			output[i+j] = (unsigned int)(temp % (MAX_UINT_LIMIT));
			carry = (unsigned int)(temp / (MAX_UINT_LIMIT));
		}
	}
	if(carry != 0)
	{
		output[size - 1] = carry;
	}
	while(output[size - 1] == 0)
		size--;

	free(nbr1->value);
	nbr1->value = output;
	nbr1->capacity = size;
	nbr1->size = size;
	nbr1->num_digits = num_len(nbr1);
}



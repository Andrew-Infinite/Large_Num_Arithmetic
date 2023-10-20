#include "str.h"
#include "stdlib.h"

char *string_reverse(char *str, int len)
{
	int i = -1;
	while(++i < len/2)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
	return str;
}

int ft_strlen(char *str)
{
	int count = 0;
	while(str[count])
		count++;
	return count;
}

int ft_atoi_sp(char *str,unsigned int **output)
{
	int size = ft_strlen(str);
	int size_output = size/MAX_UINT_DIGIT + (size % MAX_UINT_DIGIT != 0) * 1;
	(*output) = (unsigned int *) malloc (size_output * sizeof(unsigned int));
	unsigned int i = size_output;
	unsigned int j = -1;
	int limit;

	if (size <= 0 || (*output) == 0)
		return -1;
	
	while(*str && --i >= 0)
	{
		j = -1;
		(*output)[i] = 0;
		limit = size % MAX_UINT_DIGIT + (size % MAX_UINT_DIGIT == 0) * MAX_UINT_DIGIT;
		size -= limit;
		while(++j < limit)
		{
			(*output)[i] = (*output)[i] * 10 + *str - '0';
			str++;
		}
	}

	return size_output;
}

int hex_mul(unsigned int *a,int size_a,unsigned int *b,int size_b, unsigned int **output)
{
	int size = size_a + size_b;
	*output = (unsigned int *)malloc(size * sizeof(unsigned int));
	unsigned int carry = 0;
	for(int i = 0;i<size;i++)
	{
		(*output)[i] = 0;
	}

	for(int i = 0; i < size_b;i++)
	{
		for(int j = 0;j < size_a;j++)
		{
			unsigned long long temp = (unsigned long long)a[j] * b[i] + (*output)[i+j] + carry;
			(*output)[i+j] = (unsigned int)(temp % (MAX_UINT_LIMIT));
			carry = (unsigned int)(temp / (MAX_UINT_LIMIT));
		}
	}
	if(carry != 0)
	{
		(*output)[size - 1] = carry;
	}
	while((*output)[size - 1] == 0)
		size--;
	return size;
}

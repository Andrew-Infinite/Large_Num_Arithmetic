#include "str.h"
#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"

char *ft_itoa_sp(unsigned int* nbr, int size_nbr)
{
	int size_output = 0;

	if(size_nbr <= 0)
		return 0;

	for(unsigned int i = nbr[size_nbr - 1]; i > 0; i/=10)
		size_output++;
	size_output = size_output + (MAX_UINT_DIGIT) * (size_nbr - 1);

	char *ptr = (char *)malloc((size_output + 1)*sizeof(char));

	int j;
	ptr[size_output] = '\0';
	for(int i = 0; i < size_nbr; i++)
	{
		j = 0;
		for(unsigned int num = nbr[i]; num > 0; num/=10)
		{
			ptr[--size_output] = (num % 10) + '0';
			j++;
		}
		while(size_output > 0 && j < MAX_UINT_DIGIT)
		{
			ptr[--size_output] = '0';
			j++;
		}
	}
	
	return ptr;
}

int main (int argc, char *argv[])
{
	if(sizeof(unsigned long long) == 1 || argc != 3)
		return -1;

	//the maximum num of digit of multiplication is the sum of num of two digit.
	//eg. 99*9 = 891, which is 2 digit + 1 digit = 3 digit.
	if(sizeof(unsigned long long) * 0.5 < sizeof(unsigned int))
		MAX_UINT_DIGIT = (unsigned int)(sizeof(unsigned long long)*8*0.3*0.5);
	else
		MAX_UINT_DIGIT = (unsigned int)(sizeof(unsigned int)*8*0.3);
	MAX_UINT_LIMIT = ft_recursive_power(10,MAX_UINT_DIGIT);

	//remember to block for input, like not integer case.	
	//remember to free the memory as well once end the program.
	unsigned int *ptr;
	unsigned int *ptr2;
	unsigned int *output;
	char *str_output;
	int size_a = ft_atoi_sp(argv[1],&ptr);
	int size_b = ft_atoi_sp(argv[2],&ptr2);
	int size_c = hex_mul(ptr,size_a,ptr2,size_b,&output);
	str_output = ft_itoa_sp(output,size_c);
	printf("%s\n",str_output);

	return 0;
}

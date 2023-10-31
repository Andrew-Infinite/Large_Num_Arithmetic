#include "stdlib.h"
#include "uintd.h"

unsigned int MAX_UINT_DIGIT;
unsigned int MAX_UINT_LIMIT;

int ft_strlen(char *str)
{
	int count = 0;
	while(str[count])
		count++;
	return count;
}

void ft_atoi_sp(uintd *output, char *str)
{
	//make sure str string is only number.
	int size = ft_strlen(str);
	output->num_digits = size;
	if(size <= 0)
		return;

	int size_output = size / MAX_UINT_DIGIT + (size % MAX_UINT_DIGIT != 0) * 1;

	if(output->capacity < size_output || output->value == 0)
	{
		if(output->capacity > 0)
			free(output->value);
		output->value = (unsigned int *) malloc (size_output * sizeof(unsigned int));
		if (output->value == 0)
		{
			output->size = 0;
			output->capacity = 0;
			return;
		}
		output->capacity = size_output;
	}

	output->size = size_output;
	unsigned int i = size_output;
	unsigned int j;
	int limit;

	while(*str && --i >= 0)
	{
		j = -1;
		output->value[i] = 0;
		limit = size % MAX_UINT_DIGIT + (size % MAX_UINT_DIGIT == 0) * MAX_UINT_DIGIT;
		size -= limit;
		while(++j < limit)
		{
			output->value[i] = output->value[i] * 10 + *str - '0';
			str++;
		}
	}
}

void num_len(uintd *output)
{
	unsigned int size_output = 0;
	//count digit for the first largest num, MAX_UINT_DIGIT * size would have leading zero.
	for(unsigned int i = output->value[output->size - 1]; i > 0; i/=10)
		size_output++;
	size_output = size_output + (MAX_UINT_DIGIT) * (output->size - 1);

	output->num_digits = size_output;
}

void ft_itoa_sp(uintd *output)
{
	int j;
	unsigned int size_output = output->num_digits;

	//error handling
	if(output->size <= 0)
		return;
	
	//reallocate only if memory insufficient.
	if(output->str_cap < (size_output + 1))
	{
		free(output->str);
		output->str = (char *)malloc((size_output + 1)*sizeof(char));
		if(output->str == NULL)
		{
			output->str_cap = 0;
			return;
		}
		output->str_cap = size_output + 1;
	}
	output->str[size_output] = '\0';

	for(int i = 0; i < output->size; i++)
	{
		j = 0;
		//least significant number first
		//eg. num = 5648, output->str: 8 -> 48 -> 648 -> 5648 
		for(unsigned int num = output->value[i]; num > 0; num/=10)
		{
			output->str[--size_output] = (num % 10) + '0';
			j++;
		}
		//fill_zero
		//eg. Max_UINT_DIGIT = 3, output->str: 1|001|020|000|101 instead of 1|1|20|0|101
		while(size_output > 0 && j < MAX_UINT_DIGIT)
		{
			output->str[--size_output] = '0';
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
	num_len(nbr1);
}

int	ft_recursive_power(int nb, int power)
{
	int	val;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	val = ft_recursive_power(nb, power / 2);
	if ((power % 2) == 1)
		return (val * val * nb);
	else
		return (val * val);
}

void destructor(uintd *data)
{
    free(data->value);
	free(data->str);
    data->size = 0;
    data->capacity = 0;
    data->num_digits = 0;
    data->str_cap = 0;
    data->value = 0;
	data->str = 0;
}

void init_uintd(uintd *data)
{
    data->capacity = 0;
    data->num_digits = 0;
    data->size = 0;
    data->str = 0;
    data->str_cap = 0;
    data->value = 0;
}

void init_uintd_function(uintd_function *func)
{
    if(sizeof(unsigned long long) * 0.5 < sizeof(unsigned int))
		MAX_UINT_DIGIT = (unsigned int)(sizeof(unsigned long long)*8*0.3*0.5);
	else
		MAX_UINT_DIGIT = (unsigned int)(sizeof(unsigned int)*8*0.3);
	MAX_UINT_LIMIT = ft_recursive_power(10,MAX_UINT_DIGIT);

	func->init = &init_uintd;
    func->from_string = &ft_atoi_sp;
    func->to_string = &ft_itoa_sp;
    func->multiply = &multiply;
    func->destructor = &destructor;
}
#include "stdlib.h"
#include "uintd.h"
#include "./_uintd/_uintd.h"

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

	atoi_algorithm(output,str);
}


void ft_itoa_sp(uintd *output)
{
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

	itoa_algorithm(output);
}

void destructor(uintd *data)
{
    free(data->value);
	free(data->str);
    data->size = 0;
    data->capacity = 0;
    data->value = 0;
    data->num_digits = 0;
	data->str = 0;
    data->str_cap = 0;
}

void init_uintd(uintd *data)
{
    data->size = 0;
    data->capacity = 0;
    data->value = 0;
    data->num_digits = 0;
    data->str = 0;
    data->str_cap = 0;
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
#include "_uintd.h"

int ft_strlen(char *str)
{
	int count = 0;
	while(str[count])
		count++;
	return count;
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

int num_len(uintd *output)
{
	unsigned int size_output = 0;
	//count digit for the first largest num, MAX_UINT_DIGIT * size would have leading zero.
	for(unsigned int i = output->value[output->size - 1]; i > 0; i/=10)
		size_output++;
	size_output = size_output + (MAX_UINT_DIGIT) * (output->size - 1);

	return size_output;
}
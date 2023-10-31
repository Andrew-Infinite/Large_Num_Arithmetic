#ifndef _UINTD_H
# define _UINTD_H

#include "../uintd.h"

unsigned int MAX_UINT_DIGIT;
unsigned int MAX_UINT_LIMIT;



void atoi_algorithm(uintd *nbr, char *str);
void itoa_algorithm(uintd *nbr1);
void multiply(uintd *nbr1, uintd *nbr2);

int num_len(uintd *output);
int ft_strlen(char *str);
int	ft_recursive_power(int nb, int power);

#endif
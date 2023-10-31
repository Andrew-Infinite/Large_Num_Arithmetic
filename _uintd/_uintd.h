#ifndef _UINTD_H
# define _UINTD_H

unsigned int MAX_UINT_DIGIT;
unsigned int MAX_UINT_LIMIT;

typedef struct uintd
{
    unsigned int size;
    unsigned int capacity;
    unsigned int num_digits;
    unsigned int str_cap;
    unsigned int *value;
    char *str;
} uintd;

int ft_strlen(char *str);
void ft_atoi_sp(uintd *output, char *str);
void num_len(uintd *output);
void ft_itoa_sp(uintd *output);
void multiply(uintd *nbr1, uintd *nbr2);
int	ft_recursive_power(int nb, int power);
void destructor(uintd *data);
void init_uintd(uintd *data);
void init_uintd_function(uintd_function *func);
#endif
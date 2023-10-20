#ifndef STR_H
# define STR_H
# define MAX_UCHAR (1 << (sizeof(unsigned char)*8))

// klog10 = sizeof(unsigned int) * log 2 , approx log 2 / log 10 = 0.3

unsigned int MAX_UINT_DIGIT;
unsigned int MAX_UINT_LIMIT;
char *string_reverse(char *str, int len);
int ft_strlen(char *str);
int ft_atoi_sp(char *str,unsigned int **output);
char *ft_itoa_sp(unsigned int* nbr, int size_nbr);
int hex_mul(unsigned int *a,int size_a,unsigned int *b,int size_b, unsigned int **output);
int ft_recursive_power(int nb,int power);

#endif

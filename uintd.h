#ifndef DYNUINT_H
# define DYNUINT_H

typedef struct uintd
{
    unsigned int size;
    unsigned int capacity;
    unsigned int num_digits;
    unsigned int str_cap;
    unsigned int *value;
    char *str;
} uintd;

typedef struct uintd_func
{
    void (*atoi_sp)(uintd *output,char *str);
    void (*to_string)(uintd *output);
    void (*multiply)(uintd *nbr1, uintd *nbr2);
    void (*destructor)(uintd *);
} uintd_func;

void init_uintd(uintd *data);
void init_uintd_func(uintd_func *func);
#endif
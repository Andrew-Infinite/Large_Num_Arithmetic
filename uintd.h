#ifndef UINTD_H
# define UINTD_H

typedef struct uintd
{
    unsigned int size;
    unsigned int capacity;
    unsigned int *value;
    unsigned int num_digits;
    unsigned int str_cap;
    char *str;
} uintd;

typedef struct uintd_function
{
    void (*init)(uintd *);
    void (*from_string)(uintd *,char *);
    void (*to_string)(uintd *);
    //uintd *(*copy)(uintd *);
    void (*multiply)(uintd *, uintd *);
    void (*destructor)(uintd *);
} uintd_function;

void init_uintd_function(uintd_function *func);
#endif
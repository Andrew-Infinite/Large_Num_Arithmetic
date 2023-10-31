#include "stdio.h"
#include "stdlib.h"
#include "uintd.h"

int main (int argc, char *argv[])
{
	if(sizeof(unsigned long long) == 1 || argc != 3)
		return -1;

	uintd_function uintd_func;
    init_uintd_function(&uintd_func);

    uintd num;
    uintd_func.init(&num);

    uintd num2;
    uintd_func.init(&num2);

    uintd_func.from_string(&num,argv[1]);
    uintd_func.from_string(&num2,argv[2]);

    uintd_func.multiply(&num,&num2);

    uintd_func.to_string(&num);
    printf("%s \n",num.str);
	return 0;
}

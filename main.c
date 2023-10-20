#include "stdio.h"
#include "stdlib.h"
#include "uintd.h"

int main (int argc, char *argv[])
{
	if(sizeof(unsigned long long) == 1 || argc != 3)
		return -1;

	uintd_func func;
    init_uintd_func(&func);

    uintd my_num;
    init_uintd(&my_num);

    func.atoi_sp(&my_num,argv[1]);
    func.to_string(&my_num);

    printf("%s \n",my_num.str);
	return 0;
}

#include <stdio.h>
#include "get_name.h"
#include "print_str.h"
main()
{
	char hello[90] = "Hello, ";
	char* result;
	result = get_name();
	print_str(hello, result);
	free(result);
		return 0;

}

#include "get_next_line.h"

int main (void)
{
	int test;
	test = open("test.txt", O_RDONLY);
	if (test == -1)
		return(printf("%s\n", "erreur lors que l ouverture"), NULL);
	
	
}
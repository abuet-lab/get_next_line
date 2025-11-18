#include "get_next_line.h"

int main (void)
{
	int test;
	char *tab;
	char *t;
	//int i = 0;

	test = open("test.txt", O_RDONLY);
	if (test == -1)
	{
		printf("%s\n", "erreur lors que l ouverture");
		return (0);
	}
	
	
	tab = get_next_line(test);
	printf("test : %s", tab);
	t = get_next_line(test);
	printf("test : %s", t);
	close (test);
	
	
}
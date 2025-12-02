#include "get_next_line.h"

int main (void)
{
	int test;
	char *tab;
	//int i = 0;

	test = open("test.txt", O_RDONLY);
	if (test == -1)
	{
		printf("%s\n", "erreur lors que l ouverture");
		return (0);
	}
	tab = get_next_line(test);
	printf("test : %s", tab);
	free(tab);
	tab = get_next_line(test);
	printf("test : %s", tab);
	free(tab);
	tab = get_next_line(test);
	printf("test : %s", tab);
	free(tab);
	tab = get_next_line(test);
	printf("test : %s", tab);
	free(tab);
	tab = get_next_line(test);
	printf("test : %s", tab);
	free(tab);
	tab = get_next_line(test);
	printf("test : %s", tab);
	free(tab);
	tab = get_next_line(test);
	printf("test : %s", tab);
	free(tab);
	close (test);
	return(0);
	
}
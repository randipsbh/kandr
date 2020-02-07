#include <stdio.h>

/* copy input to output; 1st version */

main()
{
	int c = 0;

	while ((c = getchar()) != EOF) {
		printf("%d ", c != EOF);		
		putchar(c);		
	}
	/*  printf("\n%d\n", c != EOF); */
}

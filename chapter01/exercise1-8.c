#include <stdio.h>

main()
{
	int c, nltb;

	nltb = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == ' ' || c == '	')
			++nltb;
	}
	printf("%d\n", nltb);
}

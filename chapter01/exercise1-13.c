#include <stdio.h>

/* prints a histogram of the lengths of words */
main()
{ 
  int c, i, j;
  int count = 0;
  int words[10];

  for (i = 0; i < 10; ++i)
    words[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\n' && c != '\t' && c != '.')  {
      ++count;
    } else {
      if (count != 0)
        ++words[count];
      count = 0;
    }
  }

  printf("words lengths =");
  for (i = 0; i < 10; ++i)
    printf(" %d", words[i]);

  printf("\n\n");
  printf("%10s", " ");
  printf("Histogram of Word Lengths\n");
  for (i = 1; i < 10; ++i) {
    printf("Length of");
    printf(" %d", i);
    for (j = 0; j < words[i]; ++j) {
      printf("-");
    }
    printf("\n");
  }  
}

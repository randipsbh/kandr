#include <stdio.h>

main()
{
  int c, i, j;
  int na = 0;
  int nb = 0;
  int nc = 0;
  int nd = 0;
  int freq[4];

  while ((c = getchar()) != EOF) {
    if (c == 'a')
      na++;
    else if (c == 'b')
      nb++;
    else if (c == 'c')
      nc++;
    else if (c == 'd')
      nd++;
  }
   
    printf("Frequency\n");
    printf(" %d %d %d %d\n", na, nb, nc, nd);
    
    freq[0] = na;
    freq[1] = nb;
    freq[2] = nc;
    freq[3] = nd;

    for (i = 0; i < 4; i++) {
      for (j = 0; j < freq[i]; j++) {
        printf("-");
      }
      printf("\n");
    }
}

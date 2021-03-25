#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

  if (argc !=2 ) {
		printf ("Error: filenmae not given\n");
		exit (-1);
  }

  FILE * fp = fopen (argv[1], "w");

  for (int i=1; i<=10; i++)
		fprintf (fp, "2 x %d = %d\n", i, 2*i);

  fclose (fp);

  return 0;
}

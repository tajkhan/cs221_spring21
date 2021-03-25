#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

  if (argc !=2 ) {
		fprintf (stderr, "Error: filenmae not given\n");
		exit (-1);
  }

  FILE * fp = fopen (argv[1], "r");
	if (fp == NULL){
		fprintf(stderr, "Error: unable to open file %s\n", argv[1]);
		exit (-1);
  }

  int i1 = 0;
  int i2 = 0;
  int i3 = 0;
  char c1 = '\0';
  char c2 = '\0';

	fscanf (fp, "%d %c %d %c %d", &i1, &c1, &i2, &c2, &i3);

  char a[10]; 
  fprintf (stdout, "%s", "Enter string: ");
  fscanf (stdin, "%s", a);
  fprintf (stdout, "you entered %s", a);

	//printf ("%d %c %d %c %d\n", i1, c1, i2, c2, i3);
	fprintf (stdout, "%d %c %d %c %d\n", i1, c1, i2, c2, i3);

  fclose (fp);

  return 0;
}

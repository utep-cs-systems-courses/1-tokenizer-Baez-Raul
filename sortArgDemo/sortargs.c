#include <stdio.h>
#include "bst.h"  
  
int main(int argc, char **argv)	/* prints arguments in order */
{
  for (char **p = &argv[1]; *p; p++)
    bstInsert(&bstRoot, *p);
  bstPrint(bstRoot);
  bstClear(&bstRoot);

  char usrInput[50];
  puts("Please enter your phrase: \n>");
  fgets(usrInput, sizeof(usrInput), stdin);

  printf("%s", usrInput);
  
  /*
  while (1) {
    fputs("\n>", stdout);
    fflush (stdout);
    int c;
    while((c=getchar()) == '\n');
    if (c == EOF)
      goto done;
    
    switch (c) {
    case 'q':
      puts("Cancelled!");
      goto done;
    case '\n':
      break;
    default:
      printf("%c",c);
    }
  }
 done:
  return 0;
  */
}

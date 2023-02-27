#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main()
{
  char t = 't';
  printf("Is '%c' a space character: %d\n",t,space_char(t));
  printf("Is '%c' a space character: %d\n",t,non_space_char(t));
  
  char s[50] = "   Hello World";
  char a[50] = "Hello World";
  char l[50] = "Hello World! How are you today?";
  printf("%s\n",word_start(s));
  printf("%s\n",word_terminator(a));

  printf("There are %d words in '%s'\n",count_words(s),s);
  printf("There are %d words in '%s'\n",count_words(l),l);

  short y = 12;
  printf("%s\n",copy_str(a,y));

  tokenize(a);
}

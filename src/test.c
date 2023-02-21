#include <stdio.h>
#include "tokenizer.h"

int main()
{
  char t = 't';
  printf("%d\n",space_char(t));
  printf("%d\n",non_space_char(t));
  
  char s[50] = "   Hello World";
  char a[50] = "Hello World";
  char l[50] = "Hello World! How are you today?";
  printf("%s\n",word_start(s));
  printf("%s\n",word_terminator(a));

  printf("%d\n",count_words(s));
  printf("%d\n",count_words(l));
}

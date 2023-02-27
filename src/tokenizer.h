#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  return (c == ' ');
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  return (c != ' ');
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  char *start;
  start = str;
  
  while (space_char(*start) == 1){
    start++;
  }
  return start;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  char *end;
  end = word;

  while ((non_space_char(*end) == 1) && (*end != '\0')){
    end++;
  }
  return end;
}

/* Counts the number of words in the string argument. */
int count_words(char *str){
  char *traverse;
  traverse = str;
  int count = 0;

  while (*traverse != '\0'){
    traverse = word_start(traverse);
    if (*traverse == '\0'){
      return count;
    }
    traverse = word_terminator(traverse);
    traverse++;
    count++;
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *copy;
  copy = (char *) malloc(len);
  for(int i = 0; i < len; i++){
    copy[i] = inStr[i];
  }
  return copy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  int size = count_words(str)+1;
  char *tokens[size];
  
  char *iter = str;
  char *word;
  for(int i = 0; i < size; i++){
    iter = word_start(iter);
    word = copy_str(iter,(word_terminator(iter)-word_start(iter)));
    tokens[i] = word;
    iter = word_terminator(iter);
  }
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  for(int i = 0; *tokens[i] != '\0'; i++){
    printf("%s\n",tokens[i]);
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  for(int i = 0; *tokens[i] != '\0'; i++){
    tokens[i] = "";
  }
}

#endif

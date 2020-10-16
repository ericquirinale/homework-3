#include <stdio.h>
#include <math.h>

unsigned short get(unsigned short x, int n);

int main(int argc, char* argv[])
{
  unsigned short x = atoi(argv[1]);
  int length = (int)log2(x)+1;
  unsigned short reversed[16];
  int pal = 1;
  for (size_t i = 0; i < length; i++) {
    if(i>=16-length){
      reversed[i] = get(x, i);
    }
    else{
      reversed[i] = 0;
    }
  }
  for (size_t i = 0; i < length; i++) {
    if(get(x,i)!=reversed[i]){
      printf("%s\n", "Not-Palindrome");
      pal = 0;
      break;
    }
  }
  if(pal == 1){
    printf("%s\n", "Is-Palindrome");
  }
}

unsigned short get(unsigned short x, int n){
   return (x >> (n)) & 1U;
}

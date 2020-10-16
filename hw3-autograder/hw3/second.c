#include <stdio.h>
#include <math.h>
unsigned short get(unsigned short x, int n);

int main(int argc, char* argv[])
{
  unsigned short x = atoi(argv[1]);
  int length = (int)log2(x)+1;
  unsigned short oneCount = 0;
  unsigned short pairCount = 0;
  unsigned short pair = 0;
  for (size_t i = 0; i < length; i++) {
    if(get(x, i)==1){
      oneCount++;
      if(pair == 0){
        pair = 1;
      }
      else{
        pairCount++;
        pair = 0;
      }
    }
    else{
      pair=0;
    }
  }
  if(oneCount%2==0){
    printf("%s\t%hu\n","Even-Parity", pairCount);
  }
  else{
    printf("%s\t%hu\n","Odd-Parity", pairCount);
  }
}

unsigned short get(unsigned short x, int n){
   return (x >> (n)) & 1U;
}

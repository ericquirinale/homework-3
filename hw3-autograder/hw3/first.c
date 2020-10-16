#include <stdio.h>
#include <math.h>

unsigned short get(unsigned short x, int n);
unsigned short comp(unsigned short x, int n);
unsigned short set(unsigned short x, int n, unsigned short v);

int main(int argc, char* argv[])
{
  char* filename = argv[1];
  FILE* fp = fopen(filename, "r");
  unsigned short x;
  int binary = 0;
  char func;
  unsigned short arg1;
  unsigned short arg2;
  fscanf(fp, "%hu\n", &x);

  while (fscanf(fp, "%s\t%hu\t%hu\n", &func, &arg1, &arg2) == 3){
    switch(func) {
      case 's' :
         //set function
         x = set(x, arg1, arg2);
         printf("%hu\n", x);
         break;
      case 'c' :
         //comp function
         x = comp(x, arg1);
         printf("%hu\n", x);
         break;
      case 'g' :
         //get function
         binary = get(x, arg1);
         printf("%d\n", binary);
         break;
   }
  }
}

//fix this shit
unsigned short set(unsigned short x, int n, unsigned short v){
  unsigned short temp = get(x, n);
  if(temp == v){
    return x;
  }
  else{
    return comp(x, n);
  }
}

unsigned short comp(unsigned short x, int n){
  //x = (x ^ (1 << (n - 1)));
  x ^= 1UL << n;
  return x;
}

unsigned short get(unsigned short x, int n){
   return (x >> (n)) & 1U;
}

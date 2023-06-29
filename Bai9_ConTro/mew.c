
#include<stdio.h>
void main() 
{
  int a[] = {1,2,3,4,5}, *p;
  p = a;
  ++*p;
  printf("value1: %d ", *p);
  p += 2;
  printf("value2: %d ", *p);
}
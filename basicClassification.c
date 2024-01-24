/*  0 is false
    1 is true
    x is a check number
*/
#include <stdio.h>
#include <math.h>
#include "NumClass.h"
// will return if a number is prime
int isPrime(int x)
{
  int flag = 1; //boolean
  for (int i = 2; i <= sqrt(x) && flag == 1; i++)
  {
    if (x % i == 0)
    {
      flag = 0;
    }
  }
  return flag;
}
int isStrong(int x)
{
  int sum = 0;   // sum of factorial numbers
  int savex = x; // save "x" value
  int flag = 1;  // boolean
  while (x != 0)
  {
    int unite = x % 10; // unite from "x"
    int fact = 1;       // factorial calc
    while (unite != 0)
    {
      fact = fact * unite;
      unite--;
      if (unite == 0)
        sum += fact;
    }
    x = x / 10;
  }
  if (savex != sum)
    flag = 0; // if our "x" equal to his sum
  return flag;
}


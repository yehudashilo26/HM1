/*  0 is false
    1 is true
    x is a check number
*/
//   Recursion    //
#include <stdio.h>
#include <math.h>
#include "NumClass.h"
// will return if a number is prime
int revP(int x, int temp)
{
    if (x == 0)
        return temp;
    temp = (temp * 10) + (x % 10);
    return revP(x / 10, temp);
}
int isPalindrome(int x)
{
    int temp = revP(x, 0);
    if (temp == x)
        return 1;
    else
        return 0;
}
// will weturn if a number is Armstrong number
int checkArm(int x, int sum)
{
    if(x == 0) return 0;
    int unite = x % 10;
    int size = pow(unite, sum);
    return size + checkArm(x / 10, sum);
}
int isArmstrong(int x)
{
    int savex = x;
    int sum = 0;
    while (savex > 0)
    {
       savex = savex / 10;
        sum++;
    }
    if (x == checkArm(x, sum))
        return 1;
    else
        return 0;
}


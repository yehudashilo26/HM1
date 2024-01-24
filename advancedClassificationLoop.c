/*  0 is false
    1 is true
    x is a check number
*/
#include <stdio.h>
#include <math.h>
#include "NumClass.h"
// will return if a number is prime
int isPalindrome(int x)
{
    int savex = x;
    int rightside = 0;
    int flag = 1; // 1 == true
    /*  example :  1221
    >> left side 1221 (save the number)
    << right side 1+10*0 -> 2+10*1 -> 2+10*12 -> 1+10*122 = 1221
*/
    while (x != 0)
    {
        int unite = x % 10;
        rightside = unite + (rightside * 10);
        x /= 10;
    }
    if (savex != rightside)
        flag = 0;
    return flag;
}
// will weturn if a number is Armstrong number
int isArmstrong(int x)
{
    int save = x;
    int savex = x;
    int flag = 1;
    int sum = 0;
    int i = 0;
    while (save != 0)
    {
        save /= 10;
        i++;
    }
    while (x != 0)
    {
        int unite = x % 10;
        sum = sum + pow(unite, i);
        x /= 10;
    }
    if (savex != sum)
        flag = 0;
    return flag;
}



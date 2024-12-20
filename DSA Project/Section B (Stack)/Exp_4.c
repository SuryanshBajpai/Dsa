#include<stdio.h> 
int factorial(int n)
{
printf("Entering factorial(%d)\n", n); if (n == 0 || n == 1) {
printf("Returning from factorial(%d) with value 1\n", n); return 1;
}
int result = n * factorial(n - 1);
printf("Returning from factorial(%d) with value %d\n", n, result); return result;
}
Intmain() { int num;
printf("Enter a number to calculate its factorial: "); scanf("%d", &num);
if (num < 0) {
printf("Factorial of a negative number is not defined.\n");
}
 else {
int result = factorial(num);
printf("\nFactorial of %d is: %d\n", num, result);
}
return 0;
}

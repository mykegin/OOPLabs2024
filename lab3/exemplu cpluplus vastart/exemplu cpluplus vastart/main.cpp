#include <stdio.h>      /* printf */
#include <stdarg.h>     /* va_list, va_start, va_arg, va_end */

void PrintFloats(int n, ...)
{
    int i;
    double val;
    printf("Printing floats:");
    va_list vl;
    va_start(vl, n);
    for (i = 0; i < n; i++)
    {
        val = va_arg(vl, double);
        printf(" [%.2f]", val);
    }
    va_end(vl);
    printf("\n");
}

int main()
{
    PrintFloats(10, 3.14159, 2.71828, 1.41421, 0.1234, 7.9432, 543.123, 1.0);
    return 0;
}
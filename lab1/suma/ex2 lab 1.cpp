#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;
char s[256];
int n, i, j,sum;
int main()
{
    FILE* pFile;
    pFile = fopen("ini.txt", "r");
    fputs(s, pFile);

    if (pFile != NULL)
    {
        while(fgets(s, 256, pFile)!=NULL)
        {
            i = 0;
            n = 0;
            while (s[i] != '\n')
            {
                if (s[i] >= '0' && s[i] <= '9')
                    n = n * 10 + (s[i] - '0');
                i++;
            }
            sum += n;
            i++;
        }

        fclose(pFile);
    }
    printf("suma: %d", sum);
}
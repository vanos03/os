#include <stdio.h>
#include <string.h>
#include "poem.h"

#define n 10
#define x 200
#define y 200

int main(int argc, char* argv[])
{
    int cnt = 0, i = 0, j = 0;
    char mas[x][y];

    while (poem[i] != '\0')
    {
        if (poem[i] != '\n') mas[j][i] = poem[i];
        else
        {
            cnt++;
            mas[j][i] = '\0';
            j++;
        }
        i++;
    }
    int flag = 0;

    for (int i = 0; i < cnt; i++)
        if (strcmp(mas[i], argv[1]) == 1) printf("%d\n", i);

}
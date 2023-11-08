#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int size, sumR, sumL;


void DetR(int **arr){
    int i  = 0, j = 0, k = 0, b = 1 , n = 0;

    while(n != size)
    {
        for(int i = 0; i< size; i++)
        {
            j = i + n;
            b *= arr[i][j % size];
        }

        sumR += b;
        b = 1;

        n++;
    }

    //printf("\n%d", sumR);

}

void DetL(int **arr){
    int i  = 0, j = 0, k = 0, b = 1 , n = 0;

    while(n != size)
    {
        for(int i = 0; i < size ; i++)
        {
            j = size - 1 - i + n;
            b *= arr[i][j % size];

        }
            sumL += b;
            b = 1;
            n++;
    }
    //printf("\n%d", sumL);
}

int main(int argc, char* argv[]) {

    FILE* fin = fopen(argv[1], "rt");

    int i, j, k;
    int **arr;

    scanf("%d", &size);

    arr = (int**)malloc(size*sizeof(int));

    for (i = 0; i < size; ++i)
    {
        arr[i] = malloc(size*sizeof(int));
    }

     for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++)
            fscanf(fin, "%d", &arr[i][j]);
     }

     for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++)
            printf("%d", arr[i][j]);
     }

    fclose(fin);

    pthread_t p1;
    pthread_t p2;

    pthread_create(&p1, NULL, DetR, arr);
    pthread_create(&p2, NULL, DetL, arr);

    pthread_join(p1,NULL);
    pthread_join(p2,NULL);

    printf("\n%d", sumR);
    printf("\n%d", sumL);

   printf("\n%d",  sumR - sumL);
}

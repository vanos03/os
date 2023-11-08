#include <stdlib.h>
#include <stdio.h>
//{1,4,2,5,3,0,2,2,5,1,0,4,2,3,5,0,1,1,3,5,2,0,1,1,5} 
int main()
{
int A[25] ={0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4};
int New[9];
int sum = 0;
int LINES = 5;
int nine = 0;

for(int i = 0; i < 25; i++)
	{
	if(i % (5) == 0)
		printf("\n");
	printf("%d ", A[i]);
	}
	printf("\n");
		

printf("\n");
for (int l = 0; l<(LINES-2)*(LINES-2)+LINES; l+=LINES)
{
	for(int j =l; j<(LINES-2)+l;j++){
		nine = 0;
		for (int i = j; i < (LINES-2)*(LINES-2)+LINES +j; i += LINES)
		{
			sum = 0;
			for (int k =0; k < 3; k++){
				sum += A[i + k];
			}
			nine += sum;

		}
		printf("%d ",nine);

	}
	printf("\n");
}


/*
for(i = 0; i < (LINES-2)*(LINES-2); i++)
	{
	if(i % (LINES-2) == 0)
		printf("\n");
	printf("%d ", New[i]);
	}*/

return 0;
}

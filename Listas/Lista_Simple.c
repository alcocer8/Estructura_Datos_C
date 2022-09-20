#include <stdio.h>
#include <stdlib.h>

int* primera_posicion(int *arr, int n){
  	int *new_arr = (int*) malloc(sizeof(int)*(n+1));
  
	printf("Ingrese el nuevo valor: "); 
	scanf("%i", &new_arr[0]);

	for(int i = 1; i< n+1; i++){
		new_arr[i] = arr[i];
	}

	return new_arr;
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,3,4,1};
	int n = sizeof(arr)/sizeof(int);
	int *new_arr = primera_posicion(arr, n);
	for (int i = 0; i < n+1; ++i)
	{
		printf("i: %i\n", new_arr[i]);
	}

	return 0;
}
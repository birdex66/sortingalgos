#include <stdio.h>
#include <stdlib.h>

void printarr(int arr[],int len);
void mergesort(int arr[],int len);
void merge(int left[],int right[],int arr[],int len,int leftlen,int rightlen);

int main()
{
	char input[8];
	printf("Pick the kth ranked element: ");
	scanf("%s",input);
	int k = atoi(input) - 1;

	int arr[] = {4,8,2,3,1,5,4,7,4,7,9,8,1,3,3,2,4,1,4,10,5,1,4,3,6,6,6,9,10,4,10,6,7,9,8};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	if(k<0 || k>=len){
	       	printf("Out of range!\n");
	       	return 1;
	}
	
	printarr(arr,len);
	mergesort(arr,len);
	printarr(arr,len);
	
	for(int i=0; i<k; ++i) printf("%s", (arr[i] < 10 ? "  " : "   ") );
	printf("%s", (arr[k] < 10 ? "^\n" : "^^\n") );
	printf("%s ranked element: %i\n",input,arr[k]);

	return 0;
}

void printarr(int arr[],int len){
	for(int i=0; i<len; ++i) printf("%i ",arr[i]);
	printf("\n");

}

void mergesort(int arr[],int len){
	//printf("Length: %i\n ",len);
	if(len <= 1) return;

	int leftlen = len/2;
	int rightlen = len-leftlen;

	int left[leftlen],right[rightlen];

	for(int i=0; i<leftlen; ++i) left[i] = arr[i];
	for(int j=0; j<rightlen; ++j) right[j] = arr[j+leftlen];

	/*	
		printarr(left,leftlen);
		printarr(right,rightlen);
		printarr(arr,len);
		printf("\n");
	*/	

	mergesort(left,leftlen);
	mergesort(right,rightlen);

	merge(left,right,arr,len,leftlen,rightlen);
}
void merge(int left[],int right[],int arr[],int len,int leftlen,int rightlen){

	int i=0,j=0,k=0;
	while(i<leftlen && j<rightlen){
		if(left[i]<=right[j]) arr[k++] = left[i++];
		else arr[k++] = right[j++];
	}

	while(i<leftlen) arr[k++] = left[i++];
	while(j<rightlen) arr[k++] = right[j++];
}

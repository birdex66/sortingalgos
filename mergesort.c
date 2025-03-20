#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {true = 1,false=0}bool;



void printarr(int arr[],int len);
void mergesort(int arr[],int len);
void merge(int left[],int right[],int arr[],int len,int leftlen,int rightlen);

int main(int argc, char** argv)
{
	char* arrinput = NULL;
	size_t leninput = 0;
	ssize_t read;

	printf("Enter array elements, each separated with a ',' : ");
	read = getline(&arrinput,&leninput,stdin);

	int* arr;
	int count = 0;

	char* token = strtok(arrinput,","); 
	while(token != NULL){
		int *temp = realloc(arr,(1+count) * sizeof(int));

		if(temp == NULL){
			printf("Failed malloc.\n");
			free(arr),free(arrinput);
			return 1;
		}

		arr = temp;
		arr[count++] = atoi(token);
		token = strtok(NULL,",");	
	}
	
	bool sorted = false;

	while(true){
		char inputK[8];
		printf("Pick the kth ranked element (-1 to exit): ");
		scanf("%s",inputK);
		int k = atoi(inputK) - 1;
		if(k == -2) break;
		//int arr[] = {4,8,2,3,1,5,4,7,4,7,9,8,1,3,3,2,4,1,4,10,5,1,4,3,6,6,6,9,10,4,10,6,7,9,8};
		//int len = sizeof(arr)/sizeof(arr[0]);

		if(k<0 || k>=count){
			printf("%i is out of range!\n\n",k+1);
			continue;
		}

		if(!sorted) printarr(arr,count),mergesort(arr,count),sorted=true;
		printarr(arr,count);

		for(int i=0; i<k; ++i) printf("%s", (arr[i] < 10 ? "  " : "   ") );
		printf("%s", (arr[k] < 10 ? "^\n" : "^^\n") );
		printf("Rank %s element: %i\n\n",inputK,arr[k]);
	}
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

#include <stdio.h>
#include <chrono>
#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[],int l,int r){
	int pivot=arr[r];
	int i=l,pi=l;
	for(int i=l;i<=r-1;++i){
		if(arr[i] <= pivot){
			swap(&arr[i],&arr[pi]);
			pi++;
		}
	}
	swap(&arr[r],&arr[pi]);
	return pi;
}
void quicksort(int arr[],int l,int r){
	if(l>=r) return;
	int idx = partition(arr,l,r);
	quicksort(arr,l,idx-1);
	quicksort(arr,idx+1,r);
	
	
}

void printarr(int a[],int n){
	for(int i=0;i<n;++i){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int pwr(int a, int b)
{
    int ans = 1;
    int base = a;
    while (b)
    {
        if (b & 1)
            ans = ans * base;
        base = base * base;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int sz, j;
    for (j = 6; j <= 10; ++j)
    {
        auto start = chrono::high_resolution_clock::now();
        sz = pwr(2, j);
        int arr[sz], i;
        for (i = 0; i < sz; i++)
            arr[i] = rand() % 50;
        int arr_size = sizeof(arr) / sizeof(arr[0]);

        quicksort(arr, 0, sz - 1);
        auto end = chrono::high_resolution_clock::now();
        double time_elapsed = double(chrono::duration_cast<chrono::microseconds>(end - start).count());
        cout << "Running Time for size " << sz << " is: " << time_elapsed << " milisec"
             << "\n";
			 printarr(arr,sz);
    }
    return 0;
}
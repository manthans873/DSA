#include <iostream>
#include <chrono>
#include <stdio.h>
using namespace std;

void merge(int L[], int R[], int a[], int n, int mid)
{
	int i = 0, j = 0, k = 0;
	int n1 = mid, n2 = n - mid;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
			k++;
		}
		else
		{
			a[k] = R[j];
			j++;
			k++;
		}
	}
	while (i < n1)
	{
		a[k] = L[i];
		k++;
		i++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergesort(int a[], int n)
{
	int mid = n / 2;
	int *a1 = new int[mid];
	int *a2 = new int[n - mid];
	if (n == 1)
		return;
	for (int i = 0; i < mid; ++i)
	{
		a1[i] = a[i];
	}
	for (int i = mid; i < n; ++i)
	{
		a2[i - mid] = a[i];
	}
	mergesort(a1, mid);
	mergesort(a2, n - mid);
	merge(a1, a2, a, n, mid);
}

void printarr(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
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
	for (j = 6; j <= 18; ++j)
	{
		auto start = chrono::high_resolution_clock::now();
		sz = pwr(2, j);
		int arr[sz], i;
		for (i = 0; i < sz; i++)
			arr[i] = rand() % 1000000;
		int arr_size = sizeof(arr) / sizeof(arr[0]);

		mergesort(arr, sz);
		auto end = chrono::high_resolution_clock::now();
		double time_elapsed = double(chrono::duration_cast<chrono::microseconds>(end - start).count());
		cout << "Running Time for size " << sz << " is: " << time_elapsed << " milisec"
			 << "\n";
	}
	return 0;
}

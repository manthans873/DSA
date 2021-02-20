#include <iostream>
#include <string>
#include <cmath> //cmath for ceil and floor functions tan of an angle also
#include <algorithm>
#include <iomanip>//for setprecision//    fixed<<////setprecision(value upto you want to precise)<<variable name;////
#include <vector>
#include<numeric>
#include <set> // to work with sets
#include <cstdlib>
#include <map>
#include <stdio.h>// for bitwise operators
#include <stdlib.h>
#include <unordered_set>
#include <math.h>// for pow() function
#include <queue>

using namespace std;
typedef long long ll;

// Sorting algorithms
// 1. Selection Sort 
void SelectionSort(int arr[], int n) {
	int left = 0;
	while (left != n - 1) {
		int index = 0;
		int mn = 10000000;
		for (int i = left; i < n; ++i) {
			if (arr[i] < mn) {
				mn = arr[i];
				index = i;
			}
		}
		int temp = arr[left];
		arr[left] = arr[index];
		arr[index] = temp; 
		left ++;
	}
	for (int i = 0; i < n; ++i ) {
		cout << arr[i] << " ";
	}
	cout << "\n";

}

// 2. Bubble Sort

void BubbleSort(int arr[], int n) {
	for (int  i = 1; i < n; ++i) {
		// this flag is only for sorted array
		int flag = 0;
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) break;
		// if the sorted array is passed as argument then the loop will break
	}
	for (int i = 0; i < n; ++i ) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}
// 3. Insertion sort
void InsertionSort(int arr[], int n) {
	for (int i = 1; i < n; ++i) {
		int temp = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > temp) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
	for (int i = 0; i < n; ++i ) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {

	int arr[]={7, 2, 6, 1, 5, 3};
	SelectionSort(arr, 6);
	BubbleSort(arr, 6);
	InsertionSort(arr, 6);

	

	return 0;
}


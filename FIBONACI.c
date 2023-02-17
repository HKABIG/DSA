//Time Complexity: O(Logn)
// Space Complexity: O(1)
// Fibonacci series: 0 1 1 2 3 5 8 ...... 
#include <stdio.h>

int min(int x, int y) { return (x <= y) ? x : y; }

int fibMonaccianSearch(int arr[], int x, int n)
{
	int fibMMm2 = 0; // (m-2 th) Fibonacci number
	int fibMMm1 = 1; // (m-1 th) Fibonacci number
	int fibM = fibMMm2 + fibMMm1; // (m th) Fibonacci number

	while (fibM < n) { // Finding the Fibonacci nubmer nearest to n 
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	int offset = -1; // Starting index of search space

	while (fibM > 1) {
		int i = min(offset + fibMMm2, n - 1);
		if (arr[i] < x) {
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		}
		else if (arr[i] > x) {
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}
		else
			return i;
	}
	if (fibMMm1 && arr[offset + 1] == x)
		return offset + 1;
	return -1;
}

int main(void)
{
	int arr[]
		= { 10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100,235};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 235;
	int ind = fibMonaccianSearch(arr, x, n);
if(ind>=0)
	printf("Found at index: %d",ind);
else
	printf("%d isn't present in the array",x);
	return 0;
}

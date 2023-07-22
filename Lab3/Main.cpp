#include "Algorithm.h"
#include "DataGenerator.h"
using namespace std;
void printArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int a[200000];
	int n = 200000;
	int choice;
	cin >> choice;
	GenerateData(a, n, choice);
	//printArray(a, n);
	int count_compare = 0;
	clock_t start, end;
	start = clock();
	shakerSort(a, n, count_compare);
	//mergeSort(a, 0, n - 1, count_compare);
	end = clock();
	double time_use = (double)((end - start) * 1000) / CLOCKS_PER_SEC;//tinh theo milisec
	//printArray(a, n);
	cout << "---------------------------" << endl;
	cout << "Running time:" << time_use << endl;
	cout << "Comparison:" << count_compare << endl;
	cout << "---------------------------" << endl;

	return 0;
}
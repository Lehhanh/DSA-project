#include "Command.h"
using namespace std;

bool check_algorithm(string algorithm, int a[], int n, long long& count_compare, double& running_time) {
	count_compare = 0;
	running_time = 0;
	clock_t start, end;
	if (algorithm == "selection-sort") {
		start = clock();
		selectionSort(a, n, count_compare);
		end = clock();
	}
	else if (algorithm == "insertion-sort") {
		start = clock();
		insertionSort(a, n, count_compare);
		end = clock();
	}
	else if (algorithm == "bubble-sort") {
		start = clock();
		bubbleSort(a, n, count_compare);
		end = clock();
	}
	else if (algorithm == "shaker-sort") {
		start = clock();
		shakerSort(a, n, count_compare);
		end = clock();
	}
	else if (algorithm == "shell-sort") {
		start = clock();
		shellSort(a, n, count_compare);
		end = clock();
	}
	else if (algorithm == "heap-sort") {
		start = clock();
		heapSort(a, n, count_compare);
		end = clock();
	}
	else if (algorithm == "merge-sort") {
		start = clock();
		mergeSort(a, 0, n - 1, count_compare);
		end = clock();
	}
	else if (algorithm == "quick-sort") {
		start = clock();
		quickSort(a, 0, n - 1, count_compare);
		end = clock();
	}
	else if (algorithm == "counting-sort") {
		start = clock();
		countingSort(a, n, count_compare);
		end = clock();
	}
	else if (algorithm == "radix-sort") {
		start = clock();
		radixSort(a, n, count_compare);
		end = clock();
	}
	else if (algorithm == "flash-sort") {
		start = clock();
		flashSort(a, n, count_compare);
		end = clock();
	}
	else {
		cout << "Invalid algorithm" << endl;
		return 0;
	}
	running_time = (double)((end - start) * 1000) / CLOCKS_PER_SEC;
	return 1;
}

int check_inputOrder(string s) {
	if (s == "-rand")
		return 0;
	else if (s == "-sorted")
		return 1;
	else if (s == "-rev")
		return 2;
	else if (s == "-nsorted")
		return 3;
	return -1;
}

int check_outputParameter(string s) {
	if (s == "-time")
		return 0;
	else if (s == "-comp")
		return 1;
	else if (s == "-both")
		return 2;
	return -1;
}

void Command_2(int argc, char* argv[]) {
	string outpPar = argv[5];
	int check_1 = check_outputParameter(outpPar);
	if (check_1 == -1) {
		cout << "Invalid output parameter" << endl;
		return;
	}
	string inpSize = argv[3];
	int n = stoi(inpSize);
	if (n < 0) {
		cout << "Invalid input size" << endl;
		return;
	}
	int* a = new int[n];
	string inpOrder = argv[4];
	int check_2 = check_inputOrder(inpOrder);
	if (check_2 == -1) {
		cout << "Invalid input order" << endl;
		return;
	}
	else {
		GenerateData(a, n, check_2);
	}
	string algorithm = argv[2];
	double running_time = 0;
	long long count_compare = 0;
	if (!check_algorithm(algorithm, a, n, count_compare, running_time)) {
		cout << "Invalid algorithm" << endl;
		return;
	}
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm:" << algorithm << endl;
	cout << "Input size:" << n << endl;
	cout << "Input order:";
	switch (check_2) {
	case 0:
		cout << "randomized data" << endl;
		break;
	case 1:
		cout << "sorted data" << endl;
		break;
	case 2:
		cout << "reverse sorted data" << endl;
		break;
	case 3:
		cout << "nearly sorted data" << endl;
		break;
	}
	cout << "------------------------------" << endl;
	switch (check_1) {
	case 0:
		cout << "Running time:" << running_time << endl;
		break;
	case 1:
		cout << "Comparisons:" << count_compare << endl;
		break;
	case 2:
		cout << "Running time:" << running_time << endl;
		cout << "Comparisons:" << count_compare << endl;
		break;
	}
}
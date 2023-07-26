#include "Command.h"
using namespace std;

bool check_algorithm(char algorithm[], int a[], int n, long long& count_compare, double& running_time) {
	count_compare = 0;
	running_time = 0;
	clock_t start, end;
	if (strcmp(algorithm, "selection-sort") == 0) {
		start = clock();
		selectionSort(a, n, count_compare);
		end = clock();
	}
	else if (strcmp(algorithm, "insertion-sort") == 0) {
		start = clock();
		insertionSort(a, n, count_compare);
		end = clock();
	}
	else if (strcmp(algorithm, "bubble-sort") == 0) {
		start = clock();
		bubbleSort(a, n, count_compare);
		end = clock();
	}
	else if (strcmp(algorithm, "shaker-sort") == 0) {
		start = clock();
		shakerSort(a, n, count_compare);
		end = clock();
	}
	else if (strcmp(algorithm, "shell-sort") == 0) {
		start = clock();
		shellSort(a, n, count_compare);
		end = clock();
	}
	else if (strcmp(algorithm, "heap-sort") == 0) {
		start = clock();
		heapSort(a, n, count_compare);
		end = clock();
	}
	else if (strcmp(algorithm, "merge-sort") == 0) {
		start = clock();
		mergeSort(a, 0, n - 1, count_compare);
		end = clock();
	}
	else if (strcmp(algorithm, "quick-sort") == 0) {
		start = clock();
		quickSort(a, 0, n - 1, count_compare);
		end = clock();
	}
	else if (strcmp(algorithm, "counting-sort") == 0) {
		start = clock();
		countingSort(a, n, count_compare);
		end = clock();
	}
	else if (strcmp(algorithm, "radix-sort") == 0) {
		start = clock();
		radixSort(a, n, count_compare);
		end = clock();
	}
	else if (strcmp(algorithm, "flash-sort") == 0) {
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

int check_inputOrder(char s[]) {
	if (strcmp(s, "-rand") == 0)
		return 0;
	else if (strcmp(s, "-sorted") == 0)
		return 1;
	else if (strcmp(s, "-rev") == 0)
		return 2;
	else if (strcmp(s, "-nsorted") == 0)
		return 3;
	return -1;
}

int check_outputParameter(char s[]) {
	if (strcmp(s, "-time") == 0)
		return 0;
	else if (strcmp(s, "-comp") == 0)
		return 1;
	else if (strcmp(s, "-both") == 0)
		return 2;
	return -1;
}

void Command_1(int argc, char* argv[]) {
	string algorithm = argv[2];
	string inputFilename = argv[3];
	string outputParam = argv[4];
	int check_1 = check_outputParameter(outputParam);
	if (check_1 == -1) {
		cout << "Invalid output parameter specified!" << endl;
		return;
	}
	int n;
	ifstream inputFile(inputFilename);
	inputFile >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++){
		inputFile >> a[i];
	}
	inputFile.close();
	double running_time = 0;
	long long count_compare = 0;
	if (!check_algorithm(algorithm, a, n, count_compare, running_time)) {
		cout << "Invalid algorithm specified!" << endl;
		return;
	}
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm:" << algorithm << endl;
	cout << "Input file:" << inputFilename << endl;
	cout << "Input size:" << n << endl;
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
	delete[] a;
}

void Command_2(int argc, char* argv[]) {
	int check_1 = check_outputParameter(argv[5]);
	if (check_1 == -1) {
		cout << "Invalid output parameter" << endl;
		return;
	}
	int n = atoi(argv[3]);
	if (n < 0) {
		cout << "Invalid input size" << endl;
		return;
	}
	int* a = new int[n];
	int check_2 = check_inputOrder(argv[4]);
	if (check_2 == -1) {
		cout << "Invalid input order" << endl;
		return;
	}
	else {
		GenerateData(a, n, check_2);
	}
	ofstream f1;
	f1.open("input.txt", ios_base::out);
	f1 << n << endl;
	for (int i = 0; i < n; i++) {
		f1 << a[i] << " ";
	}
	f1.close();
	double running_time = 0;
	long long count_compare = 0;
	if (!check_algorithm(argv[2], a, n, count_compare, running_time)) {
		cout << "Invalid algorithm" << endl;
		return;
	}
	ofstream f2;
	f2.open("output.txt", ios_base::out);
	f2 << n << endl;
	for (int i = 0; i < n; i++) {
		f2 << a[i] << " ";
	}
	f2.close();
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm:" << argv[2] << endl;
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

void Command_4(int argc, char* argv[]) {
	string algorithm_1 = argv[2];
	string algorithm_2 = argv[3];
	string inputFilename = argv[4];
	int n;
	ifstream inputFile(inputFilename);
	inputFile >> n;
	int* a = new int[n];
	int* b = new int[n];
	for (int i = 0; i < n; i++){
		inputFile >> a[i];
		inputFile >> b[i];
	}
	inputFile.close();
	double running_time_1 = 0;
	double running_time_2 = 0;
	long long count_compare_1 = 0;
	long long count_compare_2 = 0;
	if (!check_algorithm(algorithm_1, a, n, count_compare_1, running_time_1)) {
		cout << "Invalid algorithm specified!" << endl;
		return;
	}
	if (!check_algorithm(algorithm_2, a, n, count_compare_2, running_time_2)) {
		cout << "Invalid algorithm specified!" << endl;
		return;
	}
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm:" << algorithm_1 << " | " << algorithm_2 << endl;
	cout << "Input file:" << inputFilename << endl;
	cout << "Input size:" << n << endl;
	cout << "------------------------------" << endl;
	cout << "Running time:" << running_time_1 << " | " << running_time_2 << endl;
	cout << "Comparisons:" << count_compare_1 << " | " << count_compare_2 << endl;
	delete[] b;
	delete[] a;
}

void Command_5(int argc, char* argv[]) {
	int n = atoi(argv[4]);
	if (n < 0) {
		cout << "Invalid input size" << endl;
		return;
	}
	int* a = new int[n];
	int check = check_inputOrder(argv[5]);
	if (check == -1) {
		cout << "Invalid input order" << endl;
		return;
	}
	else {
		GenerateData(a, n, check);
	}
	ofstream f1;
	f1.open("input.txt", ios_base::out);
	f1 << n << endl;
	for (int i = 0; i < n; i++) {
		f1 << a[i] << " ";
	}
	f1.close();
	int* b = new int[n];
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	cout << "yes" << endl;
	double running_time_1 = 0, running_time_2 = 0;
	long long count_compare_1 = 0, count_compare_2 = 0;
	bool check_1 = check_algorithm(argv[2], a, n, count_compare_1, running_time_1);
	bool check_2 = check_algorithm(argv[3], b, n, count_compare_2, running_time_2);
	if (!check_1 || !check_2) {
		cout << "Invalid algorithm" << endl;
		return;
	}
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm:" << argv[2] << " | " << argv[3] << endl;
	cout << "Input size:" << n << endl;
	cout << "Input order:";
	switch (check) {
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
	cout << "Running time:" << running_time_1 << " | " << running_time_2 << endl;
	cout << "Comparisons:" << count_compare_1 << " | " << count_compare_2 << endl;
	delete[] a;
	delete[] b;
}

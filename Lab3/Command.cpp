#include "Command.h"

using namespace std;

bool check_algorithm(string algorithm, int a[], int n, long long& count_compare, double& running_time) {
	count_compare = 0;
	running_time = 0;
	clock_t start, end;
	if (algorithm == "selection-sort") {
		start = clock();
		selection_sort(a, n, count_compare);
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
		shell_sort(a, n, count_compare);
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
		quick_sort(a, 0, n - 1, count_compare);
		end = clock();
	}
	else if (algorithm == "counting-sort") {
		start = clock();
		counting_sort(a, n, count_compare);
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
		cout << "Invalid algorithm" << endl;
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

void Command_3(int argc, char* argv[]) {

	double running_time = 0;
	long long count_compare = 0;
	int check_1 = check_outputParameter(argv[4]);

	if (check_1 == -1) {
		cout << "Invalid output parameter" << endl;
		return;
	}
	int n = atoi(argv[3]); // input size
	if (n < 0) {
		cout << "Invalid input size" << endl;
		return;
	}
	int* a = new int[n];
	GenerateRandomData(a, n);

	ofstream f1;
	f1.open("input_1.txt", ios_base::out);
	f1 << n << endl;
	for (int i = 0; i < n; i++) {
		f1 << a[i] << " ";
	}
	f1.close();

	if (!check_algorithm(argv[2], a, n, count_compare, running_time)) {
		cout << "Invalid algorithm" << endl;
		return;
	}

	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm:" << argv[2] << endl;
	cout << "Input size:" << n << endl;
	cout << "Input order: " << "Randomized" << endl;
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
	cout << endl;

	running_time = 0;
	count_compare = 0;
	GenerateNearlySortedData(a, n);

	ofstream f11;
	f11.open("input_2.txt", ios_base::out);
	f11 << n << endl;
	for (int i = 0; i < n; i++) {
		f11 << a[i] << " ";
	}
	f11.close();

	if (!check_algorithm(argv[2], a, n, count_compare, running_time)) {
		cout << "Invalid algorithm" << endl;
		return;
	}

	cout << "Input order: " << "Nearly Sorted" << endl;
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
	cout << endl;

	running_time = 0;
	count_compare = 0;
	GenerateSortedData(a, n);

	ofstream f12;
	f12.open("input_3.txt", ios_base::out);
	f12 << n << endl;
	for (int i = 0; i < n; i++) {
		f12 << a[i] << " ";
	}
	f12.close();

	if (!check_algorithm(argv[2], a, n, count_compare, running_time)) {
		cout << "Invalid algorithm" << endl;
		return;
	}

	cout << "Input order: " << "Sorted" << endl;
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
	cout << endl;

	running_time = 0;
	count_compare = 0;
	GenerateReverseData(a, n);

	ofstream f13;
	f13.open("input_4.txt", ios_base::out);
	f13 << n << endl;
	for (int i = 0; i < n; i++) {
		f13 << a[i] << " ";
	}
	f13.close();

	if (!check_algorithm(argv[2], a, n, count_compare, running_time)) {
		cout << "Invalid algorithm" << endl;
		return;
	}

	cout << "Input order: " << "Reversed" << endl;
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
	cout << endl;

	delete[] a;
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
	if (!check_algorithm(algorithm_1, a, n, count_compare_1, running_time_1) || !check_algorithm(algorithm_2, a, n, count_compare_2, running_time_2)) {
		cout << "Invalid algorithm" << endl;
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
	cout << "COMPARE MODE" << endl;
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

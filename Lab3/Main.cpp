#include "Algorithm.h"
#include "DataGenerator.h"
#include "Command.h"
using namespace std;
void printArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	string mode = argv[1];
	if (mode == "-a") {
		if (argc == 5) {
			//command 1 or 3
		}
		else if (argc == 6) {
			//command 2
			Command_2(argc, argv);
		}
		else {
			cout << "invalid command line argument" << endl;
		}
	}
	else if (mode == "-c") {
		if (argc == 5) {
			//command 4
		}
		else if (argc == 6) {
			//command 5
		}
		else {
			cout << "invalid command line argument" << endl;
		}
	}
	else {
		cout << "invalid command line argument" << endl;
	}
	return 0;
}

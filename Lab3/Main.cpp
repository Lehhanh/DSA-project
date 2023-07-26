#include "Algorithm.h"
#include "DataGenerator.h"
#include "Command.h"
using namespace std;
//void printArray(int a[], int n) {
//	for (int i = 0; i < n; i++) {
//		cout << a[i] << " ";
//	}
//	cout << endl;
//}

int main(int argc, char* argv[]) {
	if (argc < 2)
		return 0;
	if (strcmp(argv[1], "-a") == 0) {
		if (argc == 5) {
			//command 1 or 3
			Command_1(argc, argv);
		}
		else if (argc == 6) {
			//command 2
			Command_2(argc, argv);
		}
		else {
			cout << "invalid command line argument" << endl;
		}
	}
	else if (strcmp(argv[1], "-c") == 0) {
		if (argc == 5) {
			//command 4
			Command_4(argc, argv);
		}
		else if (argc == 6) {
			//command 5
			Command_5(argc, argv);
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

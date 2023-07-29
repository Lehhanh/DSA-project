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
	string mode = argv[1];
	if (mode == "-a") {
		if (argc == 5) {
			if ('0' < argv[3][0] && argv[3][0] <= '9')
			Command_3(argc, argv);
			else Command_1(argc, argv);
		}
		else if (argc == 6) {
			Command_2(argc, argv);
		}
		else {
			cout << "Insufficient command line arguments!" << endl;
		}
	}
	else if (mode == "-c") {
		if (argc == 5) {
			Command_4(argc, argv);
		}
		else if (argc == 6) {
			Command_5(argc, argv);
		}
		else {
			cout << "Insufficient command line arguments!" << endl;
		}
	}
	else {
		cout << "Invalid command line argument" << endl;
	}
	return 0;
}

// file main.cpp
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
extern "C" int MODIFY_ARRAY(int*, int);
extern "C" int* fillArray(int, int*);


#include <iostream>
#include <cstdlib>
#include <ctime>

// Function prototype
//void function(int arraySize, int* initialArray);
//
//void function(int arraySize, int* initialArray) {
//	srand(time(0));
//	for (int i = 0; i < arraySize; ++i) {
//		int randomNumber = (std::rand()%101)-50; 
//		initialArray[i] = randomNumber;
//	}
//}

int main() {
	setlocale(LC_ALL, "Russian");

	srand((unsigned int)time(NULL));
	int* initialArray = nullptr;
	int i = 0, numberOfReplaces = 0, size = 0;
	cout << "Введите размер массива: ";
	cin >> size;
	initialArray = new int[size];
	initialArray = fillArray(size, initialArray);
	cout << "Было: ";
	for (i = 0; i < size; i++) {
		cout << initialArray[i] << " ";
	}
	cout << endl;
	numberOfReplaces = MODIFY_ARRAY(initialArray, size);
	cout << endl << "Стало: ";
	for (i = 0; i < size; i++) {
		cout << initialArray[i] << " ";
	}
	cout << endl;
	cout << "Количество замен: " << numberOfReplaces << endl;
	initialArray = nullptr;
	return 0;
}
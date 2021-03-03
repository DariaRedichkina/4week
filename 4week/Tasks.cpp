#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main() {
	vector <int> P1(15);
	for (int i = 0; i < 10; i++) {
		P1[i] = i+1;
	}
	cout << "Enter 5 random numbers\n";
	for (int j = 0; j < 5; j++) {
		cin >> P1[j+10];
	}

	for (int l = 0; l < 15; l++) {
		cout << P1[l] << " ";
	}
	/*
	for (int k = 0; k < 15; k++) {
		int r = k + rand() % (15 - k); 
		swap(P1[k], P1[r]);
	}
	*/
	random_device rd;
	mt19937 g(rd());

	shuffle(P1.begin(), P1.end(), g);
	
	for (int l = 0; l < 15; l++) {
		cout << P1[l] << " ";
	}

	return 0;
}
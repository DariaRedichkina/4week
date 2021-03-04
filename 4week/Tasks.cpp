#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

bool is_prime(int n)
{
	int i, count = 0;
	if (n == 1)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (i = 1; i <= n; i++)
		if (n % i == 0) count++;
	if (count == 2)   
		return true;
	else
		return false;
}

int main() {
	vector <int> P1(15);
	for (int i = 0; i < 10; i++) {
		P1[i] = i+1;
	}
	cout << "Enter 5 random numbers\n";
	for (int j = 0; j < 5; j++) {
		cin >> P1[j+10];
	}

	cout << "sequence before any changes: ";
	for (int l = 0; l < 15; l++) {
		cout << P1[l] << " ";
	}
	cout << endl;
	/*
	for (int k = 0; k < 15; k++) {
		int r = k + rand() % (15 - k); 
		swap(P1[k], P1[r]);
	}
	*/
	random_device rd;
	mt19937 g(rd());

	shuffle(P1.begin(), P1.end(), g);
	
	cout << "sequence after mixing: ";
	for (int l = 0; l < 15; l++) {
		cout << P1[l] << " ";
	}
	cout << endl;

	sort(P1.begin(), P1.end());
	vector <int>::iterator it;
	it = unique(P1.begin(), P1.end());
	P1.resize(distance(P1.begin(), it));

	cout << "sequence after deleting duplicate items: ";
	int sizeOF = P1.size();
	for (int l = 0; l < sizeOF; l++) {
		cout << P1[l] << " ";
	}
	cout << endl;

	int counter = 0; //создан счётчик нечётных чисел
	for (int i = 0; i < sizeOF; i++) {
		if (P1[i] % 2 != 0)
			counter++;
	}
	cout << "number of odd elements: " << counter << endl;

	int s = 0; //создан элемент для сравнения его со всеми элементами вектора
	for (int i = 0; i < sizeOF; i++) {
		if (P1[i] > s)
			s = P1[i];
	}
	cout << "MAX: " << s << endl;

	for (int i = 0; i < sizeOF; i++) {
		if (P1[i] < s)
			s = P1[i];
	}
	cout << "min: " << s << endl;

	cout << "prime numbers: ";
	for (int i = 0; i < sizeOF; i++) {

		if (is_prime(P1[i]))
			cout << P1[i] << " ";
	}
	cout << endl;

	int N = sizeOF;
	vector <int> P2(N);
	for (int i = 0; i < N; i++){
		P2[i] = rand() / 1000;
	}
	cout << "new sequence: ";
	for (int i = 0; i < sizeOF; i++) {
		cout << P2[i] << " ";
	}
	cout << endl;

	int sum = 0;
	for (int i = 0; i < sizeOF; i++) {
		sum = sum + P2[i];
	}
	cout << "sequence P2 sum: " << sum << endl;

	return 0;
}
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

	int counter = 0; //������ ������� �������� �����
	for (int i = 0; i < sizeOF; i++) {
		if (P1[i] % 2 != 0)
			counter++;
	}
	cout << "number of odd elements: " << counter << endl;

	int s = 0; //������ ������� ��� ��������� ��� �� ����� ���������� �������
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

	cout << "in the sequence P1, all the elements are replaced with their squares: ";
	for (int i = 0; i < sizeOF; i++) {
		P1[i] = P1[i] * P1[i];
		cout << P1[i] << " ";
	}
	cout << endl;

	int N = sizeOF;
	vector <int> P2(N);
	for (int i = 0; i < N; i++){
		P2[i] = rand() / 100;
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

	cout << "enter a number that does not exceed " << N << ":  ";
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		P2[i] = 1;
	}
	cout << endl << "sequence after replacing some of the first elements with 1: ";
	for (int i = 0; i < sizeOF; i++) {
		cout << P2[i] << " ";
	}
	cout << endl;

	vector <int> P3(N);
	for (int i = 0; i < N; i++) {
		P3[i] = P1[i] - P2[i];
	}
	cout << "sequence P3 obtained by subtracting P2 from P1: ";
	for (int i = 0; i < sizeOF; i++) {
		cout << P3[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < sizeOF; i++) {
		if (P3[i] < 0)
			P3[i] = 0;
	}
	cout << "sequence without negative elements: ";
	for (int i = 0; i < sizeOF; i++) {
		cout << P3[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < sizeOF; i++) {
		if (P3[i] == 0) {
			P3.erase(P3.begin() + i);
			sizeOF--;
			i--;
		}
	}
	sizeOF = P3.size();
	cout << "sequence without 0: ";
	for (int i = 0; i < sizeOF; i++) {
		cout << P3[i] << " ";
	}
	cout << endl;

	reverse(P3.begin(), P3.end());
	cout << "reversed sequence P3: ";
	for (int i = 0; i < sizeOF; i++) {
		cout << P3[i] << " ";
	}
	cout << endl;

	sort(P3.begin(), P3.end());
	cout << "top 3 largest elements of the P3 sequence: ";
	for (int i = sizeOF-3; i < sizeOF; i++) {
		cout << P3[i] << " ";
	}
	cout << endl;

	//���������� P1
	sort(P1.begin(), P1.end());
	cout << "sorted sequence P1: ";
	for (int i = 0; i < N; i++) {
		cout << P1[i] << " ";
	}
	cout << endl;
	//���������� P2
	sort(P2.begin(), P2.end());
	cout << "sorted sequence P2: ";
	for (int i = 0; i < N; i++) {
		cout << P2[i] << " ";
	}
	cout << endl;

	int S4 = N * 2;
	vector <int> P4(S4);
	for (int i = 0; i < N; i++) {
		P4[i] = P1[i];
	}
	for (int i = N; i < S4; i++) {
		P4[i] = P2[i-N];
	}
	cout << "sequence P4 composed of P1 and P2: ";
	for (int i = 0; i < S4; i++) {
		cout << P4[i] << " ";
	}
	cout << endl;

	return 0;
}
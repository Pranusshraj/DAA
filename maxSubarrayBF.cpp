#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
using namespace std;

int A[10000],count,n;
int max_sum,l,h;

void genInputFile() {
	ofstream fout("input_maxSubarray.txt");
	srand((long int) clock());
	for(int i=0 ; i<10000 ; i++) {
		int num = rand() % 30;
		if(rand()%2 == 0)
			fout << -1*num << "\t";
		else
			fout << num << "\t";
	}
	fout.close();
}

void getInput() {
	ifstream fin("input_maxSubarray.txt");
	for(int i=0 ; i<n ; i++) {
		fin >> A[i];
	}
	fin.close();
}

void maxSubarrayBF() {
	max_sum = -1*INT_MAX;
	for(int i=1; i<n ; i++) {
		int sum = 0;
		for(int j=i; j<n; j++) {
			count++;
			sum += A[j];
			if(sum > max_sum) {
				max_sum = sum;
				l = i;
				h = j;
			}
		}
	}
}

int main() {
	genInputFile();
	do {
		cout << "\n\nEnter the size of the array : ";
		cin >> n;
		count = 0;
		getInput();
		maxSubarrayBF();
		cout << "Lower bound = " << l;
		cout << "\nHigher bound = " << h;
		cout << "\nMaximum sum = " << max_sum;
		cout << "\nCount = " << count;
	}while(true);
	return 0;
}

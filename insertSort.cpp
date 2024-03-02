#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){ 

	do {
		long int arr[11000];
		int n,type,count=0;
		cout << "1.Random Input \n2.Ascending Input  \n3.Descending Input \n4.Equal Input";
		cout << "\nEnter input type : ";
		cin >> type;
		cout << "\nEnter the size of the array : ";
		cin >> n;

		char file[16];
		switch(type) {
			case 1:
				strcpy(file,"input.txt");
				break;
			case 2:
				strcpy(file,"input-asc.txt");
				break;
			case 3:
				strcpy(file,"input-desc.txt");
				break;
			case 4:
				strcpy(file,"input-equal.txt");
				break;
		}
		ifstream fin(file);
		for(int i=0; i<n; i++) {
			fin >> arr[i];
		}
		fin.close();

		for(int j=1; j <n ; j++) {
			int key = arr[j];
			int i = j-1;
			while(i>=0 && arr[i]>key) {
				count++;
				arr[i+1] = arr[i];
				i--;
			}
			count++;
			arr[i+1] = key;
		}
	
		ofstream fout("output.txt");
		for(int i=0; i<n; i++) {
			fout << arr[i] << "\t";
		}
		fout.close();

		cout << "Count : " << count <<"\n\n\n"; 
	}while(true);
	return 0;	
}

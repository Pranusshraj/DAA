#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
using namespace std;

const int MAX_SIZE = 10;

void genInputFile(int p[], int n)
{
	ofstream fout("input_mcm.txt");
	srand((long int) clock());
    for(int i=0; i<n; i++) {
        fout << rand() % 30 << "\t";
    } 
    fout.close();
}

void getInput(int p[], int n) {
    ifstream fin;
    fin.open("input_mcm.txt");
    for(int i=0; i<n; i++) {
        fin >> p[i];
    }
    fin.close();
}

//------------------------------------------------------------------------------------------------

int REC_MAT_CHAIN(int p[],int i,int j,int &count) {
    if(i==j)   {
        return 0;
    } 
    long int t = LONG_MAX;
    for(int k=i; k<=j-1; k++) {
        count++;
        long int q = REC_MAT_CHAIN(p,i,k,count) + REC_MAT_CHAIN(p,k+1,j,count) + p[i-1]*p[k]*p[j];
        if(q < t) {
            t = q;
        }
    } return t;
}

//------------------------------------------------------------------------------------------------

int main() {
    int n,count = 0;
    cout << "No. of Dimensions : ";
    cin >> n;
    int p[n];
    genInputFile(p,n);
    getInput(p,n);
    cout << "P :\t";
    for(int i=0; i<n; i++) {
        cout << p[i] << "\t";
    }
    cout << "\n\n";

    int minOperations = REC_MAT_CHAIN(p, 1, n, count);

    cout << "Min no. of multiplications: " << minOperations << endl;
    cout << "No. of recursive calls: " << count << endl;
}

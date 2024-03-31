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

int LOOKUP_CHAIN(int m[][100], int p[], int i, int j, int &count) {
    if(m[i][j] < INT_MAX) {
        return m[i][j];
    }
    if(i==j){
        m[i][j] = 0;
    }
    else {
        for(int k=i; k<=j-1; k++) {
            count ++;
            long int q = LOOKUP_CHAIN(m,p,i,k,count) + LOOKUP_CHAIN(m,p,k+1,j,count) + p[i-1]*p[k]*p[j];
        }
    }
}
int MEMOIZED_MATRIX_CHAIN(int p[],int n,int &count) {
    n -= 1;
    int m[100][100];
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            m[i][j] = INT_MAX;
        }
    }
    return LOOKUP_CHAIN(m,p,1,n,count);
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

    int temp = MEMOIZED_MATRIX_CHAIN(p, n, count);

    cout << "No. of recursive calls: " << count << endl;
}

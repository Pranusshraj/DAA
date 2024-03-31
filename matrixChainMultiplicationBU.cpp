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


void Print_Opt_Order(int n, int s[][100], int i, int j) {
    //when passing multidimensional arrays as function parameters, specify the size of all dimensions except the first one.
    if(i==j) {
        cout << "A" << i;
    }
    else {
        cout << "(" ;
        Print_Opt_Order(n,s,i,s[i][j]);
        Print_Opt_Order(n,s,s[i][j]+1,j);
        cout << ")" ;
    }
}

void Matrix_Chain_Order(int p[], int n, int &count) {
    n -= 1;
    int m[100][100],s[100][100];
    int q,k;
    for(int i=1; i<=n; i++) {
        m[i][i] = 0;
    }

    for(int l=2; l<=n; l++) {
        for(int i=1; i<=n-l+1; i++) {
            int j = i+l-1;
            m[i][j] = INT_MAX;
           
            for(k=i; k<=j-1; k++) {
                count = count + 1;
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    } 
    Print_Opt_Order(n,s,1,n);
}

//------------------------------------------------------------------------------------------------

int main() {
    int n,count = 0;
    cout << "No. of Arrays : ";
    cin >> n;
    n = n+1;
    int p[n];
    genInputFile(p,n);
    getInput(p,n);
    cout << "P :\t";
    for(int i=0; i<n; i++) {
        cout << p[i] << "\t";
    }
    cout << "\n\n";
    
    Matrix_Chain_Order(p,n,count);

    cout << "\n\nCount = " << count;
}


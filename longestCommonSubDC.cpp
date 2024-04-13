#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstring>
using namespace std;

void genInputFile(int m, int n) {
    char S[] = {'A','B','C'};
    ofstream fout("lcs_input.txt");
    for(int i=0; i < m; i++) {
        fout << S[rand() % 3];
    }
    fout << endl;
    for(int i=0; i < n; i++) {
        fout << S[rand() % 3];
    }
    fout.close();
}

void getInput(string &X, string &Y, int m, int n) {
    ifstream fin("lcs_input.txt");
    getline(fin,X);
    cout << "X : " << X << endl;
    getline(fin,Y);
    cout << "Y : " << Y << endl;
    fin.close();
}

//------------------------------------------------------------------------------------------------

int LCS_LENGTH_DC(string X, string Y, int m, int n, int &count) {
    count += 1;
    if(m==0 || n==0) {
        return 0;
    }
    else {
        if(X[m-1] == Y[n-1]) {
            return 1 + LCS_LENGTH_DC(X,Y,m-1,n-1,count);
        }
        else {
            int t1 = LCS_LENGTH_DC(X,Y,m-1,n,count);
            int t2 = LCS_LENGTH_DC(X,Y,m,n-1,count);
            if(t1 >= t2) {
                return t1; 
            }
            else {
                return t2;
            }
        }
    }
}

//------------------------------------------------------------------------------------------------

int main() {
    int m,n;
    cout << "Length of 1st String(M) : ";
    cin >> m;
    cout << "Length of 2nd String(N) : ";
    cin >> n;
    genInputFile(m,n);  
    string X,Y;
    getInput(X,Y,m,n);

    int lcs_length,count=0;
    lcs_length = LCS_LENGTH_DC(X,Y,m,n,count);

    cout << "\nUsing Divide and Conquer Approach\n";
    cout << "LCS length : " << lcs_length;
    cout << "\nComparisions : " << count;
}

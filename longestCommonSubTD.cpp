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

int LCS_LENGTH_TD(string X, string Y, int** C, int i, int j, int& count) {
    if (i == 0 || j == 0)
        return 0;
    
    if (C[i][j] != -1)
        return C[i][j];
    
    count++; 
    
    if (X[i - 1] == Y[j - 1]) {
        C[i][j] = LCS_LENGTH_TD(X, Y, C, i - 1, j - 1, count) + 1;
    } else {
        C[i][j] = max(LCS_LENGTH_TD(X, Y, C, i - 1, j, count), LCS_LENGTH_TD(X, Y, C, i, j - 1, count));
    }
    
    return C[i][j];
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
    int** C = new int*[m + 1];
    for (int i = 0; i <= m; ++i) {
        C[i] = new int[n + 1];
        for (int j = 0; j <= n; ++j) {
            C[i][j] = -1;
        }
    }

    lcs_length = LCS_LENGTH_TD(X,Y,C,m,n,count);

    for (int i = 0; i <= m; ++i) {
        delete[] C[i];
    }
    delete[] C;
    //deallocating memory for the table 

    cout << "\nUsing Top Down Approach\n";
    cout << "LCS length : " << lcs_length;
    cout << "\nComparisions : " << count;
}

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

void PRINT_LCS(string X, int i, int j) {
    if (i == 0 || j == 0)
        return;
    
    if (B[i][j] == '↖') {
        PRINT_LCS(X, B, i - 1, j - 1);
        cout << X[i - 1];
    } 
    else if (B[i][j] == '↑') {
        PRINT_LCS(X, B, i - 1, j);
    } 
    else {
        PRINT_LCS(X, B, i, j - 1);
    }
}

int LCS_LENGTH_BU(string X, string Y, int m, int n, int &count) {
    int C[m+1][n+1];
    for(int i=0; i <= m; i++) {
        C[i][0] = 0;
    }
    for(int j=0; j <= n; j++) {
        C[0][j] = 0;
    }

    for(int i=1; i <= m; i++) {
        for(int j=1; j <= n; j++) {
            count += 1;
            if(X[i-1] == Y[j-1]) {
                C[i][j] = 1 + C[i-1][j-1];
            }
            else if(C[i-1][j] >= C[i][j-1]) {
                C[i][j] = C[i-1][j];
            }
            else {
                C[i][j] = C[i][j-1];
            }
        }
    }
    
    return C[m][n];
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
    lcs_length = LCS_LENGTH_BU(X,Y,m,n,count);

    cout << "\nUsing Bottom Up Approach\n";
    cout << "LCS length : " << lcs_length;
    cout << "\nComparisions : " << count;
}

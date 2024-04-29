#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int charcode(char c) {
    switch(c) {
        case 'A': return 1;
        case 'B': return 2;
        case 'C': return 3;
        case 'G': return 4;
        case 'T': return 5;
        case 'X': return 6;
        default: return 0; 
    }
}

int preprocess(const std::string& P, int d, int q) {
    int m = P.length();
    int p = 0;

    for (int i = 0; i < m; ++i) {
        p = (d * p + charcode(P[i])) % q;
    }

    return p;
}

void rkMatcher(const std::string& T, const std::string& P, int p, int d, int q) {
    int n = T.length();
    int m = P.length();
    int h = 1;

    for (int i = 1; i <= m - 1; ++i) {
        h = (h * d) % q;
    }

    int count = 0;
    int t0 = 0;
    for (int i = 0; i < m; ++i) {
        t0 = (d * t0 + charcode(T[i])) % q;
    }

    for (int s = 0; s <= n - m; ++s) {
        if (p == t0) {
            int flag = 0;
            for (int j = 0; j < m; ++j) {
                if (P[j] != T[s + j]) {
                    flag = 1;
                    break;
                }
                count++;
            }
            if (flag == 0) {
                std::cout << "Pattern occurs with valid shift " << s << std::endl;
            }
        }

        if (s < n - m) {
            int ts1 = (d * (t0 - charcode(T[s]) * h) + charcode(T[s + m])) % q;
            if (ts1 < 0) {
                ts1 = (ts1 + q) % q;
            }
            t0 = ts1;
            count++;
        }
    }

    std::cout << "Total comparisons made: " << count << std::endl;
}

int main() {
    string text1 = "ABABCABABACABABCCABABCABAB";
	string text2="ABABABCABABCABABCCABABABCABABABB";
	string text3="AABABCABCABABCABACABABCABABCABAC";
    string pattern = "ABABCABAB";

    int d = 10;
    int q = 4999;

    int p = preprocess(pattern, d, q);

    rkMatcher(text1, pattern, p, d, q);
	rkMatcher(text2, pattern, p, d, q);
	rkMatcher(text3, pattern, p, d, q);

    cout<<"\n\n";
}
#include <iostream>
#include <string>
using namespace std;
// Function to compute the prefix function (π) for the pattern (P)
void computePrefix(const std::string& P, int pi[]) {
    int m = P.length();
    pi[0] = 0;
    int k = 0;

    int count = 0;
    for (int q = 1; q < m; ++q) {
        count++;

        while (k > 0 && P[k] != P[q]) {
            k = pi[k - 1];
            count++;
        }

        if (P[k] == P[q]) {
            k++;
        }

        pi[q] = k;
    }

    std::cout << "Preprocessing Pattern count = " << count << std::endl;
}

// Function to perform string matching using the KMP algorithm
void kmpMatcher(const std::string& T, const std::string& P, const int pi[]) {
    int n = T.length();
    int m = P.length();
    int count = 0;
    int q = 0;

    for (int i = 0; i < n; ++i) {
        count++;

        while (q > 0 && P[q] != T[i]) {
            q = pi[q - 1];
            count++;
        }

        if (P[q] == T[i]) {
            q++;
        }

        if (q == m) {
            std::cout << "Pattern occurs with valid shift " << (i - m + 1) << std::endl;
            q = pi[q - 1];
        }
    }

    std::cout << "Total comparisons made: " << count << std::endl;
}

int main() {
    std::string text1 = "ABABCABABACABABCCABABCABAB";
	string text2="ABABABCABABCABABCCABABABCABABABB";
	string text3="AABABCABCABABCABACABABCABABCABAC";
    std::string pattern = "ABABCABAB";

    int m = pattern.length();
    int pi[m];

    // Compute prefix function for the pattern
    computePrefix(pattern, pi);

    // Apply KMP algorithm to find pattern in text
    kmpMatcher(text1, pattern, pi);
	kmpMatcher(text2, pattern, pi);
	kmpMatcher(text3, pattern, pi);
    return 0;
}
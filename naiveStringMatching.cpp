#include <iostream>
#include <string>

using namespace std;

int naivePatternMatch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int count = 0;

    for (int i = 0; i <= n - m; ++i) {
        int flag = 0;
        for (int j = 0; j < m; ++j) {
            count++;
            if (pattern[j] != text[i + j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            cout << "Pattern occurs with valid shift " << i << endl;
        }
    }

    return count;
}

int main() {
    string text = "ABABABCABABABCABABABC";
    string pattern = "ABABA";

    int count = naivePatternMatch(text, pattern);
    cout << "Total comparisons: " << count << endl;

    return 0;
}

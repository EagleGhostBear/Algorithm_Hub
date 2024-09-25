#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string tmp;
        int consonants = 0;
        int vowels = 0;
        getline(cin, tmp);
        for (char c : tmp) {
            if (isalpha(c)) { // 알파벳인 경우만 체크
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                    vowels++;
                }
                else {
                    consonants++;
                }
            }
        }
        cout << consonants << " " << vowels << "\n";
    }
}
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch) {
    // 모음인지 확인하는 함수 (대소문자 모두 처리)
    ch = tolower(ch); // 문자를 소문자로 변환
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    int S;
    cin >> S; // 문장의 개수를 입력받음
    cin.ignore(); // 남아있는 개행문자 제거

    for (int i = 0; i < S; i++) {
        string sentence;
        getline(cin, sentence); // 한 줄씩 문장 입력받음

        int vowels = 0, consonants = 0;

        for (char ch : sentence) {
            if (isalpha(ch)) { // 문자가 알파벳일 때만 처리
                if (isVowel(ch)) {
                    vowels++;
                }
                else {
                    consonants++;
                }
            }
        }

        cout << consonants << " " << vowels << endl; // 자음과 모음 개수 출력
    }

    return 0;
}

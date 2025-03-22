#include <iostream>

using namespace std;

int a, b;

// 최대공약수를 계산하는 함수 (유클리드 알고리즘)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;

    // Greatest Common Divisor(최대공약수)
    int gcd_num = gcd(a, b);

    // Least Common Multiple(최소공배수)
    int lcm_num = a * b / gcd_num;

    cout << gcd_num << "\n" << lcm_num;
}
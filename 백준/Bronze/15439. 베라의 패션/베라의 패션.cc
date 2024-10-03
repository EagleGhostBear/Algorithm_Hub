#include <iostream>
#include <string>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    cout << n*(n-1);
}
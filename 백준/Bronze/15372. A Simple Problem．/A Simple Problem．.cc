#include <iostream>
#include <string>

using namespace std;

int t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    for(int i=0; i<t; i++){
        long long n;
        cin >> n;
        cout << n*n << "\n";
    }
}
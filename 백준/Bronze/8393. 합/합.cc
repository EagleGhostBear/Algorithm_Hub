#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    int total = 0;
    for(int i=n; i>0; i--){
        total += i;
    }
    cout << total;
}
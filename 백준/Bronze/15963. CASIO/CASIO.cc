#include <iostream>
#include <string>

using namespace std;

long long a[2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> a[0] >> a[1];
    if(a[0]==a[1]){cout << "1";}
    else{cout << "0";}
}
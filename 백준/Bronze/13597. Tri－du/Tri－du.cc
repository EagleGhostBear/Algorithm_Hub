#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int a, b;
    cin >> a >> b;
    if(a==b){
        cout << a;
    }
    else{
        cout << max(a, b);
    }
}
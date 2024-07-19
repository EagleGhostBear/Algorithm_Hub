#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(1){
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0){
            break;
        }
        cout << a + b << "\n";
    }
}
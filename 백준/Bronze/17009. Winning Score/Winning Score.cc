#include <iostream>
#include <string>

using namespace std;

int n, a = 0, b = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for(int i=3; i>0; i--){
        cin >> n;
        n *= i;
        a += n;
    }
    for(int i=3; i>0; i--){
        cin >> n;
        n *= i;
        b += n;
    }
    if(a==b){
        cout << "T";
    }
    else if(a>b){
        cout << "A";
    }
    else{
        cout << "B";
    }
}
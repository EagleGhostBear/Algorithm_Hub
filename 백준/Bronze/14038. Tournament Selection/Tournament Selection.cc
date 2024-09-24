#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    char c;
    int w = 0;
    for(int i=0; i<6; i++){
        cin >> c;
        if(c == 'W'){
            w++;
        }
    }
    if(w>=5){
        cout << "1";
    }
    else if(w>=3){
        cout << "2";
    }
    else if(w>=1){
        cout << "3";
    }
    else{
        cout << "-1";
    }
}
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    if(n%4==0){
        if(n%400==0){
            cout << "1";
        }
        else if(n%100!=0){
            cout << "1";
        }
        else{
            cout << "0";
        }
    }
    else{
        cout << "0";
    }
}
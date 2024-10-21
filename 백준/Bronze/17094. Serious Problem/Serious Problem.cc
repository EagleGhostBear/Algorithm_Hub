#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    vector<int> v(2);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if(c == '2'){
            v[0]++;
        }
        else{
            v[1]++;
        }
    }
    
    if(v[0] > v[1]){
        cout << "2";
    }
    else if(v[0] < v[1]){
        cout << "e";
    }
    else{
        cout << "yee";
    }
}
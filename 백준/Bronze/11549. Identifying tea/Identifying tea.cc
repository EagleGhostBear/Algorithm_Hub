#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int ans;
    int total = 0;
    cin >> ans;
    for(int i=0; i<5; i++){
        int tmp;
        cin >> tmp;
        if(tmp == ans){
            total++;
        }
    }
    cout << total;
}
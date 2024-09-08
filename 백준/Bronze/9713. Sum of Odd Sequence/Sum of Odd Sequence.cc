#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t, n;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        int total = 0;
        for(int j=1; j<=n; j++){
            if(j%2==0){
                continue;
            }
            total += j;
        }
        cout << total << "\n";
    }
}
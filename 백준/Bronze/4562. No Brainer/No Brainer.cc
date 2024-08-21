#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        if(a>=b){
            cout << "MMM BRAINS\n";
        }
        else{
            cout << "NO BRAINS\n";
        }
    }
}
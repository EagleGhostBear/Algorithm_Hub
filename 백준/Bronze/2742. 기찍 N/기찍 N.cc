#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=n; i>0; i--){
        cout << i << "\n";
    }
}
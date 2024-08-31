#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int v[13] = {9, 7, 8, 0, 9, 2, 1, 4, 1, 8, 0, 0, 0};
    int total = 0;
    
    cin >> v[10] >> v[11] >> v[12];
    for(int i=0; i<13; i++){
        if(i%2==0){
            total += v[i]*1;
        }
        else{
            total += v[i]*3;
        }
    }
    
    cout << "The 1-3-sum is " << total;
}
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i=0; i<3; i++){
        int a;
        cin >> a;
        pq.push(a);
    }
    pq.pop();
    cout << pq.top();
}
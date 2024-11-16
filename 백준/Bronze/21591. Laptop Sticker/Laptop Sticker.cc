#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a-c>=2 && b-d>=2){
        cout << "1";
    }
    else{
        cout << "0";
    }
}
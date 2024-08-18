#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<3; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    for(auto s : v){
        cout << s << " ";
    }
}
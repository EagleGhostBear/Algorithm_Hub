#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v;

int solution(int x, int y, int n) {
    v.resize(y + 1, 1e7);
    v[x] = 0;
    for(int i=x; i<=y; i++){
        if(i - n >= x) v[i] = min(v[i], v[i - n] + 1);
        if(i % 2 == 0 && i / 2 >= x) v[i] = min(v[i], v[i/2] + 1);
        if(i % 3 == 0 && i / 3 >= x) v[i] = min(v[i], v[i/3] + 1);
    }
    
    if(v[y] == 1e7) return -1;
    else return v[y];
}
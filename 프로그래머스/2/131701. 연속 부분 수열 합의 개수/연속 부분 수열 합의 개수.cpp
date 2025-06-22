#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<int, bool> um;

int solution(vector<int> elements) {
    int sz = elements.size();
    for(int i=0;i <sz; i++){ // 1000 * 1000
        int total = 0;
        for(int len=0; len<sz; len++){
            if(i + len < sz) total += elements[i + len];
            else total += elements[i + len - sz];
            um[total] = true;
        }
    }
    return um.size();
}
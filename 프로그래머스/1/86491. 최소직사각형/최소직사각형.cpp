#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    pair<int, int> v = {0, 0};
    for(int i=0; i<sizes.size(); i++){
        sort(sizes[i].begin(), sizes[i].end());
        v.first = max(v.first, sizes[i][0]);
        v.second = max(v.second, sizes[i][1]);
    }
    return v.first * v.second;
}
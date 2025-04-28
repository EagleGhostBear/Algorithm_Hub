#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> v;

int solution(vector<int> mats, vector<vector<string>> park) {
    v.resize(park.size(), vector<int>(park[0].size(), 0));
    for(int i=0; i<park.size(); i++){
        for(int j=0; j<park[i].size(); j++){
            if(park[i][j] == "-1"){
                if(i == 0 || j == 0) v[i][j] = 1;
                else v[i][j] = min({v[i-1][j], v[i][j-1], v[i-1][j-1]}) + 1;
            }
        }
    }
    
    sort(mats.begin(), mats.end());
    int ans = -1, idx = 0;
    for(int i=v.size() - 1; i>-1; i--){
        for(int j=v[i].size() - 1; j>-1; j--){
            while(v[i][j] >= mats[idx]){
                ans = max(ans, mats[idx++]);
                if(idx >= mats.size()) return ans;
            }
        }
    }
    return ans;
}
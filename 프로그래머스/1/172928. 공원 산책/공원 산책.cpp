#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> v;
vector<int> ans(2);

vector<int> solution(vector<string> park, vector<string> routes) {
    v.resize(park.size(), vector<int>(park[0].size(), 0));
    for(int i=0; i<park.size(); i++){
        for(int j=0; j<park[i].size(); j++){
            if(park[i][j] == 'S') ans = {i, j};
            else if(park[i][j] == 'X') v[i][j] = 1;
        }
    }
    
    for(int i=0; i<routes.size(); i++){
        int n = int(routes[i][routes[i].size() - 1]) - int('0');
        bool chk = true;
        int row = ans[0];
        int col = ans[1];
        while(n--){
            if(routes[i][0] == 'N') row--;
            else if(routes[i][0] == 'S') row++;
            else if(routes[i][0] == 'W') col--;
            else if(routes[i][0] == 'E') col++;
            if(row < 0 || col < 0 || row >= v.size() || col >= v[0].size() || v[row][col]){
                chk = false;
                break;
            }
        }
        if(chk) ans = {row, col};
    }
    return ans;
}
#include <string>
#include <vector>

using namespace std;

pair<int, int> left = {100, 100};
pair<int, int> right;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    for(int i=0; i<wallpaper.size(); i++){
        for(int j=0; j<wallpaper[i].size(); j++){
            if(wallpaper[i][j] == '#'){
                left.first = min(left.first, i);
                left.second = min(left.second, j);
                right.first = max(right.first, i + 1);
                right.second = max(right.second, j + 1);
            }
        }
    }
    answer.push_back(left.first);
    answer.push_back(left.second);
    answer.push_back(right.first);
    answer.push_back(right.second);
    return answer;
}
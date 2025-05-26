#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string tmp = s;
    while(tmp.size()){
        char target = tmp[0];
        pair<int, int> cnt = {1, 0};
        for(int i=1; i<tmp.size(); i++){
            if(tmp[i] == target) cnt.first++;
            else{
                cnt.second++;
                if(cnt.first == cnt.second){
                    answer++;
                    // cout << tmp.substr(0, i + 1) << " " << tmp.substr(i + 1) << "\n";
                    tmp = tmp.substr(i + 1);
                    break;
                }
            }
        }
        if(cnt.first != cnt.second){
            answer++;
            break;
        }
    }
    return answer;
}
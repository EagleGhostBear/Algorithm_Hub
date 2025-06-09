#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for(int i=0; i<babbling.size(); i++){
        int prev = -1;
        string now = babbling[i];
        while(now.size() > 1){
            if (now.size() > 2 && now.substr(0, 3) == "aya") {
                if (prev == 0) break;
                else prev = 0;
                now = now.substr(3);
            }
            else if (now.size() > 2 && now.substr(0, 3) == "woo") {
                if (prev == 1) break;
                else prev = 1;
                now = now.substr(3);
            }
            else if (now.size() > 1 && now.substr(0, 2) == "ye") {
                if (prev == 2) break;
                else prev = 2;
                now = now.substr(2);
            }
            else if (now.size() > 1 && now.substr(0, 2) == "ma") {
                if (prev == 3) break;
                else prev = 3;
                now = now.substr(2);
            }
            else break;
        }
        if(!now.size()) answer++;
    }
    return answer;
}
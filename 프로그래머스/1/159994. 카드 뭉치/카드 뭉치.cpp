#include <string>
#include <vector>

using namespace std;

int idx1 = 0, idx2 = 0;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    for(int i=0; i<goal.size(); i++){
        string now = goal[i];
        if(now == cards1[idx1]){
            idx1++;
            continue;
        }
        else if(now == cards2[idx2]){
            idx2++;
            continue;
        }
        return "No";
    }
    return "Yes";
}
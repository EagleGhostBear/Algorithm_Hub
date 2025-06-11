#include <string>
#include <vector>

using namespace std;

vector<int> v(26, 0);

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for(int i=0; i<survey.size(); i++){
        if(choices[i] < 4){
            v[survey[i][0] - 'A'] += (4 - choices[i]);
        }
        else if(choices[i] > 4){
            v[survey[i][1] - 'A'] += (choices[i] - 4);
        }
    }
    if(v['R' - 'A'] >= v['T' - 'A']) answer += "R";
    else answer += "T";
    
    if(v['C' - 'A'] >= v['F' - 'A']) answer += "C";
    else answer += "F";
    
    if(v['J' - 'A'] >= v['M' - 'A']) answer += "J";
    else answer += "M";
    
    if(v['A' - 'A'] >= v['N' - 'A']) answer += "A";
    else answer += "N";
    return answer;
}
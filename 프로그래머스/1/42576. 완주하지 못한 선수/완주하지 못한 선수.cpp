#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> um;

string solution(vector<string> participant, vector<string> completion) {
    for(auto s : participant) um[s]++;
    for(auto s : completion) um[s]--;
    for(auto d : um) if(d.second) return d.first;
}
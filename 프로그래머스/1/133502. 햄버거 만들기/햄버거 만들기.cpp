#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v;

int solution(vector<int> ingredient) {
    int answer = 0;
    for(int i=0; i<ingredient.size(); i++){
        if(ingredient[i] == 1){
            if(v.size() && v.back() == 3) v.pop_back(), answer++;
            else v.push_back(1);
        }
        else if(ingredient[i] == 2 && v.size()){
            if(v.back() == 1) v.back()++;
            else v.clear();
        }
        else if(ingredient[i] == 3 && v.size()){
            if(v.back() == 2) v.back()++;
            else v.clear();
        }
    }
    return answer;
}
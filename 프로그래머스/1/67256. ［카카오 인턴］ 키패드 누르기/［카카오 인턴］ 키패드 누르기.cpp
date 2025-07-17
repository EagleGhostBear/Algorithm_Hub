#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left = {0, 3}, right = {2, 3};
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            left = {0, (numbers[i] - 1)/3};
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            right = {2, (numbers[i] - 3)/3};
        }
        else{
            pair<int, int> mid = {1, 3};
            if(numbers[i]) mid.second = (numbers[i] - 2)/3;
            if(abs(mid.first - left.first) + abs(mid.second - left.second) < abs(mid.first - right.first) + abs(mid.second - right.second)){
                answer += "L";
                left = mid;
            }
            else if(abs(mid.first - left.first) + abs(mid.second - left.second) > abs(mid.first - right.first) + abs(mid.second - right.second)){
                answer += "R";
                right = mid;
            }
            else{
                if(hand == "left"){
                    answer += "L";
                    left = mid;
                }
                else if(hand == "right"){
                    answer += "R";
                    right = mid;
                }
            }
        }
    }
    return answer;
}
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string tmp = "";
    for(int i=1; i<food.size(); i++){
        for(int j=0; j<food[i]/2; j++) tmp += i + '0';
    }
    answer += tmp + "0";
    for(int i=tmp.size() - 1; i>-1; i--) answer += tmp[i];
    return answer;
}
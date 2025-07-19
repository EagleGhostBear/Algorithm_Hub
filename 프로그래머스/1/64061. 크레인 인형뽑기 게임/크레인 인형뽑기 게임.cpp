#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, size = board.size();
    stack<int> st;
    for (auto move : moves) {
        int target = 0; move--;// move가 1부터 시작하므로 --
        for (int i=0; i<size; i++) {
            if (board[i][move]) {// 인형이 있으면
                target = board[i][move];// 타겟 갱신
                board[i][move] = 0;// 인형 뽑았으니 빈공간
                break ;
            }
        }
        if (!st.empty() && st.top() == target) {// 비어있지않고 이전인형이 현재 인형과 같다면
            st.pop();
            answer+=2;
        }
        else if (target) st.push(target);//아니면 인형을 넣어준다.
    }
    return answer;
}
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int conHor = 1, conVer = 1;
        int prev = hBars[0], len = 1;
        for(int i=1; i<hBars.size(); i++){
            if(hBars[i] - prev == 1) len++;
            else{
                conHor = max(conHor, len);
                len = 1;
            }
            prev = hBars[i];
        }
        conHor = max(conHor, len);

        prev = vBars[0], len = 1;
        for(int i=1; i<vBars.size(); i++){
            if(vBars[i] - prev == 1) len++;
            else{
                conVer = max(conVer, len);
                len = 1;
            }
            prev = vBars[i];
        }
        conVer = max(conVer, len);
        int availSize = min(conHor + 1, conVer + 1);
        return pow(availSize, 2);
    }
};
/*
전부다 빼본다X -> 정사각형이 안될 수 있음
사각형이 개큰데 최대 뺄 수 있는건 100개뿐
앞의 선택이 뒤에 영향을 줌 -> dp?
빼는 순서는 상관없음 -> 의미가 있는것 -> 연속된걸 뺄때
단, 정사각형이 될려면 : 가로에서 빼는 수 = 세로에서 빼는 수
*/
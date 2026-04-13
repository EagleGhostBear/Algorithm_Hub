class Robot {
public:
    vector<vector<int>> board;
    pair<int, int> rb;
    // 우, 상, 좌, 후
    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {1, 0, -1, 0};
    int dir = 0;
    int h, w;
    Robot(int width, int height) {
        dir = 0;
        board.assign(height, vector<int>(width, 0));
        rb = {height - 1, 0};
        h = height, w = width;
    }
    
    void step(int num) {
        // 일단 벽에 붙고 난뒤부터는
        // 2(h + w) 만큼 돌면 제자리로 돌아온다

        // 벽에 붙이기
        if(dir == 0 && num >= w - 1 - rb.second){ // col == w?
            num -= w - 1 - rb.second;
            rb.second = w - 1;
        }
        else if(dir == 1 && num >= rb.first){ // row == 0?
            num -= rb.first;
            rb.first = 0;
        }
        else if(dir == 2 && num >= rb.second){ // col == 0?
            num -= rb.second;
            rb.second = 0;
        }
        else if(dir == 3 && num >= h - 1 - rb.first){ // row == h?
            num -= h - 1 - rb.first;
            rb.first = h - 1;
        }

        // 제자리로 돌아만큼의 이동횟수를 가진다면 나눈다.
        int cycle = 2 * (h + w - 2);
        num %= cycle;

        // 한칸씩 전진
        for(int i=0; i<num; i++){
            int nr = rb.first + dr[dir];
            int nc = rb.second + dc[dir];
            if(nr < 0 || nc < 0 || nr >= h || nc >= w){
                i--;
                dir = (dir == 3 ? 0 : dir + 1);
            }
            else rb = {nr, nc};
        }
    }
    
    vector<int> getPos() {
        return {rb.second, abs(rb.first - (h - 1))};
    }
    
    string getDir() {
        vector<string> v = {"East", "North", "West", "South"};
        return v[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
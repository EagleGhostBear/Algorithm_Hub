class Bank {
public:
    vector<long long> v;
    // 0-indexed 배열 balance를 기반으로 객체를 초기화한다.
    Bank(vector<long long>& balance) {
        for(auto c : balance) v.push_back(c);
    }
    // account1번 계좌에서 account2번 계좌로 money달러를 송금한다.
    bool transfer(int account1, int account2, long long money) {
        if(account1 < 1 || account2 < 1) return false;
        if(account1 > v.size() || account2 > v.size()) return false;
        if(v[account1 - 1] - money < 0) return false;
        v[account1 - 1] -= money;
        v[account2 - 1] += money;
        return true;
    }
    // account번 계좌에 money달러를 입금한다.(성공 시 true, 실패 시 false)
    bool deposit(int account, long long money) {
        if(account < 1 || account > v.size()) return false;
        v[account - 1] += money;
        return true;
    }
    // account번 계좌에서 money달러를 출금한다.(성공 시 true, 실패 시 false)
    bool withdraw(int account, long long money) {
        if(account < 1 || account > v.size()) return false;
        if(v[account - 1] - money < 0) return false;
        v[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
class Solution {
public:
    int divide(int x, int y) {
        long long a = (long long) x, b = (long long)y;
    if (a == INT_MIN and b == -1) return INT_MAX;
    if (a == INT_MIN and b == 1) return INT_MIN;
    bool flag = (a > 0) == (b > 0) ? true : false;
    a = abs(a);
    b = abs(b);
    long long ans =0, temp = 0;
    for (int i = 31 ; i>=0; i--){
        if (( b << i ) <= a){
            a-= (b<<i);
            ans+= (1<<i);
        }
    }
    if (!flag) ans = -ans;
    return ans;
    }
};
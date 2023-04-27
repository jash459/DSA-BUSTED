class Solution {
public:
    int bulbSwitch(int n) {
    int i=0, cnt=0;
    while(i*i<=n)
    {
        cnt++;
        i++;
    }
    return cnt-1;
    }
};
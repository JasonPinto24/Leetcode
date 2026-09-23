class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int k=1;k<=60;k++){
            long long x=(long long)num1-(long long)k*num2;
            int bits=__builtin_popcountll(x);
            if(bits<=k && x>=k) return k;
        }
        return -1;
    }
};
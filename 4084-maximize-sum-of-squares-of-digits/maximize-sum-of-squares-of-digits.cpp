class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        int count=0;
        string ans="";
        count=sum/9;
        int rem=sum%9;
        int i=count;
        while(count--){
            ans+='9';
        }
        if(rem)ans+=rem+'0';
        int n=ans.size();
        int left=num-n;
        while(left--){
            ans+='0';
        }
        return ans;
    }
};
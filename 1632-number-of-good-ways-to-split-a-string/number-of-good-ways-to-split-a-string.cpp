class Solution {
public:
    int numSplits(string s) {
        vector<int> left(26,0);
        vector<int> right(26,0);
        int distinctleft=0;
        int distinctright=0;
        for(char ch:s){
            if(right[ch-'a']==0) distinctright++;
            right[ch-'a']++;
        }
        int ans=0;
        int n=s.size();
        for(int i=0;i<n-1;i++){
            char ch=s[i];
            if(left[ch-'a']==0) distinctleft++;
            left[ch-'a']++;
            right[ch-'a']--;
            if(right[ch-'a']==0){
                distinctright--;
            }
            if(distinctleft==distinctright) ans++;
        }
        return ans;
    }
};
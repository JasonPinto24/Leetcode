class Solution {
public:
    string removeStars(string s) {
        string st;
        for(char ch:s){
            if(ch=='*'){
                if(!st.empty()) st.pop_back();
            }
            else{
                st.push_back(ch);
            }
        }
        return st;
    }
};
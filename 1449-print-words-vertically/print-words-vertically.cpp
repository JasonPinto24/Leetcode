class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        string word;
        stringstream ss(s);
        while(ss>>word){
            words.push_back(word);
        }
        int maxlen=0;
        for(string &word:words){
            maxlen=max(maxlen,(int)word.size());
        }
        vector<string> ans;
        for(int col=0;col<maxlen;col++){
            string temp;
            for(int row=0;row<(int)words.size();row++){
                if(col<(int)words[row].size()){
                    temp+=words[row][col];
                }else{
                    temp+=' ';
                }
            }
            while(!temp.empty() && temp.back()==' ') temp.pop_back();
            ans.push_back(temp);
        }
        return ans;
    }
};
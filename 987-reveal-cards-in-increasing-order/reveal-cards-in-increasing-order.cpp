class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n=deck.size();
        vector<int> ans(n);
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        for(int x:deck){
            int pos=q.front();
            q.pop();
            ans[pos]=x;
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};
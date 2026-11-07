class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n=skills.size();
        int champ=0;
        int wins=0;
        for(int i=1;i<n;i++){
            if(skills[i]<skills[champ]){
                wins++;
            }
            else{
                champ=i;
                wins=1;
            }
            if(wins==k) return champ;
        }
        return champ;
    }
};
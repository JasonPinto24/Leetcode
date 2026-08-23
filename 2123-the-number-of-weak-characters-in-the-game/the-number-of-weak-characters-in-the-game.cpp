class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]) return  a[1]>b[1];
            return a[0]<b[0];
        });
        int n=properties.size();
        int ans=0;
        int maxdefense=0;
        for(int i=n-1;i>=0;i--){
            int defense=properties[i][1];
            if(defense<maxdefense){
                ans++;
            }
            maxdefense=max(maxdefense,defense);
        }
        return ans;
    }
};
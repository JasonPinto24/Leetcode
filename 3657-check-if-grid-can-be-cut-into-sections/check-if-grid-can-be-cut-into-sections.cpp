class Solution {
public:
    bool check(vector<vector<int>> &rectangles,int a,int b){
        vector<pair<int,int>> intervals;
        for(auto &r:rectangles){
            intervals.push_back({r[a],r[b]});
        }
        sort(intervals.begin(),intervals.end());
        int count=0;
        int end=0;
        for(auto &it:intervals){
            int start=it.first;
            int second=it.second;
            if(start>=end){
                count++;
                end=second;
            }
            else{
                end=max(end,second);
            }
        }
        return count>=3;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return check(rectangles,0,2)||check(rectangles,1,3);
    }
};
class Solution {
public:
    string fractionAddition(string expression) {
        int num=0;
        int den=1;
        int i=0;
        int n=expression.size();
        while(i<n){
            int sign=1;
            if(expression[i]=='+'){
                sign=1;
                i++;
            }
            else if(expression[i]=='-'){
                sign=-1;
                i++;
            }
            int currnum=0;
            while(i<n && isdigit(expression[i])){
                currnum=currnum*10+(expression[i]-'0');
                i++;
            }
            i++;
            int currden=0;
            while(i<n && isdigit(expression[i])){
                currden=currden*10+(expression[i]-'0');
                i++;
            }
            currnum*=sign;
            num=num*currden+currnum*den;
            den=den*currden;
            int g=gcd(abs(num),den);
            num/=g;
            den/=g;

        }
        return to_string(num) + '/' + to_string(den);
    }
};
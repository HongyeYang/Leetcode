class Solution {
public:
    string parseTernary(string expression,int begin=0) {
        if(begin>=expression.size())return "";
        if(begin==expression.size()-1||expression[begin+1]==':')return expression.substr(begin,1);
        if(expression[begin]=='T')return parseTernary(expression,begin+2);
        else{
            int level=1;
            begin+=2;
            while(begin<expression.size()&&level){
                if(expression[begin]=='?')level++;
                else if(expression[begin]==':')level--;
                begin++;
            }
            return parseTernary(expression, begin);
        }
        
    }
};

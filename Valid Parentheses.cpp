class Solution {
public:
    bool isValid(string s) {
        stack<char>roc;
        for(char c:s){
            if(c=='('||c=='['||c=='{'){
                roc.push(c);
            }
            else{
                if(roc.empty())return false;
                char cur=roc.top();
                roc.pop();
                if((c==')'&&cur!='(')||(c==']'&&cur!='[')||(c=='}'&&cur!='{'))return false;
            }
        }
        return roc.empty();
    }
};

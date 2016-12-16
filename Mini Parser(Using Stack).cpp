class Solution {
public:
    NestedInteger deserialize(string s) {
        int len=s.size();
        if(!len)return NestedInteger();
        stack<NestedInteger>roc;
        int i=0;
        while(i<len){
            if(s[i]=='[')roc.push(NestedInteger(INT_MIN));
            else if((s[i]<='9'&&s[i]>='0')||s[i]=='-'){
                int j=i+1;
                while(j<len&&(s[j]<='9'&&s[j]>='0')||s[j]=='-')j++;
                roc.push(NestedInteger(stoi(s.substr(i,j-i))));
                i=j-1;
            }
            else if(s[i]==']'){
                stack<NestedInteger>tep;
                while(!(roc.top().isInteger()&&roc.top().getInteger()==INT_MIN)){
                    tep.push(roc.top());
                    roc.pop();
                }
                roc.pop();
                NestedInteger cur=NestedInteger();
                while(!tep.empty()){
                    cur.add(tep.top());
                    tep.pop();
                }
                roc.push(cur);
            }
            i++;
        }
        return roc.top();
    }
};

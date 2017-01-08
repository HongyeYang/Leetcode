class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int thrfd=3,fivfd=5,k=1;
        vector<string>res;
        while(k<=n){
            string cur;
            if(k==thrfd){
                cur+="Fizz";
                thrfd+=3;
            }
            if(k==fivfd){
                cur+="Buzz";
                fivfd+=5;
            }
            if(cur.empty())res.push_back(to_string(k));
            else res.push_back(cur);
            k++;
        }
        return res;
    }
};

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string data;
        for(string &s:strs){
            data+=s;
            data.push_back(0);
        }
        return data;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string>res;
        for(int i=0;i<s.size();i++){
            int start=i;
            while(s[i]!=0)i++;
            res.push_back(s.substr(start,i-start));
        }
        return res;
    }
};


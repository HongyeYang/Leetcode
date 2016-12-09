class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1=version1.size();
        int len2=version2.size();
        version1.push_back('.');
        version2.push_back('.');
        int c1=0,c2=0;
        while(c1<len1&&c2<len2){
            int brk=c1;
            while(version1[brk]!='.')brk++;
            int it1=stoi(version1.substr(c1,brk-c1));
            c1=brk+1;
            brk=c2;
            while(version2[brk]!='.')brk++;
            int it2=stoi(version2.substr(c2,brk-c2));
            c2=brk+1;
            if(it1<it2)return -1;
            else if(it2<it1)return 1; 
        }
        if(c1<len1){
            while(c1<len1){
                int brk=c1;
                while(version1[brk]!='.')brk++;
                int it1=stoi(version1.substr(c1,brk-c1));
                if(it1>0)return 1;
                c1=brk+1;
            }
        }
        else if(c2<len2){
           while(c2<len2){
                int brk=c2;
                while(version2[brk]!='.')brk++;
                int it2=stoi(version2.substr(c2,brk-c2));
                if(it2>0)return -1;
                c2=brk+1;
            }
        }
        return 0;
    }
};

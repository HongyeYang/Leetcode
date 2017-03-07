// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int res=0;
        for(int i=0;i<n/4+1;i++){
            int diff=read4(buf+res);
            if(diff==0)return res;
            res+=diff;
        }
        return res>n?n:res;
    }
};

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
        for(int i=0;i<n;i++){
            if(readpos==writepos){
                writepos=read4(buff);
                readpos=0;
                if(writepos==0)return i;
            }
            buf[i]=buff[readpos++];
        }
        return n;
    }
private:
char buff[4];
int readpos=0;
int writepos=0;
};

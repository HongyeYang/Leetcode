class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(v1.size())q.push({v1.begin(),v1.end()});
        if(v2.size())q.push({v2.begin(),v2.end()});
    }

    int next() {
        auto cur=q.front();
        q.pop();
        int res=*(cur.first);
        if((++cur.first)!=cur.second)q.push(cur);
        return res;
    }

    bool hasNext() {
        return !q.empty();
    }
private:
    queue<pair<vector<int>::iterator,vector<int>::iterator>>q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

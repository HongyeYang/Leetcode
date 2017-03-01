class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        row=vec2d.begin();
        end=vec2d.end();
        while(row!=end&&(row->begin()==row->end()))row++;
        if(row!=end)col=row->begin();
    }

    int next() {
        int res=*col;
        col++;
        while(col==row->end()){
            row++;
            if(row!=end)col=row->begin();
            else break;
        }
        return res;
    }

    bool hasNext() {
        if(row==end)return false;
        return true;
    }
private:
vector<vector<int>>::iterator row;
vector<int>::iterator col;
vector<vector<int>>::iterator end;
};


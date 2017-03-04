class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        w=width;
        h=height;
        for(pair<int,int>&p:food){
            foods.push(p.first*w+p.second);
        }
        snake.push_back(0);
        spos.insert(0);
        if(!foods.empty()&&!spos.count(foods.front())){
            f=foods.front();
            foods.pop();
        }
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int nhead=snake.front();
        int i=nhead/w, j=nhead%w;
        if(direction=="U"){i--;nhead-=w;}
        if(direction=="L"){j--;nhead-=1;}
        if(direction=="R"){j++;nhead+=1;}
        if(direction=="D"){i++;nhead+=w;}
        spos.erase(snake.back());
        
        if(i<0||i>=h||j<0||j>=w||spos.count(nhead))return -1;
        spos.insert(nhead);
        snake.push_front(nhead);
        if(nhead!=f)snake.pop_back();
        else {
            f=-1;
            spos.insert(snake.back());
        }
        if(f==-1&&!foods.empty()&&!(spos.count(foods.front()))){
            f=foods.front();
            foods.pop();
        }
        return (int)snake.size()-1;
    }
    
private:
int w=0;
int h=0;
queue<int>foods;
unordered_set<int>spos;
list<int>snake;
int f=-1;
};

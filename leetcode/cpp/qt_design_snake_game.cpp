/**
* @Author: Tian Qiao
* @Date:   2016-07-15T22:49:34+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-15T22:49:46+08:00
*/



/*
Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.

Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.

When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

Example:
Given width = 3, height = 2, and food = [[1,2],[0,1]].

Snake snake = new Snake(width, height, food);

Initially the snake appears at position (0,0) and the food at (1,2).

|S| | |
| | |F|

snake.move("R"); -> Returns 0

| |S| |
| | |F|

snake.move("D"); -> Returns 0

| | | |
| |S|F|

snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

| |F| |
| |S|S|

snake.move("U"); -> Returns 1

| |F|S|
| | |S|

snake.move("L"); -> Returns 2 (Snake eats the second food)

| |S|S|
| | |S|

snake.move("U"); -> Returns -1 (Game over because snake collides with border)
*/

// My Solution(Fail)
class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    deque<pair<int, int>> snake; // 贪食蛇覆盖区域
    vector<vector<char>> ground; // 地图
    vector<pair<int, int>> foods; // 食物所在区域
    int Eaten = 0; // 已经吃下的食物数
    // 如果第一个food和出发点重合，那么第一个food不显示，直至贪食蛇离开出发点
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        ground.resize(height, vector<char>(width, 'E')); // E:empty, S:snake, F:food
        for(auto i:food) {
            ground[food[0].first][food[0].second] = 'F';
            break;
        }
        ground[0][0] = 'S';
        snake.push_back({0,0});
        foods = food;
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        cout << "Hello" << endl;
        int height = ground.size(), width = ground[0].size();
        cout << snake.back().first << " " << snake.back().second << endl;

        if(direction=="U") {
            if(snake.back().first==0 || ground[snake.back().first-1][snake.back().second]=='S') return -1;
            if(ground[snake.back().first-1][snake.back().second]=='E') {
                ground[snake.front().first][snake.front().second]='E';
                snake.pop_front();
            } else if(ground[snake.back().first-1][snake.back().second]=='F') {
                Eaten++; // F
                ground[foods[Eaten].first][foods[Eaten].second] = 'F';
            }
            ground[snake.back().first-1][snake.back().second]='S';
            snake.push_back({snake.back().first-1, snake.back().second});
        } else if(direction=="D") {
            if(snake.back().first==height-1 || ground[snake.back().first+1][snake.back().second]=='S') return -1;
            if(ground[snake.back().first+1][snake.back().second]=='E') {
                ground[snake.front().first][snake.front().second]='E';
                snake.pop_front();
            } else if(ground[snake.back().first+1][snake.back().second]=='F') {
                Eaten++;
                ground[foods[Eaten].first][foods[Eaten].second] = 'F';
            }
            ground[snake.back().first+1][snake.back().second]='S';
            snake.push_back({snake.back().first+1, snake.back().second});
        } else if(direction=="L") {
            if(snake.back().second==0 || ground[snake.back().first][snake.back().second-1]=='S') return -1;
            if(ground[snake.back().first][snake.back().second-1]=='E') {
                ground[snake.front().first][snake.front().second]='E';
                snake.pop_front();
            } else if(ground[snake.back().first][snake.back().second-1]=='F') {
                Eaten++;
                ground[foods[Eaten].first][foods[Eaten].second] = 'F';
            }
            ground[snake.back().first][snake.back().second-1]='S';
            snake.push_back({snake.back().first, snake.back().second-1});
        } else { // R
            if(snake.back().second==width-1 || ground[snake.back().first][snake.back().second+1]=='S') return -1;
            if(ground[snake.back().first][snake.back().second+1]=='E') {
                ground[snake.front().first][snake.front().second]='E';
                snake.pop_front();
            } else if(ground[snake.back().first][snake.back().second+1]=='F') {
                Eaten++;
                ground[foods[Eaten].first][foods[Eaten].second] = 'F';
            }
            ground[snake.back().first][snake.back().second+1]='S';
            snake.push_back({snake.back().first, snake.back().second+1});
        }
        return Eaten;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */

 class SnakeGame {
 public:
 /** Initialize your data structure here.
 @param width - screen width
 @param height - screen height
 @param food - A list of food positions
 E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */

 int w, h, pos;
 vector<pair<int, int>> food;
 set<pair<int, int>> hist; // 内容与snake一致，特点在于具备快速查找的能力
 deque<pair<int, int>> q; // snake

 SnakeGame(int width, int height, vector<pair<int, int>> food) {
 	this->food = food;
 	w = width, h = height, pos = 0;
 	q.push_back(make_pair(0, 0));
 }

 /** Moves the snake.
 @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
 @return The game's score after the move. Return -1 if game over.
 Game over when snake crosses the screen boundary or bites its body. */
int move(string direction) {
 	int row = q.back().first, col = q.back().second;
 	pair<int, int> d = q.front(); q.pop_front(); // the tail of the snake
 	hist.erase(d);

 	if (direction == "U")
 		row--;
 	else if (direction == "D")
 		row++;
 	else if (direction == "L")
 		col--;
 	else if (direction == "R")
 		col++;

 	if (row < 0 || col < 0 || col >= w || row >= h || hist.count(make_pair(row, col)))
 		return -1;

 	hist.insert(make_pair(row, col));
 	q.push_back(make_pair(row, col));

 	if (pos >= food.size())
 		return q.size() - 1;

 	if (row == food[pos].first && col == food[pos].second) {
 		pos++;
 		q.push_front(d); // 保留贪食蛇的尾巴
 		hist.insert(d); // 保留贪食蛇的尾巴
 	}

 	return q.size() - 1;
   }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */

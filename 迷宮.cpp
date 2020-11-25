#include <iostream>
#include <queue>
#include <stack>

struct element{
	short int x;
	short int y;
	element* last;
};
std::queue<element*> pathpoint;			//存放目前走到的路徑點 

//struct point{
//	int x;
//	int y;
//};

struct offsets{
	short int vert;
	short int horiz;
};

int main(){
	offsets move[8] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}}; 		//決定八個方位該移動的水平垂直

	int size[2] = {0};			//讀入迷宮大小 
	std::cin >> size[0];
	std::cin >> size[1];
	
	int maze[size[0]+2][size[1]+2] = {0};		//讀入迷宮並加上邊界 
	for(int i=0; i<size[0]+2; i++){
		for(int j=0; j<size[1]+2; j++){
			if(i == 0 || j == 0 || i == size[0]+1 || j == size[0]+1){
				maze[i][j] = 1;
			}else{
				std::cin >> maze[i][j];	
			}
		}
	}
	
	maze[1][1] = 2;
	bool found = false;
	element *start = new element;
	start->x = 1;
	start->y = 1;
	start->last = NULL;
	pathpoint.push(start);
	while(1){
		element *front = pathpoint.front();
		pathpoint.pop();
		for(int i=0; i<8; i++){			
			element *temp = new element;
			temp->x = front->x + move[i].horiz;
			temp->y = front->y + move[i].vert;
			if(maze[temp->x][temp->y] == 0){
				temp->last = front;
				pathpoint.push(temp);
				maze[temp->x][temp->y] = maze[front->x][front->y] + 1;
			}
		}
		if(front->x == size[0] && front->y== size[1]){
			break;
		}
	}
	
//	std::stack<point> path;			//結果路徑 
//	point p = {size[0], size[1]};		//先放終點 
//	path.push(p);
//	int pathnumber = maze[size[0]][size[1]] - 1;		//總共要走幾步-1 
//	for(; pathnumber > 1; pathnumber--){
//		for(int i = 0; i<8; i++){		//之後慢慢回推 
//			point temp = {p.x + move[i].horiz, p.y + move[i].vert};
//			if(maze[temp.x][temp.y] == pathnumber){
//				path.push(temp);
//				p = temp;
//				break;
//			}
//		}
//	}

//	while(!path.empty()){
//			std::cout << path.top().x << " " << path.top().y << std::endl;
//			path.pop();
//	}

	std::stack<element*> result;
	element* pos = new element;
	pos = pathpoint.back();		//紀錄終點 用來回推 
	while(pos->last){
		result.push(pos);
		pos = pos->last;
	}
	
	std::cout <<  "1 1" << std::endl;
	while(!result.empty()){
			std::cout << result.top()->x << " " << result.top()->y << std::endl;
			result.pop();
	}
	
	return 0; 
}

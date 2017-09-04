#include <bits/stdc++.h>
using namespace std;
struct state{
	int x,y;
	 bool operator < (const state& that) const {
        if (x != that.x) return x < that.x;
        return y < that.y;
    }		
};
int cx,cy,target;


void addPath(map<state,pair<state,int> > &parentOf,queue<state> &q,state top,int rule,state child){
	if(parentOf.find(child) == parentOf.end()){
		q.push(child);
		parentOf[child] = make_pair(top,rule);
	}
}
void bfs(state start,stack<pair<state,int> > &path){
	queue<state> q;
	state goal = (state) {-1,-1};
	
	map<state,pair<state,int> > parentOf;
	q.push(start);
	parentOf[start] = make_pair(start,0);
	
	while(!q.empty()){
		state top = q.front();
		q.pop();
		
		
		if(top.x == target || top.y == target){
			goal = top;
			break;
		}
		
		if(top.x < cx){
			state child = (state) {cx,top.y};
			addPath(parentOf,q,top,1,child);
		}
		
		if(top.y < cy){
			state child = (state) {top.x,cy};
			addPath(parentOf,q,top,2,child);
		}
		if(top.x > 0){
			state child = (state) {0,top.y};
			addPath(parentOf,q,top,3,child);
		}
		if(top.y > 0){
			state child = (state) {top.x,0};
			addPath(parentOf,q,top,4,child);
		}
		if(top.y > 0){
			state child = (state) {min(top.x + top.y, cx), max(0,top.x + top.y - cx)};
			addPath(parentOf,q,top,5,child);
		}
		if(top.x > 0){
			state child = (state) {max(0,top.x + top.y - cy),min(cy,top.x + top.y)};
			addPath(parentOf,q,top,6,child);
		}	
	}
	if(goal.x == -1 || goal.y == -1) return;
		
		
		path.push(make_pair(goal,0));
		while (parentOf[path.top().first].second != 0) path.push(parentOf[path.top().first]);

}
int main(){
	cout <<"enter capacities\n";
	cin >>cx>>cy;
	cout <<"Enter target\n";
	cin >>target;
	
	stack<pair<state,int> > path;
	
	bfs((state) {0, 0}, path);
    if (path.empty())
        printf("\nTarget cannot be reached.\n");
    else{
        printf("\nNumber of moves to reach the target : %d\nOne path to the target is as follows :\n", path.size() - 1);
        while (!path.empty())   {
            state top = path.top().first;
            int rule = path.top().second;
            path.pop();

            switch (rule)   {
                case 0: printf("State : (%d, %d)\n#\n", top.x, top.y);
                        break;
                case 1: printf("State : (%d, %d)\nAction : Fill the first jug\n", top.x, top.y);
                        break;
                case 2: printf("State : (%d, %d)\nAction : Fill the second jug\n", top.x, top.y);
                        break;
                case 3: printf("State : (%d, %d)\nAction : Empty the first jug\n", top.x, top.y);
                        break;
                case 4: printf("State : (%d, %d)\nAction : Empty the second jug\n", top.x, top.y);
                        break;
                case 5: printf("State : (%d, %d)\nAction : Pour from second jug into first jug\n", top.x, top.y);
                        break;
                case 6: printf("State : (%d, %d)\nAction : Pour from first jug into second jug\n", top.x, top.y);
                        break;
            }
        }
	}
	
}

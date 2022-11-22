#include <iostream>
#include <vector>
using namespace std;

class block{
    public:
    bool isStart;
    bool isEnd;
    bool isWall;
    bool hasPlayer;
    int x, y;

    block(int x, int y){
        this->x = x;
        this->y = y;
        this->isWall = true;
        this->hasPlayer = false;
        this->isStart = false;
        this->isEnd = false;
    }
};

struct agent{
    int x, y;
};

vector<vector<block*>> mapMaker(int width, int height){
    vector<vector<block*>> empty2DVector = vector<vector<block*>>(height, vector<block*>(width, 0));

    for(int i=empty2DVector.size()-1;i>=0;--i){
		for(int j=0;j<empty2DVector[i].size();j++){
            block *newBlock = new block(j, i);
            empty2DVector[i][j] = newBlock;
            //cout << "(" << empty2DVector[i][j]->x <<", " << empty2DVector[i][j]->y << ") ";
        }
        //cout<<endl;
	}
    
    return empty2DVector;
};

void displayMap(vector<vector<block*>> map){
    for(int i=map.size()-1;i>=0;--i){
		for(int j=0;j<map[i].size();j++){
            if(map[i][j]->isWall){
                cout << "[-]";
            } 

            if(map[i][j]->isWall == false){
                cout << "   ";
            } 

        }
        cout<<endl;
	}
}

//Step 1: populate 2-d vector with blocks
//Step 2: create a display method
//Step 3: test aforementioned display method


int main(){

    vector<vector<block*>> sample = mapMaker(7, 26);
    sample[2][7]->isWall = false;
    sample[5][15]->isWall = false;
    displayMap(sample);

    return 0;
}
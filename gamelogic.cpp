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
		for(unsigned int j=0;j<empty2DVector[i].size();j++){
            block *newBlock = new block(i, j);
            empty2DVector[i][j] = newBlock;
            //cout << "(" << empty2DVector[i][j]->x <<", " << empty2DVector[i][j]->y << ") ";
        }
        //cout<<endl;
	}

    //cout << empty2DVector[4][4]->x << endl;
    return empty2DVector;
};

void displayMap(vector<vector<block*>> map){
    for(int i=map.size()-1;i>=0;--i){
		for(unsigned int j=0;j<map[i].size();j++){

            if(map[i][j]->isWall){
                cout << "[-]";
            } else {

                if(map[i][j]->isStart){
                    cout << " S ";
                } else if(map[i][j]->isEnd){
                    cout << " X ";
                } else if(map[i][j]->isWall == 0){
                    cout << "   ";
                } 

            }
        }

        cout<<endl;
	}
}

block* makeStart(vector<vector<block*>> map, int x, int y){
    map[x][y]->isStart = 1;
    map[x][y]->isWall = 0;

    return map[x][y];
}

block* makeEnd(vector<vector<block*>> map, int x, int y){
    map[x][y]->isEnd = 1;
    map[x][y]->isWall = 0;

    return map[x][y];
}

void clean(vector<vector<block*>> map){
    for(int i=0;i<map.size(); i++){
		for(unsigned int j=0;j<map[i].size();j++){
            delete(map[i][j]);
	    }
    }
}





// Environment Logic
//Step 1: populate 2-d vector with blocks - DONE
//Step 2: create a display method - DONE
//Step 3: test aforementioned display method - DONE
//Step 4: make a start-maker and an end-maker - DONE
//Step 4.5: IMPORTANT - make a clean method for all the blocks - DONE
//Step 5: implement a randomized A* function for generating random pathways in the obstacle course
//Step 6: implement feathering
//Step 7: Maybe add controls for manual agent control?
// Environment logic checklist ends here

int main(){

    vector<vector<block*>> sample = mapMaker(7, 23);

    makeEnd(sample, 3, 11);
    makeStart(sample, 1, 2);

    displayMap(sample);
    clean(sample);

    return 0;
}
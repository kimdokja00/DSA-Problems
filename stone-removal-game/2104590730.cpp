class Solution {
public:
    bool canAliceWin(int n) {
        int stone = n;
        int remove = 10;
        int turn = 0; //div by 2 then alice wins
        while(stone>=0 && remove!= 0){
            stone = stone - remove;
            remove--;
            turn++;
        }
        if(turn%2 == 0){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    bool judgeCircle(string moves) {
        int up = 0, down = 0, left = 0, right = 0, count = 0;
        
        while(count < moves.length()){
            
            if(moves[count] == 'U'){
                up++;
            }
            else if(moves[count] == 'D'){
                down++;    
            }           
            else if(moves[count] == 'L'){
                left++;    
            }            
            else{
                right++;    
            }
    
            count++;
        }


        if(up == down && left == right){
            return true;
        }
        
        return false;
    }
};

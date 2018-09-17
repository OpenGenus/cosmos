class Solution {
public:
    bool judgeCircle(string moves) {
        int up = 0, down = 0, left = 0, right = 0, count = 0;
        
        while(count < moves.length()){      //loop through the entire input string
            
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

        /*For the robot to be in the original position, the 'up' must equal the 'down' 
          and the 'right' must equal the 'left'.
        */
        if(up == down && left == right){        
            return true;
        }
        
        return false;
    }
};

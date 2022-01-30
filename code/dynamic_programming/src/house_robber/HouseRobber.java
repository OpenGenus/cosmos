import java.util.Arrays;

class HouseRobber {
    public static int rob(int[] nums) {
        int len = nums.length;
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        if(len == 2) return Math.max(nums[0], nums[1]);

        int memo[] = new int [len];
        memo[0] = nums[0];
        memo[1] = Math.max(nums[0], nums[1]);
        System.out.println("Memo before robbing: " + Arrays.toString(memo) + "\n");
        for(int i=2; i<len; i++){
            System.out.println("Visiting house no. " + (i+1));
            int choice1 = nums[i] + memo[i-2];
            int choice2 = memo[i-1];
            System.out.println("choice 1 (rob this house and 2nd before) : " + choice1);
            System.out.println("choice 2 (max of previous two houses) : " + choice2);
            memo[i] = Math.max(choice1, choice2);
            System.out.println("Memo after robbing: " + Arrays.toString(memo) + "\n");
        }
        return memo[len-1];
    }
    public static void main(String args[]){
        int input[] = new int[]{1,2,3,4};
        System.out.println("Houses with given stash on a street: " + Arrays.toString(input));
        int stolenAmount = rob(input);
        System.out.println("Max amount stolen by robber: " + stolenAmount);
    }
}

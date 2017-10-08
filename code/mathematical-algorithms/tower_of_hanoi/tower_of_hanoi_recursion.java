public class tower_of_hanoi {

	public static void main(String[] args) {
	
		//disks: 4, source: pole 1, destination: pole 3, auxilary: pole 2
		towerOfHanoi(4, "1", "3", "2");
	
	}

	//To print the steps needed to solve tower of hanoi via recursion
	public static void towerOfHanoi(int num, String src, String dest, String aux){
		//base case of recursion
		//if there are no disks, just return
		if(num == 0) {
			return;
		}
		
		//move (num - 1) disks from src to aux using dest pole
		towerOfHanoi(num - 1, src, aux, dest);
		//step to move the remaining disk from src to dest
		System.out.println("Move " + num + "th disc from " + src + " to " + dest);
		//move (num - 1) disks from aux to dest using src pole
		towerOfHanoi(num - 1, aux, dest, src);
	}
	
}


public class WilliamsHeap{

	private Node array[];//Heap's array
	private int k = 0;
	private int n;//Max number of nodes
	

	public WilliamsHeap(int n){

		array = new Node[n+1];
		this.n = n;
	}
	
	public Integer[] insert(Node elem, Integer[] pos) {
		
		if(k == n+1) {
			
			System.out.println("Monticulo lleno :(");
			return pos;
			
		}else {
			
			k++;
			array[k] = elem;
			return upward(k,pos);
			
		}
		
	}
	
	public Integer[] upward(int elem,Integer[] pos) {
		
		int i = elem;
		Node aux;
		int auxpos;
		
		while((i != 1) && array[i/2].getPathCost() > array[i].getPathCost()) {
			
			auxpos = pos[array[i/2].getKey()];
			pos[array[i/2].getKey()] = pos[array[i].getKey()];
			pos[array[i].getKey()] = auxpos;
			
			aux = array[i/2];
			array[i/2] = array[i];
			array[i] = aux;
			i = i/2;
		}
		
		pos[array[i].getKey()] = i; 
		
		return pos;
		
	}
	
	public Integer[] delMin(Integer[] pos){
		
		if(k == 0) {
			System.out.println("No hay mas elementos :(");
			return null;
		}
		else {
			array[1] = array[k];
			k = k-1;
			return downward(1,pos);
		}
		
	}
	
	
	public Integer[] downward(int elem,Integer[] pos) {
		
		Node aux;
		int j = 1;
		boolean fin = false;
		int m = 0;
		int auxpos;
		
		while((2*j <= k) && !fin) {
			
			if((2*j+1) <= k && (array[2*j + 1].getPathCost() < array[2*j].getPathCost())) {
				m = 2*j +1;
			}else if((2*j+1) >  k || (array[2*j + 1].getPathCost() >= array[2*j].getPathCost())) {
				m = 2*j;
			}
			
			if(array[j].getPathCost() > array[m].getPathCost()) {
				
				auxpos = pos[array[m].getKey()];
				pos[array[m].getKey()] = pos[array[j].getKey()];
				pos[array[j].getKey()] = auxpos;
				
				aux = array[j];
				array[j] = array[m];
				array[m] = aux;
				j= m;
				
			}else {
				fin = true;
			}
			
		}
		
		return pos;
		
	}
	
	
	public Node min() {
		
		if (k == 0) return null;
		return array[1];
	}
	
	
	public Integer[] decreaseKey(int elem, Double pathCost,Integer[] pos) {
		
		array[elem] = new Node(array[elem].getKey(),pathCost);
		return upward(elem,pos);
		
	}


	
}

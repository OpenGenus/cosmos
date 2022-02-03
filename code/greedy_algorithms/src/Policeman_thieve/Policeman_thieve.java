public class Policeman_thieve {
    class Solution 
{ 
    int catchThieves(char arr[], int k) 
	{ 
        Queue<Integer> tq = new ArrayDeque<>(); // queue to store index of thief
        Queue<Integer> pq = new ArrayDeque<>(); // queue to store index of police
        
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 'T') {
                tq.offer(i);
            } else {
                pq.offer(i);
            }
        }
        
        while (!tq.isEmpty() && !pq.isEmpty()) {
            if (Math.abs(tq.peek() - pq.peek()) <= k) { // thief is within the reach of the policeman
                counter++;
                pq.poll();
                tq.poll();
            } else if (tq.peek() > pq.peek()) { // thief lies beyond the reach of the current policeman
                pq.poll();
            } else { // thief is not reachable from any of the police
                tq.poll();   
            }
        }
        
        return counter;
	} 
} 
}

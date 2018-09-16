/* Part of Cosmos by OpenGenus Foundation */

public class ElementaryCellularAutomaton {
	private static final int SIZE = 200;
	private static final int HISTORY = 200;
	
	private final byte rule;

	private boolean[][] grid = new boolean[HISTORY][SIZE];
	private int step = 0;

	public static void main(String[] args) {
		ElementaryCellularAutomaton elCell = new ElementaryCellularAutomaton((byte)2);
		do {
			System.out.println(elCell);
		} while(elCell.step());
	}

	/**
	 * This is the main class for an elementary cellular automaton
	 * @param ruleNr Identifier for which of the 256 rules should be used
	 */
	public ElementaryCellularAutomaton(byte ruleNr) {
		rule = ruleNr;
		/*
		 * Initialize center to 1
		 * (other initializations are possible and will result in different behavior)
		 */
		grid[0][SIZE / 2] = true;
	}

	public boolean step() {
		if (step < (HISTORY-1)) {
			for (int i = 0; i < SIZE; i++) {
				byte neighbors = getNeighbors(i);
				boolean nextValue = (((rule >> neighbors) & 1) == 1);
				grid[step+1][i] = nextValue;
			}
			step++;
			return true;
		} else {
			return false;
		}
	}
	
	/*
	 * Convert the cell and its neighbors to a 3-bit number
	 */
	private byte getNeighbors(int cell) {
		return (byte) ((grid[step][getCellIndex(cell-1)] ? 4 : 0) + 
				(grid[step][getCellIndex(cell)] ? 2 : 0) +
				(grid[step][getCellIndex(cell+1)] ? 1 : 0));
	}
	
	/*
	 * Convert the cell number to the index of the grid array
	 */
	private int getCellIndex(int cell) {
		int result = cell%SIZE;
		if(result < 0) {
			result += SIZE;
		}
		return result;
	}
	
	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		boolean[] array = grid[step];
		for (int i = 0; i < array.length; i++) {
		    if (array[i]) builder.append("1"); else builder.append("0");
		}
		return builder.toString();
	}
}

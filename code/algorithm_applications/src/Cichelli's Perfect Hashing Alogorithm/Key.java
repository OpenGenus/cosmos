public class Key implements Comparable<Key> {
    //fields
	private String keyWord;
	private char firstLetter, lastLetter;
	//unnassignedLetter is used if only one letter(first or last) is not set.
	private int totalValue, firstLetterValue, lastLetterValue, positionInGFirst, positionInGLast, unassignedLetterPosition;
	
	//constructor
	public Key(String keyWord)	{
		this.keyWord = keyWord;
		this.firstLetter = keyWord.charAt(0);
		this.lastLetter = keyWord.charAt(keyWord.length() - 1);
		this.totalValue = 0; //updated in setValue method
		this.firstLetterValue = 0; //updated in setValue method
		this.lastLetterValue = 0; //updated in setValue method
		this.positionInGFirst = 0; //updated in Cichelli's alogrithm
		this.positionInGLast = 0; //updated in Cichelli's alogrithm
		//unassignedLetterPosition is set to -1 as an arbitrary value.
		this.unassignedLetterPosition = -1; //can updated in Cichelli's alogrithm under certain conditions.
	}
	
	/*this method is necessary in sorting the list of keys by value.
	 * I created this compareTo method based on info from the following link:
	 * https://beginnersbook.com/2013/12/java-arraylist-of-object-sort-example-comparable-and-comparator/
	 */
	@Override
	public int compareTo(Key comparesTo)	{
		int compareValue = ((Key)comparesTo).getTotalValue();
		return compareValue-this.totalValue;
	}

	//getter and setter methods
	
	public String getKeyWord()	{
		return keyWord;
	}
	
	public char getFirstLetter()	{
		return firstLetter;
	}
	
	public char getLastLetter()	{
		return lastLetter;
	}
	
	public int getFirstLetterValue()	{
		return firstLetterValue;
	}
	
	public void setFirstLetterValue(int value)	{
		this.firstLetterValue = value;
	}
	
	public int getLastLetterValue()	{
		return lastLetterValue;
	}
	
	public void setLastLetterValue(int value)	{
		this.lastLetterValue = value;
	}
	
	public void setTotalValue(int value)	{
		this.totalValue = value;
	}
	
	public int getTotalValue()	{
		return totalValue;
	}
	
	public void setPositionInGFirst(int position)	{
		this.positionInGFirst = position;
	}
	
	public int getPositionInGFirst()	{
		return positionInGFirst;
	}

	
	public void setpositionInGLast(int position)	{
		this.positionInGLast = position;
	}

	public int getPositionInGLast()	{
		return positionInGLast;
	}
	
	public void setUnassignedLetterPosition(int position)	{
		this.unassignedLetterPosition = position;
	}
	
	public int getUnassignedLetterPosition()	{
		return unassignedLetterPosition;
	}
}

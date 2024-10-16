import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Stack;

public class Hashing {

	public static void main(String[] args) {
		//start timer
		long startTime = System.currentTimeMillis();
		
		//list used to hold key words.
		ArrayList<Key> listOfKeys = new ArrayList<Key>();
		
		//method opens key word file then returns a scanner of the file of key words.
		Scanner keyWordFile = openTextFile("files/kywrdsOdd.txt");
		 
		//method reads the key word file and populates a list of keys.
		readKeys(keyWordFile, listOfKeys);
		
		//array will be used to count frequency of letters.
		int[] occurencesOfLetters = new int[26];

		//this method counts the frequency of letters and stores in occurenceOfLetters array.
		populateOccurencesOfLetters(listOfKeys, occurencesOfLetters);
		
		/*this method sets the value of all keywords based off the frequency of each word's 
		first and last letter.*/
		setValueOfAllKeys(listOfKeys, occurencesOfLetters);

		//This method sorts the list of keys by value in descending order.
		Collections.sort(listOfKeys);
				
		/*this arraylist takes values from occurences array but deletes characters 
		 * with frequencies of zero.*/
		ArrayList<Character> uniqueLetters = new ArrayList<Character>();
		populateUniqueLetters(uniqueLetters, occurencesOfLetters);
		
		/*g 2 dimensional array overview:
		 * collumn 0 stores g-values
		 * collumn 1 stores ascii values of characteres
		 * collumn 2 stores 0 if value for g has not been set and 1 if value for g has been set.
		 */
		int[][] g = new int[uniqueLetters.size()][3];	
		populateGArray(uniqueLetters, g);		

		//this hashtable will have keywords mapped to it using a hash function while the cichelli's algorithm is running.
		Key[] hashTable = new Key[listOfKeys.size()];
		
		/*max and mod values initialized. max value is utilized in cichelli's algorithm
		mod value is utilized in the hash function*/
		int maxValue = listOfKeys.size()/2;
		int modValue = listOfKeys.size();
		
		/*creating a stack and populating it with the keywords from my list of key words.
		it is easier to implement cichelli's algorithm with a stack rather than a list.*/
		Stack<Key> keyWordStack = new Stack<Key>();
		populateStack(listOfKeys, keyWordStack);
		
		//Cichelli's algorithm is called to map key words to the hashTable
		cichelli(keyWordStack, hashTable, g, modValue, maxValue);
		
		//this array is used to count the frequency each keyword appears in a subsequent text file.
		int[] keyWordCounter = new int[hashTable.length];
		//this method initializes the counter array with zeros.
		initializeCounter(keyWordCounter);
		
		//method opens text file then returns a scanner of the file.
		Scanner textFile = openTextFile("files/tstOdd.txt");
		
		/*this method reads the second text file. 
		Other methods checkForKeyWord and printResults are called within the readOtherFile method.
		The result is that the program will print number of keywords etc. present in the second text file.
		The hash function is used in order compare key words with the words of the second text file. the printed
		results are accurate thus proving this implementation of Cichelli's algorithm is effective.
		*/
		readOtherFile(textFile, g, hashTable, keyWordCounter, modValue);

		//end timer
		long endTime = System.currentTimeMillis();
		//calculate the time it took to run the program.
		long timeTaken = endTime - startTime;
		System.out.println("Execution time: " + timeTaken + " milliseconds");
		//System.out.println("Start time: " + startTime + " milliseconds");
		//System.out.println("End time: " + endTime + " milliseconds");
		
	}//end of main
	
	//method opens text file then returns a scanner of the file.
	public static Scanner openTextFile(String fileName)	{
		Scanner data;

		try{
            data = new Scanner(new File(fileName));
            return data;
        }
        catch(FileNotFoundException e){
            System.out.println(fileName  + " did not read correctly");
        }  
		data = null;
		return data;
	}
	
	//method reads the key word file and populates a list of keys.
	public static void readKeys(Scanner data, ArrayList<Key> listOfKeys)	{
		String currentToken;
		while(data.hasNext())	{
			currentToken = data.next();
			currentToken = currentToken.toLowerCase();
			Key currentKey = new Key(currentToken);
			listOfKeys.add(currentKey);
		}
	}
	
	//this method counts the frequency of letters and stores in occurenceOfLetters array.
	public static void populateOccurencesOfLetters(ArrayList<Key> listOfKeys, int[] occurencesOfLetters)	{
		//using an array of 26 to keep track of occurences of letters
		//initialize all array values to zero.
		for (int i = 0; i < 26; i += 1)	{
			occurencesOfLetters[i] = 0;
		}
		// count the frequency that each letter appears as a first or last letter
		for (Key e: listOfKeys)	{
			for (int i = 97; i < 123; i += 1)	{
				if (e.getFirstLetter() == (char) i)	{
					occurencesOfLetters[i - 97] += 1;
				}
				if (e.getLastLetter() == (char) i)	{
					occurencesOfLetters[i - 97] += 1;
				}
			}//end of for loop
		}//end of foreach loop		
	}
	
	/*this method sets the value of all keywords based off the frequency of each word's 
	first and last letter.*/
	public static void setValueOfAllKeys(ArrayList<Key> listOfKeys, int[] occurencesOfLetters)	{
		//set values of keys
		for(Key e : listOfKeys)	{
			int firstLetterValue = occurencesOfLetters[((int) e.getFirstLetter() - 97)];
			e.setFirstLetterValue(firstLetterValue);
			int lastLetterValue = occurencesOfLetters[((int) e.getLastLetter() - 97)];
			e.setLastLetterValue(lastLetterValue);
			int totalValue = firstLetterValue + lastLetterValue;
			e.setTotalValue(totalValue);
		}
	}
	
	//the uniqueLetters arrayList is populated with letters from the occurencesOfLetters array.
	public static void populateUniqueLetters(ArrayList<Character> uniqueLetters, int[] occurencesOfLetters)	{
		for(int i = 0; i < occurencesOfLetters.length; i += 1)	{
			if (occurencesOfLetters[i] != 0)	{
				uniqueLetters.add((char) (i+97));
			}
		}
	}
	
	//this method populates 2 dimension g array
	public static void populateGArray(ArrayList<Character >uniqueLetters, int [][] g)	{
		for (int i = 0; i < uniqueLetters.size(); i += 1)	{
			//collumn 0 holds g values. all initialized to zero
			g[i][0] = 0;
			//collumn 1 holds ascci values of letters.
			g[i][1] = (int) uniqueLetters.get(i);	
			//collumn 2 holds 0 if g-value is not set and 1 if g-value is set. all initialized to zero.
			g[i][2] = 0;
		}
	}
	
	//this method populates the stack with keys from the listOfKeys.
	public static void populateStack(ArrayList<Key> listOfKeys, Stack<Key> keyWordStack)	{
		for (int i = (listOfKeys.size() - 1); i >= 0; i -= 1)	{
			keyWordStack.push(listOfKeys.get(i));
		}
	}
	
	//Cichelli's algorithm is called to map key words to the hashTable and is a perfect hashing algorithm.
	public static boolean cichelli(Stack<Key> keyWordStack, Key [] hashTable, int[][] g, int modValue, int maxValue)	{
		
		while(keyWordStack.isEmpty() != true)	{
		
			Key word = keyWordStack.pop();
			
			//finding first and last g values by comparing 2d gArray to first and last letters of word.
			//setPositionInG refers to the row of the array where the letters was found.
			for (int i = 0; i < g.length; i += 1)	{
				if (g[i][1] == ((int) word.getFirstLetter()))	{
					word.setPositionInGFirst(i);
				}
				if (g[i][1] == ((int) word.getLastLetter()))	{	
					word.setpositionInGLast(i);
				}
			}
			

			//if values are already assigned for both letters try to place key in table
			if (g[word.getPositionInGFirst()][2] == 1 && g[word.getPositionInGLast()][2] == 1)	{
				//check if hash value for word is valid.
				if (hashTable[hashFunction(word, g[word.getPositionInGFirst()][0], g[word.getPositionInGLast()][0], modValue)] == null)	{
					//assign hash value to word
					hashTable[hashFunction(word, g[word.getPositionInGFirst()][0], g[word.getPositionInGLast()][0], modValue)] = word;
					//recursively call cichelli method
					if (cichelli(keyWordStack, hashTable, g, modValue, maxValue) == true)	{
						return true;
					}
					//detach the hash value for word
					else	{
						hashTable[hashFunction(word, g[word.getPositionInGFirst()][0], g[word.getPositionInGLast()][0], modValue)] = null;
						//set values of g array column 2 back to zero.
					}
				}
				keyWordStack.push(word);
				return false;
			}	
			
			//neither letter assigned g-value AND first != last letter
			else if((g[word.getPositionInGFirst()][2] == 0) && (g[word.getPositionInGLast()][2] == 0) && (word.getFirstLetter() != word.getLastLetter()))	{
				/*increment first g value up to maxValue times, but dont increment 1st iteration 
				to see if we get a hit while g value is still set to zero. Previous sentence explains
				why for loop condition is (maxValue + 1)*/
				for (int m = 0; m < (maxValue + 1); m += 1)	{
					//not incrementing g-value in first iteration
					if (m > 0)	{
						//increment g-value
						g[word.getPositionInGFirst()][0] += 1;
					}
					//check if hash value is valid if not we want to keep incrementing g.
					if (hashTable[hashFunction(word, g[word.getPositionInGFirst()][0], g[word.getPositionInGLast()][0], modValue)] == null)	{
						//assign hash value to word
						hashTable[hashFunction(word, g[word.getPositionInGFirst()][0], g[word.getPositionInGLast()][0], modValue)] = word;
						//set values of g array column 2 to 1.
						g[word.getPositionInGFirst()][2] = 1;
						g[word.getPositionInGLast()][2] = 1;
						//recursively call cichelli method
						if (cichelli(keyWordStack, hashTable, g, modValue, maxValue) == true)	{
							return true;
						}
						//detach the hash value for word
						else	{
						hashTable[hashFunction(word, g[word.getPositionInGFirst()][0], g[word.getPositionInGLast()][0], modValue)] = null;
						//set values of g array column 2 back to zero.
						g[word.getPositionInGFirst()][2] = 0;
						g[word.getPositionInGLast()][2] = 0;
						}
					
					}
				}//end of for loop
				/*I believe this following code is only reached if hashfunction has a hit 
				 but returns false at some point or if hash function has no hits! */		
				//reset g value
				g[word.getPositionInGFirst()][0] = 0;
				keyWordStack.push(word);
				return false;	
			}//end of else if
			
			
			// else refers to case where only one letter assigned g-value OR first = last letter
			else	{
				//determine which letter(first or last) is assigned a g value.
				//if the following condition is true than the first letter has a g value and last letter will not
				if (g[word.getPositionInGFirst()][2] == 0)	{
					word.setUnassignedLetterPosition(word.getPositionInGFirst());
					
				}
				// reaches (else if) if the first letter does not have a gvalue. still possible neither has a g value.
				else if (g[word.getPositionInGLast()][2] == 0)	{
					word.setUnassignedLetterPosition(word.getPositionInGLast());
					
				}
				/*reaches else. if the first letter = last letter
				this case should not be reached with the given set of keywords.*/
				else	{
					//there is no unassigned letter first = last.
					//set to arbitrary value of -1.
					word.setUnassignedLetterPosition(-1);
				}
				
				/*increment the unassigned letter's g value up to maxValue times, but dont increment 1st iteration 
				to see if we get a hit while g value is still set to zero. Previous sentence explains
				why for loop condition is (maxValue + 1)*/
				for (int m = 0; m < (maxValue + 1); m += 1)	{
					//not incrementing g-value in first iteration
					if(m > 0)	{
						//increment g-value
						g[word.getUnassignedLetterPosition()][0] += 1;
					}
					//check if hash value is valid if not we want to keep incrementing g.
					if (hashTable[hashFunction(word, g[word.getPositionInGFirst()][0], g[word.getPositionInGLast()][0], modValue)] == null)	{
						//assign hash value to word
						hashTable[hashFunction(word, g[word.getPositionInGFirst()][0], g[word.getPositionInGLast()][0], modValue)] = word;
						//only need to change the unassigned letter's set field to 1.
						g[word.getUnassignedLetterPosition()][2] = 1;
						//recursively call cichelli's method
						if (cichelli(keyWordStack, hashTable, g, modValue, maxValue) == true)	{
							return true;
						}
						//detach the hash value for word  
						else	{
						hashTable[hashFunction(word, g[word.getPositionInGFirst()][0], g[word.getPositionInGLast()][0], modValue)] = null;
						//set unassigned letters set field back to zero.
						g[word.getUnassignedLetterPosition()][2] = 0;
						}
					}
				}//end of for loop
				/*I believe this following code is only reached if hashfunction has a hit but returns false at some point
				 * or if hash function has no hits!
				 */			
				//reset unassigned letters g value
				g[word.getUnassignedLetterPosition()][0] = 0;
				keyWordStack.push(word);
				return false;
			}//end of else
				
		}//end of while
		// empty stack means we have a solution
		return true;   
	}//end of Cichelli's method
			
	
	//overloaded hash function takes Key data type as an argument		
	public static int hashFunction(Key keyWord, int gFirst, int gLast, int modValue)	{
		int hashValue = (keyWord.getKeyWord().length() + gFirst + gLast) % modValue;
		return hashValue;
	}
	
	//overloaded hash function takes String data type as an argument.
	public static int hashFunction(String word, int gFirst, int gLast, int modValue)	{
		int hashValue = (word.length() + gFirst + gLast) % modValue;
		return hashValue;
	}
	
	//this method initializes the keyWordCounter array with zeros.
	public static void initializeCounter(int[] keyWordCounter)	{
		for (int i = 0; i < keyWordCounter.length; i += 1)	{
			keyWordCounter[i] = 0;
		}
	}

	public static void readOtherFile(Scanner data, int g[][], Key[] hashTable, int[] keyWordCounter, int modValue)	{
		int lineCounter = 0, wordCounter = 0;
		
		String x;
        String []y;
        while(data.hasNextLine()){
        	lineCounter += 1;  
            x = data.nextLine();
            
            /*the following conditional statement takes care of the issue of their being an
             * entirely blank line encountered before reaching the end of the text file.
             */
            if(x.length() == 0) {
            	x = data.nextLine();
            }
            
            x = x.toLowerCase();
			x = x.replaceAll("[,.()]","");
          
            
            y = x.split(" ");
            wordCounter +=  y.length;
            
            //method compares a token to a key word to see if they are identical.
            checkForKeyWord(y, g, hashTable, keyWordCounter, modValue);
        }
        //method prints statistical results
        printResults(lineCounter, wordCounter, hashTable, keyWordCounter);
	}
	
	
	//method compares a token to a key word to see if they are identical.
	public static void checkForKeyWord(String[] words, int[][] g, Key[] hashTable, int[] keyWordCounter, int modValue)	{
		for(String word: words)	{
			char firstLetter = word.charAt(0),  lastLetter = word.charAt(word.length() - 1);
			boolean firstLetterBool = false, lastLetterBool = false;
			int firstGvalue = 0, lastGvalue = 0;
			
		
			for(int i = 0; i < g.length; i += 1)	{
				if(firstLetter == (char) g[i][1]) {
					firstLetterBool = true;
					firstGvalue = g[i][0];
				}
				if (lastLetter == (char) g[i][1])	{
					lastLetterBool = true;
					lastGvalue = g[i][0];
				}
			}
			if (firstLetterBool == true && lastLetterBool == true)	{
				int index = hashFunction(word, firstGvalue, lastGvalue, modValue);
				if (word.equals(hashTable[index].getKeyWord()))	{
					keyWordCounter[index] += 1;
				}
			}
		}
	}
	
	//method prints statistical results
	public static void printResults(int lineCounter, int wordCounter, Key[] hashTable, int[] keyWordCounter)	{
		System.out.println("Total Lines Read " + lineCounter);
		System.out.println("Total Words Read " + wordCounter);
		System.out.println("Break down by key word");
		for(int i = 0; i < hashTable.length; i += 1)	{
			System.out.println("    " + hashTable[i].getKeyWord() + ": " + keyWordCounter[i]);
		}
		int totalKeys = 0;
		for(int e: keyWordCounter)	{
			totalKeys += e;
		}
		System.out.println("Total Keywords: " + totalKeys);
	}
	
	
}//end of class

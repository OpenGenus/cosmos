// Part of Cosmos by OpenGenus Foundation

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * Given n men and n women, where each person has ranked each person of the opposite sex according to their 
 * preference. Males and females are matched such that there are no two people of opposite sex who would 
 * both rather have each other than their current partners. 
 */
public class StableMatching {
	private List<String> males;
	private List<String> females;
	private int[][] rank;
	private String[] currentMatch;
	private String[][] malePref;
	private String[][] femalePref;

	public StableMatching(String[] m, String[] f, String[][] mPref, String[][] fPref) {
		males = new ArrayList<>(Arrays.asList(m));
		females = new ArrayList<>(Arrays.asList(f));
		malePref = mPref;
		femalePref = fPref;
		
		// create an array which represents the current partner of each woman
		currentMatch = new String[f.length];
		
		createRankMatrix();
		
		findStableMatching();
	}
	
	/**
	 * An implementation of the Gale-Shapely algorithm
	 */
	private void findStableMatching() {
		
		// initially all men are free
		List<String> freeMales = new LinkedList<>(males);
		
		// create a pointer for each man which indicates the next woman on their preference list
		int[] nextCandidate = new int[males.size()];

		while (!freeMales.isEmpty())	{
			
			// choose a free male and his index
			String freeMale = freeMales.get(0);
			int freeMaleIndex = males.indexOf(freeMale);
			
			// find the next female on his preference list to whom he has not made an offer yet
			String candidateFemale = malePref[freeMaleIndex][nextCandidate[freeMaleIndex]];
			int femaleIndex = females.indexOf(candidateFemale);
			
			nextCandidate[freeMaleIndex]++;
			
			// if the female is free, form a match and remove male from free males
			if (currentMatch[femaleIndex] == null) {
				currentMatch[femaleIndex] = freeMale;
				freeMales.remove(0);
			
			// otherwise compare ranking of the two males
			} else {
				// get the females current partner and his index
				String currentPartner = currentMatch[femaleIndex];
				int currentPartnerIndex = males.indexOf(currentPartner);
				
				// if the female prefers the new male to her current, form a match and remove male from free males
				if (rank[freeMaleIndex][femaleIndex] < rank[currentPartnerIndex][femaleIndex]) {
					currentMatch[femaleIndex] = freeMale;
					freeMales.remove(0);
					freeMales.add(currentPartner);
				}
			}
		}
	}
	
	/**
	 * Creates a rank matrix in which the (i,j)th entry represents the ranking of male i by
	 * female j. This allows the rank of a male to each female to be found in constant time.
	 * @param femalePref 
	 */
	private void createRankMatrix() {
		int n = males.size();
		rank = new int[n][n];
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++){
				int maleIndex = males.indexOf(femalePref[i][j]);
				rank[maleIndex][i] = j;
			}
		}
	}
	
	public void printMatches() {
		System.out.println("Matches : ");
		for (int i = 0; i < currentMatch.length; i++) {
			System.out.println(currentMatch[i] + ", " + females.get(i));
		}
	}
	
	public static void main(String args[]) {
		
		// list of males
		String[] m = {"M1", "M2", "M3", "M4", "M5"};
        
		// list of females
        String[] f = {"F1", "F2", "F3", "F4", "F5"};
 
        // males preference list
        String[][] mPref = {{"F4", "F1", "F2", "F3", "F5"}, 
                         	{"F2", "F3", "F4", "F5", "F1"}, 
                         	{"F4", "F5", "F1", "F2", "F3"}, 
                         	{"F5", "F1", "F2", "F3", "F4"},
                         	{"F1", "F2", "F3", "F4", "F5"}};
        // females preference list                    
        String[][] fPref = {{"M5", "M1", "M2", "M3", "M4"}, 
	                        {"M4", "M1", "M5", "M3", "M2"}, 
	                        {"M1", "M3", "M2", "M4", "M5"},
	                        {"M4", "M5", "M3", "M2", "M1"}, 
	                        {"M2", "M1", "M3", "M4", "M5"}};
        
       StableMatching matching = new StableMatching(m, f, mPref, fPref);
       
       matching.printMatches();
	}

}
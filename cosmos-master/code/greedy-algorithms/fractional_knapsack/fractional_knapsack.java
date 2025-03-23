/* Part of Cosmos by OpenGenus Foundation */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;

/**
 * Added by Vishesh Dembla on October 07, 2017
 */

public class fractional_knapsack {

    private double finalValue;
    private int remainingWeight;
    private Item [] itemList;

    public fractional_knapsack( int totalWeight, Item [] itemList) {
        this.finalValue = 0;
        this.remainingWeight = totalWeight;
        this.itemList = itemList;
        //Sorting the array in descending order based upon the preference order
        Arrays.sort(itemList);
    }

    public double getFinalValue() {
        return finalValue;
    }

    public int getRemainingWeight() {
        return remainingWeight;
    }

    public Item [] getFractions(){
        int i = 0;
        
        //Setting fraction of preffered items as 1.0, if their weight is less than the total remaining weight
        while(i  < itemList.length && remainingWeight > itemList[i].getWeight()){
            remainingWeight -= itemList[i].getWeight();
            finalValue += itemList[i].getValue();
            itemList[i].setFraction(1.0);
            i++;
        }
        
        if( i < itemList.length) {
            //Calculating the fraction of the item whoes weight is greater than the current remaining weight
            finalValue = finalValue + (remainingWeight) * itemList[i].getValue() / itemList[i].getWeight();
            itemList[i].setFraction(remainingWeight / itemList[i].getWeight());
            remainingWeight = 0 ;
        }

        return itemList;
    }

    public static void main(String args[]){
        int totalWeight = 90;
        Item [] items = {new Item(10,60) , new Item(20,100) , new Item(30, 120)};

        fractional_knapsack fractionalKnapsack = new fractional_knapsack(totalWeight , items);

        items = fractionalKnapsack.getFractions();
        System.out.println("TOTAL VALUE = "+fractionalKnapsack.getFinalValue()+" REMAINING WEIGHT = "+fractionalKnapsack.getRemainingWeight());
        for(int i = 0 ; i < items.length ; i++)System.out.print("ITEM "+(i+1) +" "+items[i]);
    }

}



class Item implements Comparable<Item>{
    private int weight;
    private int value;

    
    private double preference;
    private double fraction;

    public Item(int weight, int value) {

        this.weight = weight;
        this.value = value;
        this.fraction = 0.0;
        //Attribute preference helps to decide the order of preference of the items for selection
        this.preference = (double) value / (double) weight;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public double getFraction() {
        return fraction;
    }

    public void setFraction(double fraction) {
        this.fraction = fraction;
    }

    
     //Enabling sort in descending order
    @Override
    public int compareTo(Item item) {
        double difference = this.preference - item.preference;
        if(difference > 0)
            return -1;
        else if(difference < 0)
            return 1;
        else
            return 0;
    }
    @Override
    public String toString(){
        return "VALUE = "+this.value+" WEIGHT = "+this.weight+" FRACTION = "+this.fraction+"\n";
    }
}

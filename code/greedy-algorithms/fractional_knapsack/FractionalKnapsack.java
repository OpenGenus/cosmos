import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;

/**
 * Created by I341429 on 10/7/2017.
 */
public class FractionalKnapsack {

    private double finalValue;
    private int remainingWeight;
    private Item [] itemList;

    public FractionalKnapsack( int totalWeight, Item [] itemList) {
        this.finalValue = 0;
        this.remainingWeight = totalWeight;
        this.itemList = itemList;
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
        while(i  < itemList.length && remainingWeight > itemList[i].getWeight()){
            remainingWeight -= itemList[i].getWeight();
            finalValue += itemList[i].getValue();
            itemList[i].setFraction(1.0);
            i++;
        }
        if( i < itemList.length) {

            finalValue = finalValue + (remainingWeight) * itemList[i].getValue() / itemList[i].getWeight();

            itemList[i].setFraction(remainingWeight / itemList[i].getWeight());
            remainingWeight = 0 ;
        }

        return itemList;
    }

    public static void main(String args[]){
        int totalWeight = 90;
        Item [] items = {new Item(10,60) , new Item(20,100) , new Item(30, 120)};

        FractionalKnapsack fractionalKnapsack = new FractionalKnapsack(totalWeight , items);

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

    @Override
    public int compareTo(Item item) {
        double difference = this.preference - item.preference;
        if(difference > 0)
            return 1;
        else if(difference < 0)
            return -1;
        else
            return 0;
    }
    @Override
    public String toString(){
        return "VALUE = "+this.value+" WEIGHT = "+this.weight+" FRACTION = "+this.fraction+"\n";
    }
}

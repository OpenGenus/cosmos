/*

// design pattern | OOP patterns | adapter | civilian | JAVA
// Part of Cosmos by OpenGenus Foundation

*/


package Adapter;

public class Civilian implements Movement {
    @Override
    public void walk() {
        System.out.println("I'm having a beautiful stroll in my happy, little peaceful town.");
    }
}

/*

// design pattern | OOP patterns | factory | gifts | nothing | JAVA
// Part of Cosmos by OpenGenus Foundation

*/


package factory.gifts;

public class Nothing implements Gift {
    @Override
    public String message() {
        return "YOU WON NOTHING!";
    }
}

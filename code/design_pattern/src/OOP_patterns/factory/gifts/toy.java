/*

// design pattern | OOP patterns | factory | gifts | toy | JAVA
// Part of Cosmos by OpenGenus Foundation

*/


package factory.gifts;

public class Toy implements Gift {
    @Override
    public String message() {
        return "You won a toy! Be happy";
    }
}

package factory.gifts;

public class Nothing implements Gift {
    @Override
    public String message() {
        return "YOU WON NOTHING!";
    }
}

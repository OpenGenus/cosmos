package factory.gifts;

public class Car implements Gift {
    @Override
    public String message() {
        return "Nobody wins a car, it's a prank, bro";
    }
}

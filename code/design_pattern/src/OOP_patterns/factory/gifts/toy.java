package factory.gifts;

public class Toy implements Gift {
    @Override
    public String message() {
        return "You won a toy! Be happy";
    }
}

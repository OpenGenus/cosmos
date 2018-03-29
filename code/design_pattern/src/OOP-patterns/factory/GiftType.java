package factory;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public enum GiftType {
    Nothing, Car, Toy, Booze, Error;

    public GiftType fromString(String from) {
        if (from.equalsIgnoreCase("nothing"))
            return Nothing;

        if (from.equalsIgnoreCase("car"))
            return Car;

        if (from.equalsIgnoreCase("toy"))
            return Toy;

        if (from.equalsIgnoreCase("booze"))
            return Booze;

        return Error;
    }

    private static final List<GiftType> VALUES =
            Collections.unmodifiableList(Arrays.asList(values()));
    private static final int SIZE = VALUES.size();
    private static final Random RANDOM = new Random();

    public static GiftType randomGift() {
        return VALUES.get(RANDOM.nextInt(SIZE));
    }
}

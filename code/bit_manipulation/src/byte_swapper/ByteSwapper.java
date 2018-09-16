// Part of Cosmos by OpenGenus Foundation
public class ByteSwapper {

    private ByteSwapper() {
        throw new AssertionError();
    }

    public static short swap (short value) {
        int b1 = value & 0xFF;
        int b2 = value >> 8 & 0xFF;
        return (short) (b1 << 8 | b2 << 0);
    }

    public static int swap (int value) {
        int b1 = value >> 0 & 0xff;
        int b2 = value >> 8 & 0xff;
        int b3 = value >> 16 & 0xff;
        int b4 = value >> 24 & 0xff;
        return b1 << 24 | b2 << 16 | b3 << 8 | b4 << 0;
    }

    public static long swap (long value) {
        long b1 = value >> 0 & 0xff;
        long b2 = value >> 8 & 0xff;
        long b3 = value >> 16 & 0xff;
        long b4 = value >> 24 & 0xff;
        long b5 = value >> 32 & 0xff;
        long b6 = value >> 40 & 0xff;
        long b7 = value >> 48 & 0xff;
        long b8 = value >> 56 & 0xff;
        return b1 << 56 | b2 << 48 | b3 << 40 | b4 << 32 | b5 << 24 | b6 << 16 | b7 << 8 | b8 << 0;
    }

    public static float swap (float value) {
        int intValue = Float.floatToIntBits(value);
        intValue = swap(intValue);
        return Float.intBitsToFloat(intValue);
    }

    public static double swap (double value) {
        long longValue = Double.doubleToLongBits(value);
        longValue = swap(longValue);
        return Double.longBitsToDouble(longValue);
    }

    public static void swap (final short[] array) {
        if (array == null || array.length <= 0) {
            throw new IllegalArgumentException("Array can't be null or empty");
        }
        for (int i = 0; i < array.length; i++) {
            array[i] = swap(array[i]);
        }
    }

    public static void swap (int[] array) {
        if (array == null || array.length <= 0) {
            throw new IllegalArgumentException("Array can't be null or empty");
        }
        for (int i = 0; i < array.length; i++) {
            array[i] = swap(array[i]);
        }
    }

    public static void swap (long[] array) {
        if (array == null || array.length <= 0) {
            throw new IllegalArgumentException("Array can't be null or empty");
        }
        for (int i = 0; i < array.length; i++) {
            array[i] = swap(array[i]);
        }
    }

    public static void swap (float[] array) {
        if (array == null || array.length <= 0) {
            throw new IllegalArgumentException("Array can't be null or empty");
        }
        for (int i = 0; i < array.length; i++) {
            array[i] = swap(array[i]);
        }
    }

    public static void swap (double[] array) {
        if (array == null || array.length <= 0) {
            throw new IllegalArgumentException("Array can't be null or empty");
        }
        for (int i = 0; i < array.length; i++) {
            array[i] = swap(array[i]);
        }
    }
}

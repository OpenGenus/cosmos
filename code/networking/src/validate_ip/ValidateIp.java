import java.util.Arrays;
import java.util.regex.Pattern;

public class ValidateIp {
    public static void main(String[] args) {
        assert (isValid("172.16.254.1"));
        assert (!isValid("172.16.254.01"));
        assert (isValid("2001:0db8:85a3:0000:0000:8a2e:0370:7334"));
        assert (isValid("2001:db8:85a3:0:0:8A2E:0370:7334"));
        assert (!isValid("02001:0db8:85a3:0000:0000:8a2e:0370:7334"));
    }

    private static boolean isValid(String addr) {
        if (addr.contains(".")) {
            return isValidv4(addr);
        }
        if (addr.contains(":")) {
            return isValidv6(addr);
        }
        return false;
    }

    private static boolean isValidv4(String addr) {
        Pattern pattern = Pattern.compile("(?:(?:(?:[1-9][0-9]{0,2})|0)\\.){3}(?:(?:[1-9][0-9]{0,2})|0)");
        if (!pattern.matcher(addr).matches()) {
            return false;
        }
        return Arrays.stream(addr.split("\\.")).noneMatch(s -> Integer.parseInt(s) > 255);
    }

    private static boolean isValidv6(String addr) {
        Pattern pattern = Pattern.compile("(?:(?:(?:[0-9a-fA-F]{1,4})):){7}(?:(?:[0-9a-fA-F]{1,4}))");
        return pattern.matcher(addr).matches();
    }
}

/**
 * Check if an IP address conforms to IPv4 standards
 * */
import java.util.regex.Pattern;

class IPvalidator{
    public static boolean isIPV4(String ipAddr){
        Pattern PATTERN = Pattern.compile("^(([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.){3}([01]?\\d\\d?|2[0-4]\\d|25[0-5])$");
        return PATTERN.matcher(ipAddr).matches();
    }
    
    public static void main(String[] args){
        String validIP = "192.168.0.1";
        String invalidIP = "31.0.1.2000";
        System.out.println(isIPV4(validIP));
        System.out.println(isIPV4(invalidIP));
    }
}
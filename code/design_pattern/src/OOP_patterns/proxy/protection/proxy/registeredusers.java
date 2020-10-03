package protection.proxy;

import java.util.HashMap;
import java.util.Map;

public class RegisteredUsers {
    static Map<String, String> registered = new HashMap<String, String>(){
        {
            put("Robert", "123");
            put("David", "pass");
            put("Gangplank", "Illaoi");
        }
    };
}

import java.util.HashMap;
import java.util.Map;

class Problem019 {
    public static void main(String args[]){
        Map<Integer, String> L = new HashMap<Integer, String>();
        L.put(1, "Sun");
        L.put(2, "Mon");
        L.put(3, "Tue");
        L.put(4, "Wed");
        L.put(5, "Thurs");
        L.put(6, "Fri");
        L.put(7, "Sat");
     
        // Start at Monday, 1st, 1900
        int counter = 1;
        int tally = 0;
         
        // Year
        for (int yr = 1900; yr < 2001;  ++ yr)
        {
            System.out.println("Year = " + yr);
            // Month
            for (int month = 1; month < 13; month ++)
            {
                int y = findDays(month, yr);
                // Number of month days
                for (int monthDays = 1; monthDays <= y; monthDays ++) 
                {
                    // Start at Monday, 1st, 1900
                    counter = (counter % 7) + 1;
                    if ((monthDays == 1) && (L.get(counter) == "Sun"))
                    {
                        System.out.println("month_days = " + monthDays);
                        if( yr != 1900)
                            tally += 1;
                    }
                }
            }
            System.out.println();
        }
        System.out.println("tally = " + tally );
    }
    public static int findDays(int month, int yr){
        int d = 0;
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) ||
        (month == 8) || (month == 10) || (month == 12))
        {
            d = 31;
        }
        else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
        {
            d = 30;
        }
        else if (month == 2)
        {
            d = (yr % 4 == 0 && (yr % 100 != 0 || yr % 400 == 0)) ? 29 : 28;
        }
        else
        {
          throw new ArithmeticException("Month is out of bound !"); 
        }
        return d;
    }
}

import java.util.HashMap;
import java.util.Map;
 
 
public class Problem_19 {
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
        for (int yr = 1900; yr < 2001; yr ++)
        {
            System.out.println("Year = " + yr);
            // Month
            for (int month = 1; month < 13; month ++)
            {
                int y = find_days(month, yr);
                for (int month_days = 1; month_days <= y; month_days ++) // Number of month days
                {
                    // Start at Monday, 1st, 1900
                    counter += 1;
                    if ((month_days == 1) && (L.get(counter) == "Sun"))
                    {
                        System.out.println("month_days = " + month_days);
                        tally += 1;
                    }
                    // Days of the week
                    if (counter >= 7)
                    {
                        counter = 0;
                    }
                }
            }
            System.out.println();
        }
        // subtract 2 for the year 1900 - start counting at 1901
        System.out.println("tally = " + (tally - 2));
    }
    public static int find_days(int month, int yr){
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
        else if ((month == 2))
        {
            if (yr % 4 == 0)
            {
                if (yr % 100 == 0)
                {
                    if (yr % 400 == 0)
                    {
                        d = 29;
                    }
                    else
                    {
                        d = 28;
                    }
                } 
                else
                {
                    d = 29;
                }
            }
            else
            {
                d = 28;
            }
        }
        else
        {
            System.out.println("There has been an error");
        }
        return d;
    }
}

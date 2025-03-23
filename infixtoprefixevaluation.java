import java.util.Stack;
public class infixtoprefix
{
    public static boolean isoperator(char ch)
    {
        if(ch=='+'||ch=='-'||ch=='/'||ch=='*'||ch=='%'||ch=='^')
        {
            return true;
        }
        return false;
    }
    public static int priority(char ch)
    {
        if(ch=='+'||ch=='-')
        {
            return 0;
        }
        else if(ch=='/'||ch=='*'||ch=='%')
        {
            return 1;
        }
        else if(ch=='^')
        {
            return 2;
        }
        return -1;
    }
    public static String infixtopre(String str)
    {
        Stack<String> strst=new Stack<>();
        Stack<Character> opst=new Stack<>();
        str.reverse();
        System.out.println(str);
        for(int i=0;i<str.length();i++)
        {
            char ch=str.charAt(i);
            if(ch==')')
            {
                ch='(';
            }
            else if(ch=='(')
            {
                ch=')';
            }
            else if(ch>='0' && ch<='9')
            {
                strst.push(ch+"");
            }
            else if(ch=='(')
            {
                opst.push(ch);
            }
            else if(isoperator(ch))
            {
                while(opst.size()!=0 && priority(opst.peek())>priority(ch) && opst.peek()!='(')
                {
                    String val1=strst.pop();
                    String val2=strst.pop();
                    char c=opst.pop();

                    strst.push(val2+val1+c+"");
                }
                opst.push(ch);
            }
            else 
            {
                while(opst.peek()!='(')
                {
                String val1=strst.pop();
                String val2=strst.pop();
                char c=opst.pop();

                strst.push(val2+val1+c+"");   
                }
                opst.pop();
            }
        }
        while(opst.size()!=0)
        {
            String val1=strst.pop();
            String val2=strst.pop();
            char c=opst.pop();
            strst.push(val2+val1+c+"");
        }
        return strst.pop();
    }
    public static void main(String[] args)
    {
        //StringBuilder str=new StringBuilder("1+2*3-4^(5+6)");
        System.out.println(infixtopre(str));
    }
}

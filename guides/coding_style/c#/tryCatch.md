---
Title: Try Catch Statement
---

## Try Catch in CSharp
In the world of programming most of the time for the newbie, they only code in a linear way, assuming that it will be a good practice
and most of the time learning to error exception handling is left behind. 

But it's only just a normal for newbie programmers as I came from the same shoes.:)

Since I start developing I always thinking in linear way of coding until such time that my code is mixing up together.

I really came accross to hardly maintain especially I don't have any error handlers before but now I always implement it in my bunch of
code as necessary.

In C# the try-catch statement consists of a try block followed by one or more catch clauses, which specify handlers for different 
exceptions. When an exception is thrown, the common language runtime (CLR) looks for the catch statement that handles this exception. 
If the currently executing method does not contain such a catch block, the CLR looks at the method that called the current method, 
and so on up the call stack. If no catch block is found, then the CLR displays an unhandled exception message to the user and stops 
execution of the program.

You can read more from here in [MSDN](https://msdn.microsoft.com/en-us/library/0yd65esw(v=vs.90).aspx).

Going back! 

Here is my example of coding in C# for exception handling.

```
protected void btnSave_Click(object sender, EventArgs e)
    {
        var insCmd = new MySqlCommand("INSERT INTO user VALUES (@Id, @firstNm, @lastNm, @Role)", con);

        insCmd.Parameters.AddWithValue("@Id", txtId.Text);
        insCmd.Parameters.AddWithValue("@firstNm", txtFirstNm.Text);
        insCmd.Parameters.AddWithValue("@lastNm", txtLastNm.Text);
        insCmd.Parameters.AddWithValue("@Role", ddlRole.SelectedItem);

        try
        {
            con.Open();
            insCmd.ExecuteNonQuery();
            lblMessage.Visible = true;
            lblMessage.Text = "Successfully Saved!";
            
        }
        catch (Exception ex)
        {
            lblMessage.Visible = true;
            lblMessage.Text = "Error: " + ex.Message;

        }
        con.Close();
        txtFirstNm.Text = "";
        txtLastNm.Text = "";
    }
```
The above code is came from one of my web based project where try catch is execute a message error if there will be an invalid character
to insert in the database.

Through this strategy it will avoid your program or web application to crushed in an unexpected situation.

Hope it helps!

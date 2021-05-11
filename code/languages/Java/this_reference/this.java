//Code to show 'this' reference in Java
class Cosmos 
{
    int a;
    int b;

    // Parameterized constructor
    Cosmos(int a, int b) 
    {
        this.a = a;
        this.b = b;
    }

    void display() 
    {
        System.out.println("a = " + a + " b = " + b);
    }

    public static void main(String[] args) 
    {
        Cosmos object = new Cosmos(60, 100);
        object.display();
    }
}

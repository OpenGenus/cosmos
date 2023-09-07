package design_pattern;

 class Singleton {
    private static Singleton instance = new Singleton();
    private Singleton(){}
    public static Singleton getInstance(){
        return instance;
    }

}
public class SingletonPattern {
    public static void main(String[] args) {
        Singleton object = Singleton.getInstance();
    }
}


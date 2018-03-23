import observer.Observer;
import observer.Subject;
import observer.network.Artist;
import observer.network.Fan;

public class Demo {
    public void startDemo() {
        Observer f1 = new Fan("Robert");
        Observer f2 = new Fan("David");
        Observer f3 = new Fan("Gangplank");

        Subject<String> s1 = new Artist("Erik Mongrain");
        Subject<String> s2 = new Artist("Antoine Dufour");

        s1.subscribe(f1);
        s1.subscribe(f2);

        s2.subscribe(f2);
        s2.subscribe(f3);

        s1.addNotification("New album coming out!!");
        s2.addNotification("I'll be having a concert in Romania!");

        s1.addNotification("Im so happy!");
        s2.addNotification("How does this work?");
    }
}

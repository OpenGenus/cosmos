/*

// design pattern | OOP patterns | observer java | observer | subject | JAVA
// Part of Cosmos by OpenGenus Foundation

*/


package observer;

public interface Subject<T extends String> {
    void subscribe(Observer o);

    void unsubscribe(Observer o);

    void notifyObservers();

    String getLastNotification();

    void addNotification(T notification);
}

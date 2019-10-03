package observer;

public interface Subject<T extends String> {
    void subscribe(Observer o);

    void unsubscribe(Observer o);

    void notifyObservers();

    String getLastNotification();

    void addNotification(T notification);
}

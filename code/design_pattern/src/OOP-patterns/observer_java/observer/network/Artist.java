package observer.network;

import observer.Observer;
import observer.Subject;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Artist<T extends String> implements Subject {
    private Set<Observer> observers;

    private String name;

    private List<String> updates;

    public Artist(String name) {
        this.name = name;
        this.observers = new HashSet<>();
        this.updates = new ArrayList<>();
    }

    public Artist(Set<Observer> observers) {
        this.observers = observers;
        this.updates = new ArrayList<>();
    }

    @Override
    public String getLastNotification() {
        return "[ " + this.name + " ] " + this.updates.get(this.updates.size() - 1);
    }

    @Override
    public void addNotification(String notification) {
        System.out.println("[ " + this.name + " ] " + notification);
        updates.add(notification);
        this.notifyObservers();
    }

    @Override
    public void subscribe(Observer o) {
        this.observers.add(o);
    }

    @Override
    public void unsubscribe(Observer o) {
        this.observers.remove(o);
    }

    @Override
    public void notifyObservers() {
        observers.forEach(o -> o.receiveNotification(this));
    }
}

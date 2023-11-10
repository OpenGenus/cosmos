package observer.network;

import observer.Observer;

import java.util.*;

public class Fan implements Observer {
    private String name;
    private Set<Artist> followedSubjects;

    public Fan(String name) {
        this.followedSubjects = new HashSet<>();
        this.name = name;
    }

    public Fan(Set<Artist> subjectsToFollow) {
        this.followedSubjects = subjectsToFollow;
    }

    public void addSubject(Artist subject) {
        subject.subscribe(this);
        this.followedSubjects.add(subject);
    }

    public Set<Artist> getFollowedSubjects() {
        return new HashSet<>(followedSubjects);
    }

    @Override
    public void receiveNotification(observer.Subject from) {
        System.out.println("[" + this.name + "] " + from.getLastNotification());
    }
}

# Observer Design Pattern
It is a software design pattern in which an object, called the subject, maintains a list of its dependents, called observers, and notifies them automatically of any state changes, usually by calling one of their methods. It is the "view" part in the MVC architectural pattern.

Observer pattern uses three actor classes.
* Subject 
* Observer
* Client

Subject is an object having methods to attach and detach observers to a client object. We have created an abstract class Observer and a concrete class Subject that is extending class Observer.

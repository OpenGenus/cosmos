/*

// design pattern | OOP patterns | adapter | soldiers | adaptee | JAVA
// Part of Cosmos by OpenGenus Foundation

*/


package Adapter.Soldiers;

public interface Adaptee {
    void walk();

    void changeWalkStyle(Order newStyle);
}

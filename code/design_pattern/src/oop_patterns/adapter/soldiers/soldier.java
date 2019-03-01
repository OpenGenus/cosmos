package Adapter.Soldiers;

public class Soldier implements Adaptee {
    private Order order;

    @Override
    public void walk() {
        System.out.println("IM " + order + ", SIR, YES, SIR!");
    }

    @Override
    public void changeWalkStyle(Order newStyle) {
        this.order = newStyle;
    }
}

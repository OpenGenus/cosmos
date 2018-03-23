package Adapter;

import Adapter.Soldiers.Adaptee;
import Adapter.Soldiers.General;

public class Adaptor implements Movement {
    public Adaptee adaptee;

    public General general;

    public Adaptor(Adaptee adaptee, General general) {
        this.adaptee = adaptee;
        this.general = general;
    }


    @Override
    public void walk() {
        adaptee.changeWalkStyle(general.receiveOrder());
        adaptee.walk();
    }
}

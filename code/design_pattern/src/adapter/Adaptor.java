package Adapter;

import Adapter.Soldiers.Adaptee;
import Adapter.Soldiers.General;

public class Adaptor implements Movement {
    public Adaptee adaptee;

    public General general;

    public Adaptor(Adaptee a, General g){
        adaptee = a;
        this.general = g;
    }


    @Override
    public void walk() {
        adaptee.changeWalkStyle(general.receiveOrder());
        adaptee.walk();
    }
}

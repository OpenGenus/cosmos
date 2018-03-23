package Adapter.Soldiers;

import Adapter.Movement;

import java.util.List;

public class General {
    private Order order;

    public List<Adaptee> troopsUnderCommand;

    public void setOrder(Order order) {
        this.order = order;
    }

    public Order receiveOrder() {
        if (order == null)
            return Order.AT_EASE;

        return order;
    }
}

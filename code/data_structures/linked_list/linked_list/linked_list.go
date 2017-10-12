package main

import "fmt"

type node struct {
    next *node
    label string
}

func (list *node) insert(new_label string) *node {
    if list == nil {
        new_node := &node {
            next: nil,
            label: new_label,
        }
        return new_node
    } else if list.next == nil {
        new_node := &node{
            next: nil,
            label: new_label,
        }
        list.next = new_node
    } else {
        list.next.insert(new_label)
    }
    return nil
}

func (list *node) print_list() {
    head := list.next
    for head != nil {
        fmt.Println(head.label)
        head = head.next
    }
}

func (list *node) remove(remove_label string) {
    if list.next == nil {
        return
    } else if list.next.label == remove_label {
        list.next = list.next.next
    } else {
        list.next.remove(remove_label)
    }
}

func main() {
    l := &node{
        next: nil,
        label: "-1",
    }

    l.insert("a")
    l.insert("b")
    l.insert("c")
    l.insert("d")
    l.insert("e")

    l.print_list()

    fmt.Println("After Removing label C")
    l.remove("c")

    l.print_list()

}

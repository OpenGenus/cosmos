class Insertion_SiglyLinkedList {
    // A linked list Node
    static class Node {
        public int data;
        public Node nextNode;

        // inserting the required data
        public Node(int data) {
            this.data = data;

        }
    }

    // function to create and return a Node
    static Node GetNode(int data) {
        return new Node(data);
    }

    // function to insert a Node at required position
    static Node InsertPos(Node headNode, int position, int data) {
        Node head = headNode;
        if (position < 1)
            System.out.print("Invalid position");

        // if position is 1 then new node is
        // set infornt of head node
        // head node is changing.
        if (position == 1) {
            Node newNode = new Node(data);
            newNode.nextNode = headNode;
            head = newNode;
        } else {
            while (position-- != 0) {
                if (position == 1) {
                    // adding Node at required position
                    Node newNode = GetNode(data);

                    // Making the new Node to point to
                    // the old Node at the same position
                    newNode.nextNode = headNode.nextNode;

                    // Replacing current with new Node
                    // to the old Node to point to the new Node
                    headNode.nextNode = newNode;
                    break;
                }
                headNode = headNode.nextNode;
            }
            if (position != 1)
                System.out.print("Position out of range");
        }
        return head;
    }

    static void PrintList(Node node) {
        while (node != null) {
            System.out.print(node.data);
            node = node.nextNode;
            if (node != null)
                System.out.print(",");
        }
        System.out.println();
    }

    // Driver code
    public static void main(String[] args) {
        Node head = GetNode(3);
        head.nextNode = GetNode(5);
        head.nextNode.nextNode = GetNode(8);
        head.nextNode.nextNode.nextNode = GetNode(10);

        System.out.print("Linked list before insertion: ");
        PrintList(head);

        int data = 12, pos = 3;
        head = InsertPos(head, pos, data);
        System.out.print("Linked list after" + " insertion of 12 at position 3: ");
        PrintList(head);

        // front of the linked list
        data = 1;
        pos = 1;
        head = InsertPos(head, pos, data);
        System.out.print("Linked list after" + "insertion of 1 at position 1: ");
        PrintList(head);

        // insertion at end of the linked list
        data = 15;
        pos = 7;
        head = InsertPos(head, pos, data);
        System.out.print("Linked list after" + " insertion of 15 at position 7: ");
        PrintList(head);
    }
}
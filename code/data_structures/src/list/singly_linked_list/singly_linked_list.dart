/* Part of Cosmos by OpenGenus Foundation */

import 'dart:math';

class OutOfRange implements Exception {
  OutOfRange([this.message]) : super();
  final message;

  @override
  String toString() {
    if (message == null) {
      return 'OutOfRange';
    }
    return 'OutOfRange $message';
  }
}

class Node {
  Node({this.data = null});
  int? data;
  Node? next;
}

class LinkedList {
  LinkedList({required this.head});
  Node head;

  int get length {
    int len = 0;
    Node? curr_node = this.head;
    while (curr_node?.next != null) {
      curr_node = curr_node?.next;
      len++;
    }
    return len;
  }

  void append(int data) {
    Node? curr_node = this.head;
    while (curr_node?.next != null) {
      curr_node = curr_node!.next;
    }
    curr_node?.next = Node(data: data);
  }

  int? elementAt(int index) {
    if (index >= length) {
      throw OutOfRange(
          "The index passed: $index must be less than length: $length");
    }
    Node? curr_node = this.head;
    int curr_index = 0;
    while (true) {
      if (index == curr_index) {
        curr_node = curr_node!.next;
        return curr_node!.data;
      }
      curr_index++;
    }
  }

  void display() {
    Node? curr_node = this.head;
    List<int?> result = [];
    while (curr_node?.next != null) {
      curr_node = curr_node!.next;
      result.add(curr_node!.data);
    }
    print(result);
  }

  List? toList() {
    Node? curr_node = this.head;
    List<int?> result = [];
    while (curr_node?.next != null) {
      curr_node = curr_node!.next;
      result.add(curr_node!.data);
    }
    return result;
  }

  void delete(int index) {
    if (index >= length) {
      throw OutOfRange(
          "The index passed: $index must be less than length: $length");
    }
    Node? curr_node = this.head;
    Node? previous_node;
    int curr_index = 0;
    while (true) {
      previous_node = curr_node;
      curr_node = curr_node!.next;
      if (index == curr_index) {
        previous_node!.next = curr_node!.next;
        return;
      }
      curr_index++;
    }
  }
}

LinkedList randIntLinkedList({required int length, int maxRange = 10}) {
  int i = 0;
  LinkedList ll = LinkedList(head: Node());
  Random rand = Random();
  while (i < length) {
    ll.append(rand.nextInt(maxRange));
    i++;
  }
  return ll;
}

int main() {
  LinkedList linkedList = randIntLinkedList(length: 10, maxRange: 25);
  int randIndex = Random().nextInt(9);
  print('Index : $randIndex | value: ${linkedList.elementAt(randIndex)}');
  print("Linked List length: ${linkedList.length}");
  linkedList.display();
  linkedList.delete(randIndex);
  print("Linked List length after delete: ${linkedList.length}");
  print('Linked List to Array: ${linkedList.toList()}');
  return 0;
}

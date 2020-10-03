/*
 * Part of Cosmos by OpenGenus Foundation
 *
 */

function Queue() {
  store = [];

  this.show = () => {
    console.log(store);
  };

  this.enqueue = element => {
    store.push(element);
  };

  this.dequeue = () => {
    return store.shift();
  };

  this.front = () => {
    return store[0];
  };

  this.rear = () => {
    return store[store.length - 1];
  };

  this.size = () => {
    return store.length;
  };

  this.isEmpty = () => {
    return store.length === 0;
  };
}

let q = new Queue();
q.enqueue("a");
q.enqueue("b");
q.enqueue("c");
q.enqueue("d");
q.show();
console.log("Front Element: ", q.front());
console.log("Rear Element: ", q.rear());
q.dequeue();
console.log("After Dequeue: ");
q.show();

/**
 * Part of Cosmos by OpenGenus Foundation
 */

function Queue() {
  this.queue = [];
  this.stack = [];
  this.frontEl = null;
  this.total = 0;

  this.enqueue = function (el) {
    if (this.total == 0) {
      this.frontEl = el;
    }

    this.queue.push(el);
    this.total++;
  };

  this.dequeue = function () {
    // Confirm if stack is empty and return
    if (this.total == 0) {
      console.log("The queue is empty!");

      return;
    }

    // Move all queue entries to stack if stack is empty
    if (this.stack.length == 0) {
      while (this.queue.length > 0) {
        this.stack.push(this.queue.pop());
      }
    }

    this.total--;
    // Return the topmost element
    return this.stack.pop();
  };

  this.size = function () {
    return this.total;
  };

  this.front = function () {
    if (this.stack.length > 0) {
      return this.stack[this.stack.length - 1];
    }

    return this.frontEl;
  };

  this.reverse = function () {
    if (this.total == 0) {
      console.log("The queue is empty");

      return;
    }

    this.stack.reverse();
    this.queue.reverse();
    while (this.queue.length > 0) {
      this.stack.push(this.queue.pop());
    }

    this.frontEl = this.stack[this.stack.length - 1];
  };

  this.print = function () {
    if (this.total == 0) {
      console.log(this.queue);
      return;
    }

    let output = [];
    for (let i = this.stack.length - 1; i >= 0; --i) {
      output.push(this.stack[i]);
    }
    for (let q of this.queue) {
      output.push(q);
    }

    console.log(output);
  };
}

const queue = new Queue();
const items = [1, 2, 3, 4];
for (let i of items) {
  queue.enqueue(i);
}
console.log("\nCurrent queue");
console.log("===============");
queue.print();

console.log("\nCurrent queue front");
console.log("===============");
console.log(queue.front());

const el = queue.dequeue();
console.log("\nRemoved element:");
console.log("===============");
console.log(el);

console.log("\nCurrent queue");
console.log("===============");
queue.print();

queue.enqueue(5);
queue.enqueue(6);
console.log("\nUpdated queue");
console.log("===============");
queue.print();

console.log("\nReversed queue");
console.log("===============");
queue.reverse();
queue.print();

console.log("\nReversed queue front");
console.log("===============");
console.log(queue.front());

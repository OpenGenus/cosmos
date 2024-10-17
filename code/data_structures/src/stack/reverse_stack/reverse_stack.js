/**
 * Part of Cosmos by OpenGenus Foundation
 */

function Stack() {
  this.stack = [];

  this.pop = function () {
    this.stack.pop();
  };

  this.push = function (el) {
    this.stack.push(el);
  };

  this.peek = function () {
    return this.stack[this.stack.length - 1];
  };

  this.isEmpty = function () {
    return this.stack.length == 0;
  };

  this.reverse = function () {
    if (this.isEmpty()) {
      console.log("The stack is empty");
      
      return;
    }

    this.stack.reverse();
  };

  this.print = function () {
    console.log(this.stack);
  };
}

const stack = new Stack();
const items = [1, 2, 3, 4];
for (let i of items) {
  stack.push(i);
}

console.log("\nCurrent Stack");
console.log("===============");
stack.print();
console.log("\nReversed Stack");
console.log("===============");
stack.reverse();
stack.print();

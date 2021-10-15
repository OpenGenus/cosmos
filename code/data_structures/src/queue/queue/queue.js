/*
 * Part of Cosmos by OpenGenus Foundation
 *
 */

function Queue(size_max) {
  data = new Array(size_max + 1);
  max = (size_max + 1);
  start = 0;
  end = 0;

  this.empty = () => {
    return start == end;
  }

  this.full = () => {
    return start == (end + 1) % max;
  }

  this.enqueue = (x) => {
    if (this.full()) {
      console.log("Queue full");
      return false;
    }
    data[end] = x;
    end = (end + 1) % max;
    return true;
  }

  this.dequeue = () => {
    if (this.empty()) {
      console.log("Queue empty");
      return;
    }
    x =  data[start];
    start = (start + 1) % max;
    return x;
  }

  this.top = () => {
    if (this.empty()) {
      console.log("Queue empty");
      return;
    }
    return data[start];
  }

  this.display = () => {
    cur =  start
    while (cur !=  end) {
      console.log(data[cur])
      cur = (cur + 1) % max
    }
  }
}

let q = new Queue(3);
q.enqueue("a");
q.enqueue("b");
q.enqueue("c");
q.enqueue("d"); // Queue full
q.display(); // a, b, c
q.dequeue();
q.display(); // b, c
q.dequeue();
q.dequeue();
q.dequeue(); // Queue empty
q.enqueue("z");
q.display() // z
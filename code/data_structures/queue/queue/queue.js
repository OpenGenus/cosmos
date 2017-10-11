function Queue (arr = []) {
    this.arr = arr;
}

Queue.prototype.dequeue = function()  {
    this.arr.shift();
};

Queue.prototype.enqueue = function(element)  {
    this.arr.push(element)
};

Queue.prototype.front = function()  {
     this.arr[0];
};

Queue.prototype.size = function() {
    return this.arr.length;
};

var queue = new Queue([5]);
console.log(queue.arr);

queue.enqueue(3);
console.log("Enqueue ", queue.arr);
queue.dequeue();
console.log("Dequeue", queue.arr);
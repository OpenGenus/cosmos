/* Part of Cosmos by OpenGenus Foundation */

Array.prototype.swap = function(x, y) {
  let b = this[x];
  this[x] = this[y];
  this[y] = b;

  return this;
};

/**
 * PriorityQueue constructor
 * @param data Initial data
 * @param compareFn compare function
 * @constructor
 */
function PriorityQueue(data, compareFn) {
  this.data = data || [];
  this.compareFn = compareFn || defaultCompareFn;

  this.push = push;
  this.pop = pop;
  this.top = top;
  this.init = init;
  this.empty = empty;
  this._up = up;
  this._down = down;

  this.init();
}

/**
 * Initialises the priority queue
 */
function init() {
  if (this.data.length > 1) {
    let n = this.data.length;
    for (let i = Math.floor(n / 2 - 1); i >= 0; i -= 1) {
      this._down(i, n);
    }
  }
}

/**
 * Get the topmost item of the priority queue
 * @returns {*|Object}
 */
function top() {
  return this.data[0];
}

/**
 * Is the queue empty?
 * @returns {boolean}
 */
function empty() {
  return this.data.length === 0;
}

/**
 * Pushes the item onto the heap
 */
function push(item) {
  this.data.push(item);
  this._up(this.data.length - 1);
}

/**
 * Pop removes the minimum element (according to Less) from the heap
 * and returns it.
 *
 * @returns {string|number|Object}
 */
function pop() {
  if (this.data.length === 0) {
    return undefined;
  }

  let n = this.data.length - 1;
  this.data.swap(0, n);
  this._down(0, n);

  return this.data.pop();
}

/**
 * Default comparator function is for max heap
 * @param p First item to compare
 * @param q Second item to compare
 *
 * @returns {number} -1 if p < q, 1 if p > q or 0 if p == q
 */
function defaultCompareFn(p, q) {
  const diff = p - q;

  return diff < 0 ? -1 : diff > 0 ? 1 : 0;
}

/**
 * Percolate up from index
 * @param index
 */
function up(index) {
  while (index > 0) {
    let parentIndex = parent(index);
    let parentItem = this.data[parentIndex];
    let currentItem = this.data[index];

    if (parentIndex === index || !this.compareFn(currentItem, parentItem) < 0) {
      break;
    }
    this.data.swap(parentIndex, index);
    index = parentIndex;
  }
}

/**
 * Percolate down from index until n
 * @param index
 * @param n
 *
 * * @returns {boolean} True if a change happened. False otherwise.
 */
function down(index, n) {
  let i = index;
  while (true) {
    let currentItem = this.data[i];
    let j1 = leftChild(i);
    if (j1 + 1 >= n || j1 < 0) {
      // overflows
      break;
    }
    let j = j1; // left child
    let j2 = j1 + 1; // right child
    if (j2 < n && this.compareFn(this.data[j2], this.data[j1]) < 0) {
      j = j2;
    }
    if (this.compareFn(this.data[j], currentItem) >= 0) {
      break;
    }
    this.data.swap(i, j);
    i = j;
  }

  return i > index;
}

/**
 * Return parent index
 * @param index current inter
 * @returns {number} parent index
 */
function parent(index) {
  return Math.floor((index - 1) / 2);
}

/**
 * Return left child index
 * @param index current inter
 * @returns {number} left child index
 */
function leftChild(index) {
  return index * 2 + 1;
}

function main() {
  const pq = new PriorityQueue([45, 6, 4, 3, 2, 72, 34, 12, 456, 29, 312]);
  pq.push(1);
  console.log(pq);
}

main();

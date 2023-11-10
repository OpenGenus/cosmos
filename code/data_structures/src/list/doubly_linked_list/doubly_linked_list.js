/** Source: https://github.com/brunocalou/graph-theory-js/blob/master/src/data_structures/linked_list.js */

/**@module dataStructures */

"use strict";

/**
 * Node class
 * @constructor
 * @public
 * @param {any} value - The value to be stored
 */
function Node(value) {
  this.value = value;
  this.next = null;
  this.prev = null;
}

/**
 * Linked list class
 * @constructor
 */
function LinkedList() {
  /**@private
   * @type {node}
   */
  this._front = null;

  /**@private
   * @type {node}
   */
  this._back = null;

  /**@private
   * @type{number}
   */
  this._length = 0;

  Object.defineProperty(this, "length", {
    get: function() {
      return this._length;
    }
  });
}

/**
 * Inserts the element at the specified position in the list. If the index is not specified, will append
 * it to the end of the list
 * @param {any} element - The element to be added
 * @param {number} index - The index where the element must be inserted
 */
LinkedList.prototype.add = function(element, index) {
  if (index > this._length || index < 0) {
    throw new Error("Index out of bounds");
  } else {
    if (index === undefined) {
      //Add the element to the end
      index = this._length;
    }

    var node = new Node(element);

    if (index === 0) {
      //Add the element to the front
      if (this._length !== 0) {
        node.next = this._front;
        this._front.prev = node;
      } else {
        //Add the element to the back if the list is empty
        this._back = node;
      }
      this._front = node;
    } else if (index === this._length) {
      //Add the element to the back
      if (this._length !== 0) {
        node.prev = this._back;
        this._back.next = node;
      }
      this._back = node;
    } else {
      //Add the element on the specified index
      var current_node = this._front;
      var i;

      //Check if the index is closer to the front or to the back and performs the
      //insertion accordingly
      if (index < this._length / 2) {
        for (i = 0; i < this._length; i += 1) {
          if (i === index) {
            break;
          }
          //Get the next node
          current_node = current_node.next;
        }
      } else {
        current_node = this._back;

        for (i = this._length - 1; i > 0; i -= 1) {
          if (i === index) {
            break;
          }
          //Get the previous node
          current_node = current_node.prev;
        }
      }

      node.prev = current_node.prev;
      node.next = current_node;

      current_node.prev.next = node;

      current_node.prev = node;
    }

    this._length += 1;
  }
};

/**
 * Inserts the element at the begining of the list
 * @param {any} element - The element to be added
 */
LinkedList.prototype.addFirst = function(element) {
  this.add(element, 0);
};

/**
 * Inserts the element at the end of the list
 * @param {any} element - The element to be added
 */
LinkedList.prototype.addLast = function(element) {
  this.add(element);
};

/**
 * Removes all the elements of the list
 */
LinkedList.prototype.clear = function() {
  while (this._length) {
    this.pop();
  }
};

/**
 * Returns if the list contains the element
 * @param {any} element - The element to be checked
 * @returns {boolean} True if the list contains the element
 */
LinkedList.prototype.contains = function(element) {
  var found_element = false;

  this.every(function(elem, index) {
    if (elem === element) {
      found_element = true;
      return false;
    }
    return true;
  });

  return found_element;
};

/**
 * The function called by the forEach method.
 * @callback LinkedList~iterateCallback
 * @function
 * @param {any} element - The current element
 * @param {number} [index] - The index of the current element
 * @param {LinkedList} [list] - The linked list it is using
 */

/**
 * Performs the fn function for all the elements of the list, untill the callback function returns false
 * @param {iterateCallback} fn - The function the be executed on each element
 * @param {object} [this_arg] - The object to use as this when calling the fn function
 */
LinkedList.prototype.every = function(fn, this_arg) {
  var current_node = this._front;
  var index = 0;

  while (current_node) {
    if (!fn.call(this_arg, current_node.value, index, this)) {
      break;
    }
    current_node = current_node.next;
    index += 1;
  }
};

/**
 * Performs the fn function for all the elements of the list
 * @param {iterateCallback} fn - The function the be executed on each element
 * @param {object} [this_arg] - The object to use as this when calling the fn function
 */
LinkedList.prototype.forEach = function(fn, this_arg) {
  var current_node = this._front;
  var index = 0;

  while (current_node) {
    fn.call(this_arg, current_node.value, index, this);
    current_node = current_node.next;
    index += 1;
  }
};

/**
 * Returns the element at the index, if any
 * @param {number} index - The index of the element to be returned
 * @returns {any} The element at the specified index, if any. Returns undefined otherwise
 */
LinkedList.prototype.get = function(index) {
  if (index < 0 || index >= this._length) {
    return undefined;
  }

  var node = this._front;

  for (var i = 0; i < this._length; i += 1) {
    if (i === index) {
      return node.value;
    }

    node = node.next;
  }
};

/**
 * Returns the first element in the list
 * @returns {any} The first element in the list
 */
LinkedList.prototype.getFirst = function() {
  return this.get(0);
};

/**
 * Returns the last element in the list
 * @returns {any} The last element in the list
 */
LinkedList.prototype.getLast = function() {
  if (this._back != null) {
    return this._back.value;
  }
};

/**
 * Returns the index of the element in the list
 * @param {any} element - The element to search
 * @returns {number} The index of the element in the list, or -1 if not found
 */
LinkedList.prototype.indexOf = function(element) {
  var node = this._front;

  for (var i = 0; i < this._length; i += 1) {
    if (node.value === element) {
      return i;
    }

    node = node.next;
  }

  return -1;
};

/**
 * Returns if the list is empty
 * @returns {boolean} If the list if empty
 */
LinkedList.prototype.isEmpty = function() {
  return this._length === 0;
};

/**
 * Returns the last index of the element in the list
 * @param {any} element - The element to search
 * @returns {number} The last index of the element in the list, -1 if not found
 */
LinkedList.prototype.lastIndexOf = function(element) {
  var current_node = this._back;
  var index = this._length - 1;

  while (current_node) {
    if (current_node.value === element) {
      break;
    }
    current_node = current_node.prev;
    index -= 1;
  }

  return index;
};

/**
 * Retrieves the first element without removing it.
 * This method is equivalent to getFirst
 * @see getFirst
 * @returns {any} The first element
 */
LinkedList.prototype.peek = function() {
  return this.get(0);
};

/**
 * Removes and returns the first element of the list.
 * This method is equivalent to removeFirst
 * @see removeFirst
 * @returns {any} The removed element
 */
LinkedList.prototype.pop = function() {
  return this.removeFirst();
};

/**
 * Inserts the element to the end of the list
 * This method is equivalent to addFirst
 * @see addFirst
 */
LinkedList.prototype.push = function(element) {
  this.addFirst(element);
};

/**
 * Removes and retrieves the element at the specified index.
 * If not specified, it will remove the first element of the list
 * @param {number} index - The index of the element to be removed
 * @returns {any} The removed element
 */
LinkedList.prototype.remove = function(index) {
  if (index > this._length - 1 || index < 0 || this._length === 0) {
    throw new Error("Index out of bounds");
  } else {
    var removed_node;

    if (index === 0) {
      //Remove the first element
      removed_node = this._front;
      this.removeNode(this._front);
    } else if (index === this._length - 1) {
      //Remove the last element
      removed_node = this._back;
      this.removeNode(this._back);
    } else {
      //Remove the element at the specified index
      var node = this._front;
      var i;

      if (index < this._length / 2) {
        for (i = 0; i < this._length; i += 1) {
          if (i === index) {
            removed_node = node;
            this.removeNode(removed_node);
            break;
          }
          node = node.next;
        }
      } else {
        node = this._back;

        for (i = this._length - 1; i > 0; i -= 1) {
          if (i === index) {
            removed_node = node;
            this.removeNode(removed_node);
            break;
          }
          node = node.prev;
        }
      }
    }
    this._length -= 1;
    return removed_node.value;
  }
};

/**
 * Removes and retrieves the first element of the list
 * @returns {any} The removed element
 */
LinkedList.prototype.removeFirst = function() {
  if (this._length > 0) {
    return this.remove(0);
  }
};

/**
 * Removes and retrieves the first occurrence of the element in the list
 * @returns {any} The removed element
 */
LinkedList.prototype.removeFirstOccurrence = function(element) {
  var node = this._front;
  var index = 0;

  while (node) {
    if (node.value === element) {
      this.removeNode(node);
      return node.value;
    }

    node = node.next;
    index += 1;
  }
};

/**
 * Removes and retrieves the last element of the list
 * @returns {any} The removed element
 */
LinkedList.prototype.removeLast = function() {
  if (this._length > 0) {
    return this.remove(this._length - 1);
  }
};

/**
 * Removes and retrieves the last occurrence of the element in the list
 * @returns {any} The removed element
 */
LinkedList.prototype.removeLastOccurrence = function(element) {
  var node = this._back;
  var index = this._length - 1;

  while (node) {
    if (node.value === element) {
      this.removeNode(node);
      return node.value;
    }

    node = node.prev;
    index -= 1;
  }
};

/**
 * Removes the node from the list
 * @returns {any} The removed node
 */
LinkedList.prototype.removeNode = function(node) {
  if (node === this._front) {
    if (this._length > 1) {
      this._front.next.prev = null;
      this._front = this._front.next;
    } else {
      this._front = null;
      this._back = null;
    }
    node.next = null;
  } else if (node === this._back) {
    this._back.prev.next = null;
    this._back = this._back.prev;
    node.prev = null;
  } else {
    var prev_node = node.prev;
    var next_node = node.next;

    prev_node.next = next_node;
    next_node.prev = prev_node;
    node.next = null;
    node.prev = null;
  }
};

/**
 * Replaces the element at the specified position in the list.
 * @param {any} element - The new element
 * @param {number} index - The index where the element must be replaced
 * @returns {any} The element previously at the specified position
 */
LinkedList.prototype.set = function(element, index) {
  if (index > this._length - 1 || index < 0 || this._length === 0) {
    throw new Error("Index out of bounds");
  } else {
    var node = this._front;
    var old_element;

    for (var i = 0; i < this._length; i += 1) {
      if (i === index) {
        old_element = node.value;
        node.value = element;
        return old_element;
      }
      node = node.next;
    }
  }
};

/**
 * Returns the size of the list
 * @returns {number} The size of the list
 */
LinkedList.prototype.size = function() {
  return this._length;
};

/**
 * Converts the list to an array
 * @returns {array} The converted list in an array format
 */
LinkedList.prototype.toArray = function() {
  var array = new Array(this._length);

  this.forEach(function(element, index) {
    array[index] = element;
  });

  return array;
};

module.exports = LinkedList;

// Breadth First Search Tree with Queue

'strict mode';

var Tree = function(value) {
  this.value = value;
  this.children = [];
};

var Queue = function() {
  var storage = [];

  this.push = function(item) {
    storage.push(item);
  };

  this.pop = function() {
    return storage.shift();
  };
};

Tree.prototype.BFSelect = function(filter) {

  var queue = new Queue();
  var results = [];
  var item;
  queue.push({tree: this, depth: 0});

  while (item = queue.pop()) {
    var tree = item.tree;
    var depth = item.depth;
    if (filter(tree.value, depth)) {
      results.push(tree.value);
    }
    for (var i = 0; i < tree.children.length; i++) {
      var child = tree.children[i];
      queue.push({tree: child, depth: depth + 1});
    }
  }

  return results;
}

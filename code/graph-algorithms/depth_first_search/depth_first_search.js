// Depth First Search Tree

'strict mode';

var Tree = function(value) {
  this.value = value;
  this.children = [];
};

Tree.prototype.DFSelect = function(filter) {

  var results = [];
  var subroutine = function(node, depth) {
    if(filter(node.value, depth)) {
      array.push(node.value);
    }
    for (var i = 0; i < node.children.length; i++) {
      var child = node.children[i];
      subroutine(child, depth + 1);
    }
  };
  subroutine(this, 0);
  return array;
}

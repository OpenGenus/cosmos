/*
 * Part of Cosmos by OpenGenus Foundation
 */
function HashTable(obj) {
  this.length = 0;
  this.items  = {};
  
  for (var p in obj) {
    if (obj.hasOwnProperty(p)) {
      this.items[p] = obj[p];
      this.length++;
    }
  }
  
  this.get = function(key) {
    return this.has(key) ? this.items[key] : undefined;
  };
  
  this.set = function(key, value) {
    var previous;
    
    if (!this.has(key)) {
      this.length++;
    } else {
      previous = this.items[key];
    }
    
    this.items[key] = value;
    return previous;
  };
  
  this.has = function(key) {
    return this.items.hasOwnProperty(key);
  };
  
  this.remove = function(key) {
    var previous;
    
    if (this.has(key)) {
      previous = this.items[key];
      this.length--;
      delete this.items[key];
    }
    
    return previous;
  };
  
  this.keys = function() {
    return Object.keys(this.items);
  };
  
  this.values = function() {
    return Object.values(this.items);
  };
  
  this.each = function(fn) {
    for (var k in this.items) {
      if (this.has(k)) {
        fn(k, this.items[k]);
      }
    }
  };
  
  this.clear = function() {
    this.items = {}
    this.length = 0;
  };
}


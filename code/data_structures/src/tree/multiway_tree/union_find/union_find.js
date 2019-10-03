/* Part of Cosmos by OpenGenus Foundation */

class UnionFind {
  constructor() {
    this.parents = [];
    this.ranks = [];
  }

  find(v) {
    if (this.parents[v] === v) {
      return v;
    }
    this.parents[v] = this.find(this.parents[v]);
    return this.parents[v];
  }

  union(a, b) {
    if (this.parents[a] === undefined) {
      this.parents[a] = a;
      this.ranks[a] = 0;
    }

    if (this.parents[b] === undefined) {
      this.parents[b] = b;
      this.ranks[b] = 0;
    }

    a = this.find(a);
    b = this.find(b);

    if (a !== b) {
      if (this.ranks[a] < this.ranks[b]) {
        [a, b] = [b, a];
      }

      if (this.ranks[a] === this.ranks[b]) {
        this.ranks[a]++;
      }

      this.parents[b] = a;
    }
  }

  connected(a, b) {
    return this.find(a) === this.find(b);
  }
}

const uf = new UnionFind();
uf.union(1, 3);
uf.union(1, 4);
uf.union(4, 2);
uf.union(5, 6);
console.log(uf.find(3));
console.log(uf.find(4));
console.log(uf.find(2));
console.log(uf.find(5));

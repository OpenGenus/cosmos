function Bag() {
  let bag = [];
  this.size = () => bag.length;

  this.add = item => bag.push(item);

  this.isEmpty = () => bag.length === 0;
}

let bag1 = new Bag();
console.log(bag1.size()); // 0

bag1.add("Blue ball");
console.log(bag1.size()); // 1

bag1.add("Red ball");
console.log(bag1.size()); // 2

/* Part of Cosmos by OpenGenus Foundation */

let singletonInstance = null;

class Singleton {
  constructor() {
    if(!singletonInstance) {
      singletonInstance = this;
    }
    return singletonInstance;
  }
}
 
// tests that the Singleton class above works as intended
(function () {
  let instance = new Singleton();
  console.log(instance === new Singleton()); // true
})();

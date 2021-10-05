/* Part of Cosmos by OpenGenus Foundation */

class Singleton {
    constructor() {
        console.log('New Singleton');
    }

    static getInstance() {
        if (!Singleton.instance) {
            Singleton.instance = new Singleton();
        }

        return Singleton.instance;
    }

    foo() {
        console.log('bar');
    }
}

(function () {
    const firstInstance = Singleton.getInstance(); // New Singleton
    const secondInstance = Singleton.getInstance(); // void

    firstInstance.foo(); // bar
    secondInstance.foo(); // bar
})();

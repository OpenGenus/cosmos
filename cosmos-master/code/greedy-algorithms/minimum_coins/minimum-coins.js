/* Part of Cosmos by OpenGenus Foundation */

function minimumCoins(value, denominations) {
    var result = [];
    // Assuming denominations is sorted in descendig order
    for(var i = 0; i < denominations.length; i++) {
        var cur_denom = denominations[i];
        while(cur_denom <= value) {
            result.push(cur_denom);
            value -= cur_denom;
        }
    }
    return result;
}

Array.prototype.equals = function(other) {
    if (!other || !(other instanceof Array)) {
        return false;
    }

    if (this.length != other.length) {
        return false;
    }

    for (var i = 0; i < this.length; i++) {
        if (this[i] != other[i]) {
            return false;
        }
    }

    return true;
}

function test() {
    scenarios = [
        {value: 100, denoms: [50, 25, 10, 5, 1],      result: [50, 50]},
        {value: 101, denoms: [50, 25, 10, 5, 1],      result: [50, 50, 1]},
        {value: 77,  denoms: [50, 25, 10, 5, 1],      result: [50, 25, 1, 1]},
        {value: 38,  denoms: [50, 25, 10, 5, 1],      result: [25, 10, 1, 1, 1]},
        {value: 17,  denoms: [50, 25, 10, 5, 1],      result: [10, 5, 1, 1]},
        {value: 3,   denoms: [50, 25, 10, 5, 1],      result: [1, 1, 1]},
        {value: 191, denoms: [100, 50, 25, 10, 5, 1], result: [100, 50, 25, 10, 5, 1]}
    ];

    scenarios.forEach(function(scenario) {
        var actual = minimumCoins(scenario.value, scenario.denoms);
        if (!scenario.result.equals(actual)) {
            console.error("Test Failed: Value: " + scenario.value
                        + ", Denominations: " + scenario.denoms
                        + ", Expected Result: " + scenario.result
                        + ", Actual Result: " + actual);
        }
    }, this);
}

test();


const constants = {
    directions: {
        'clockwise': 'CLOCKWISE',
        'counterClockwise': 'COUNTER_CLOCKWISE'
    }
}

const newVector = (a, b) => ({
    x: b.x - a.x,
    y: b.y - a.y
});

const crossProduct = (u, v) => u.x * v.y - u.y * v.x;

const length = v => v.x * v.x + v.y * v.y;

const parallelogramArea = (a, b, c) => crossProduct(newVector(a, b), newVector(a, c));

const pointRotation = (a, b, c) => (parallelogramArea(a, b, c) < 0) 
    ? constants.directions.clockwise 
    : constants.directions.counterClockwise;

const preprocess = p => {
    let pivot = p[0];

    for (let i = 1; i < p.length; i++) {
        if (pivot.y > p[i].y || (pivot.y === p[i].y && pivot.x > p[i].x)) {
            pivot = p[i];
        }
    }

    p.sort((a, b) => {
        const area = parallelogramArea(pivot, a, b);
        if (Math.abs(area) < 1e-6) {
            return (
                length(newVector(pivot, a)) -
                length(newVector(pivot, b))
            );
        }
        return -area;
    });
};

const grahamScan = p => {
    if (p.length <= 3) {
        return p;
    }
    
    preprocess(p);
    
    const convexHull = [p[0], p[1]];
    
    for (let i = 2; i < p.length; i++) {
        let j = convexHull.length;
        while (
            j >= 2 &&
            pointRotation(convexHull[j - 2], convexHull[j - 1], p[i]) === constants.directions.clockwise
        ) {
            convexHull.pop();
            j--;
        }
        convexHull.push(p[i]);
    }
    
    return convexHull;
};

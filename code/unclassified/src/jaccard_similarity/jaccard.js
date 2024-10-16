/**
 * Calculates union of two given sets
 * @param {Set} setA
 * @param {Set} setB
 */
const union = (setA, setB) => {
  const _union = new Set(setA);
  for (let elem of setB) {
    _union.add(elem);
  }
  return _union;
};

/**
 * Calculates intersection of two given sets
 * @param {Set} setA
 * @param {Set} setB
 */
const intersection = (setA, setB) => {
  const _intersection = new Set();
  for (let elem of setB) {
    if (setA.has(elem)) {
      _intersection.add(elem);
    }
  }
  return _intersection;
};

/**
 *
 * @param {Array} first
 * @param {Array} second
 */
const jaccardSimilarity = (first, second) => {
  intersection_cardinality = intersection(new Set(first), new Set(second)).size;
  union_cardinality = union(new Set(first), new Set(second)).size;
  return intersection_cardinality / union_cardinality;
};

console.log(jaccardSimilarity([0, 1, 2, 5, 6], [0, 2, 3, 5, 7, 9]));

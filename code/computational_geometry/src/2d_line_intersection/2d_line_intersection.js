// computational geometry | 2D line intersecton | JavaScript
function intersection_by_points(x1, y1, x2, y2, x3, y3, x4, y4) {
  var x12 = x1 - x2;
  var x34 = x3 - x4;
  var y12 = y1 - y2;
  var y34 = y3 - y4;

  var c = x12 * y34 - y12 * x34;

  var a = x1 * y2 - y1 * x2;
  var b = x3 * y4 - y3 * x4;

  var x = (a * x34 - b * x12) / c;
  var y = (a * y34 - b * y12) / c;

  // Keeping points integers. Change according to requirement
  x = parseInt(x);
  y = parseInt(y);

  return { x: x, y: y };
}

// Line segments defined by 2 points a-b and c-d
function intersection_by_vectors(vec1, vec2, vec3, vec4) {
  return intersection_by_points(
    vec1["x"],
    vec1["y"],
    vec2["x"],
    vec2["y"],
    vec3["x"],
    vec3["y"],
    vec4["x"],
    vec4["y"]
  );
}

// Accepts line in Ax+By = C format
function intersection_by_line_euqation(line1, line2) {
  var A1 = line1["A"];
  var B1 = line1["B"];
  var C1 = line1["C"];
  var A2 = line2["A"];
  var B2 = line2["B"];
  var C2 = line2["C"];

  var delta = A1 * B2 - A2 * B1;
  if (delta === 0) console.log("Lines are parallel");

  var x = (B2 * C1 - B1 * C2) / delta;
  var y = (A1 * C2 - A2 * C1) / delta;

  // Keeping points integers. Change according to requirement
  x = parseInt(x);
  y = parseInt(y);

  return { x: x, y: y };
}

// Driver Program
function main() {
  // 3x + 4y = 1
  var line1 = { A: 3, B: 4, C: 1 };
  // 2x + 5y = 3
  var line2 = { A: 2, B: 5, C: 3 };

  var intersection_point = intersection_by_line_euqation(line1, line2);

  console.log("Test using line equation");
  console.log(
    `Lines intersect at x:${intersection_point["x"]}, y:${
      intersection_point["y"]
    }`
  );
  console.log("Test using points");

  intersection_point = intersection_by_vectors(
    { x: 2, y: 5 },
    { x: 5, y: 3 },
    { x: 7, y: 4 },
    { x: 1, y: 6 }
  );
  console.log(
    `Lines intersect at x:${intersection_point["x"]}, y:${
      intersection_point["y"]
    }`
  );
}

main();

function distanceBetweenPoints (x1, x2, y1, y2) {
  return Math.sqrt(Math.pow((x2-x1),2) + Math.pow((y2-y1),2))
}

console.log(distanceBetweenPoints(0,3,0,4))

import Foundation

class KMeans<Label: Hashable> {
  let numCenters: Int
  let labels: [Label]
  private(set) var centroids = [Vector]()

  init(labels: [Label]) {
    assert(labels.count > 1, "Exception: KMeans with less than 2 centers.")
    self.labels = labels
    self.numCenters = labels.count
  }

  private func indexOfNearestCenter(_ x: Vector, centers: [Vector]) -> Int {
    var nearestDist = DBL_MAX
    var minIndex = 0

    for (idx, center) in centers.enumerated() {
      let dist = x.distanceTo(center)
      if dist < nearestDist {
        minIndex = idx
        nearestDist = dist
      }
    }
    return minIndex
  }

  func trainCenters(_ points: [Vector], convergeDistance: Double) {
    let zeroVector = Vector([Double](repeating: 0, count: points[0].length))

    var centers = reservoirSample(points, k: numCenters)

    var centerMoveDist = 0.0
    repeat {
      var classification: [[Vector]] = .init(repeating: [], count: numCenters)

      for p in points {
        let classIndex = indexOfNearestCenter(p, centers: centers)
        classification[classIndex].append(p)
      }

let newCenters = classification.map { assignedPoints in
        assignedPoints.reduce(zeroVector, +) / Double(assignedPoints.count)
      }

      centerMoveDist = 0.0
      for idx in 0..<numCenters {
        centerMoveDist += centers[idx].distanceTo(newCenters[idx])
      }

      centers = newCenters
    } while centerMoveDist > convergeDistance

    centroids = centers
  }

  func fit(_ point: Vector) -> Label {
    assert(!centroids.isEmpty, "Exception: KMeans tried to fit on a non trained model.")

    let centroidIndex = indexOfNearestCenter(point, centers: centroids)
    return labels[centroidIndex]
  }

  func fit(_ points: [Vector]) -> [Label] {
    assert(!centroids.isEmpty, "Exception: KMeans tried to fit on a non trained model.")

    return points.map(fit)
  }
}

func reservoirSample<T>(_ samples: [T], k: Int) -> [T] {
  var result = [T]()

  for i in 0..<k {
    result.append(samples[i])
  }

  for i in k..<samples.count {
    let j = Int(arc4random_uniform(UInt32(i + 1)))
    if j < k {
      result[j] = samples[i]
    }
  }
  return result
}

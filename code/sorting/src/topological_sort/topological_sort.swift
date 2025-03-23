var inDegree: [Int] = []

func topologicalSort(adjList: [[Int]]) -> [Int] {
    var result: [Int] = []
    let numVertices = adjList.count - 1
    var queue = [Int]()
    for i in 1 ... numVertices {
        if inDegree[i] == 0 {
            queue.append(i)
        }
    }

    while !queue.isEmpty {
        let currVertex = queue.first!
        queue.removeFirst()

        result.append(currVertex)

        for i in 0 ..< adjList[currVertex].count {
            let neighbour = adjList[currVertex][i]
            inDegree[neighbour] -= 1;

            if inDegree[neighbour] == 0 {
                queue.append(neighbour)
            }
        }
    }

    return result
}

    /* Consider following graph
     * 1----->2----->5
     * |     ^^
     * |    / |
     * |   /  |
     * |  /   |
     * v /    |
     * 4----->3
     * One of the solution would be
     * 1 -> 4 -> 3 -> 2 -> 5
     */

let numVertices = 5
inDegree = Array(repeating: 0, count: numVertices + 1)
var adjList: [[Int]] = Array(repeating: [], count: numVertices + 1)

adjList[1].append(2)
adjList[1].append(4)
adjList[2].append(5)
adjList[3].append(2)
adjList[4].append(2)
adjList[4].append(3)

inDegree[1] = 0
inDegree[2] = 3
inDegree[3] = 1
inDegree[4] = 1
inDegree[5] = 1

let topSort = topologicalSort(adjList: adjList)

for num in topSort {
    print(num, terminator: "")
    if num != topSort.last! {
        print("->",  terminator: "")
    }
}


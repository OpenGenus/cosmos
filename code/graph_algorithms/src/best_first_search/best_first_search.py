from queue import PriorityQueue


class BestFirstSearch:
    def __init__(self):
        self.n = 0
        self.e = 0
        self.matrix = [[0] * 20] * 20
        self.pq = PriorityQueue()
        self.heur = [0] * 20
        self.h = 0
        self.start = 0
        self.visited = [0] * 20
        self.list = []
        self.totalcost = 0

    def accept(self):
        self.n = int(input("Enter the number of nodes :"))
        self.matrix = [[0 for x in range(self.n)] for y in range(self.n)]
        for i in range(0, self.n):
            self.h = int(input("Enter heuristic value of this node :"))
            self.heur[i] = self.h

        self.e = int(input("Enter the number of edges :"))
        for i in range(0, self.e):
            self.x = int(input("Enter start node of the edge :"))
            self.y = int(input("Enter end node of the edge :"))
            self.cost = int(input("Enter cost of the edge :"))
            self.matrix[self.x][self.y] = self.cost
            self.matrix[self.y][self.x] = self.cost

        self.start = int(input("Enter start vertex of traversal :"))
        self.end = int(input("Enter end vertex of traversal :"))

    def display(self):
        print(self.matrix)

    def bfs(self):
        f = 999
        prev = self.start
        self.pq.put((self.heur[self.start], self.start))
        self.visited[self.start] = 1
        # self.list.append(self.start)

        while self.pq.empty() != 1 and f != 0:
            n = self.pq.get()
            f = n[0]
            p = n[1]
            self.visited[p] = 1
            self.list.append(p)
            self.totalcost = self.totalcost + self.matrix[prev][p]
            prev = p
            for i in range(0, self.n):
                if self.visited[i] != 1 and self.matrix[p][i] != 0:
                    self.pq.put((self.heur[i], i))

        print("Path : ", self.list)
        print("Cost = ", self.totalcost)


obj = BestFirstSearch()
obj.accept()
# obj.display()
obj.bfs()


# OUTPUT :
# 1)
# Enter the number of nodes :5
# Enter heuristic value of this node :7
# Enter heuristic value of this node :6
# Enter heuristic value of this node :2
# Enter heuristic value of this node :0
# Enter heuristic value of this node :1
# Enter the number of edges :7
# Enter start node of the edge :0
# Enter end node of the edge :2
# Enter cost of the edge :4
# Enter start node of the edge :0
# Enter end node of the edge :1
# Enter cost of the edge :1
# Enter start node of the edge :1
# Enter end node of the edge :2
# Enter cost of the edge :2
# Enter start node of the edge :1
# Enter end node of the edge :3
# Enter cost of the edge :12
# Enter start node of the edge :1
# Enter end node of the edge :4
# Enter cost of the edge :5
# Enter start node of the edge :2
# Enter end node of the edge :4
# Enter cost of the edge :2
# Enter start node of the edge :3
# Enter end node of the edge :4
# Enter cost of the edge :3
# Enter start vertex of traversal :0
# Enter end vertex of traversal :3
# Path :  [0, 2, 4, 3]
# Cost =  9

# 2)
# Enter the number of nodes :7
# Enter heuristic value of this node :10
# Enter heuristic value of this node :11
# Enter heuristic value of this node :5
# Enter heuristic value of this node :4
# Enter heuristic value of this node :2
# Enter heuristic value of this node :3
# Enter heuristic value of this node :0
# Enter the number of edges :6
# Enter start node of the edge :0
# Enter end node of the edge :1
# Enter cost of the edge :4
# Enter start node of the edge :0
# Enter end node of the edge :2
# Enter cost of the edge :1
# Enter start node of the edge :2
# Enter end node of the edge :5
# Enter cost of the edge :5
# Enter start node of the edge :2
# Enter end node of the edge :4
# Enter cost of the edge :3
# Enter start node of the edge :4
# Enter end node of the edge :5
# Enter cost of the edge :1
# Enter start node of the edge :4
# Enter end node of the edge :6
# Enter cost of the edge :1
# Enter start vertex of traversal :0
# Enter end vertex of traversal :6
# Path :  [0, 2, 4, 6]
# Cost =  5

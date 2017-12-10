/* Part of Cosmos by OpenGenus Foundation */

case class UnionFind[T](map: Map[T, T] = Map[T, T]()) {

    def add(element: T) = this.copy(map = map + (element -> element))

    def find(element: T): T = {
        val parent = map(element)
        if (parent == element) element else find(parent)
    }

    private def findRank(element: T, rank: Int): (T, Int) = {
        val parent = map(element)
        if (parent == element) (element, rank) else findRank(parent, rank + 1)
    }

    def union(x: T, y: T): UnionFind[T] = {
        val (parentX, rankX) = findRank(x, 0)
        val (parentY, rankY) = findRank(y, 0)
        val newPair = 
            if (rankX > rankY) (parentY -> parentX) 
            else               (parentX -> parentY)
        this.copy(map = map + newPair)
    }
}

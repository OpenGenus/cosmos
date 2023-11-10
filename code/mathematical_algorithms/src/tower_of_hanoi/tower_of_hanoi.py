# Part of Cosmos by OpenGenus Foundation
moves = 0


def TowerOfHanoi(disks, A, B, C):
    global moves
    moves += 1
    if disks == 1:
        print("Move disk 1 from rod", A, "to rod", B)
        return
    TowerOfHanoi(disks - 1, A, C, B)
    print("Move disk", disks, "from rod", A, "to rod", B)
    TowerOfHanoi(disks - 1, C, B, A)


# Driver code
n = int(input("Enter the number of disks- "))
TowerOfHanoi(n, "A", "C", "B")
print("Total moves required = " + str(moves))

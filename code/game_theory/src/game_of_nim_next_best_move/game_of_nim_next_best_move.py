def nim_sum(objectList, heaps):
    nim = 0

    # Calculate nim sum for all elements in the objectList
    for i in objectList:
        nim = nim ^ i

    print("The nim sum is {}.".format(nim))

    # Determine how many objects to remove from which heap
    objects_to_remove = max(objectList) - nim
    objects_to_remove = abs(objects_to_remove)

    # Logic for certain configurations on determining how many objects to remove from which heap
    # "objectList.index(max(objectList))+ 1 )" determines the index in objectList at which the biggest
    # heap of objects exists.
    if (nim > 0) and (len(objectList) > 2) and (nim != max(objectList)) and (nim != 1):
        print(
            "Pick {} objects from heap {}".format(
                objects_to_remove, objectList.index(max(objectList)) + 1
            )
        )
        break

    if (nim > 0) and (len(objectList) > 2) and (nim == max(objectList)) and (nim != 1):
        print(
            "Pick {} objects from heap {}.".format(
                nim, objectList.index(max(objectList)) + 1
            )
        )
        break

    if nim > 0 and len(objectList) <= 2 and (objects_to_remove != 0):
        print(
            "Pick {} objects from heap {}".format(
                objects_to_remove, objectList.index(max(objectList)) + 1
            )
        )
        break

    if nim > 0 and len(objectList) <= 2 and (objects_to_remove == 0):
        print(
            "Pick {} objects from heap {}".format(
                nim, objectList.index(max(objectList)) + 1
            )
        )
        break

    elif (nim == 1) and (len(objectList) <= 2):
        print(
            "Pick {} objects from heap {}".format(
                nim, objectList.index(max(objectList)) + 1
            )
        )
        break

    if (nim == 1) and (nim == max(objectList)) and (nim != 0) and (len(objectList) > 2):
        print(
            "Pick {} objects from heap {}".format(
                nim, objectList.index(max(objectList)) + 1
            )
        )
        break

    if nim == 0:
        print(
            "Pick all objects from heap {}.".format(
                objectList.index(max(objectList)) + 1
            )
        )
        break


def get_next_optimum(heaps):
    """
    Heaps should be in dictionary format where
    key : heap number, value : number of objects

    Example:
    {
        1:3,
        2:4,
        3:5
    }

    Maximum 5 heaps allowed with maximum 8 objects each
    """
    objects = list(heaps.values())
    heapKeys = list(heaps.keys())

    print(" Your game board looks like this ")
    print("-" * 30)

    for i in range(len(heapKeys)):
        print("Heap {} : {}".format(i + 1, "|" * objects[i]))

    print("-" * 30)
    nim_sum(objects, heapKeys)

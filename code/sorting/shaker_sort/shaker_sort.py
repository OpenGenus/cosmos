# Part of Cosmos by OpenGenus Foundation
import random


def shaker_sort(sort_list):
    beginning_idx = 0
    end_idx = len(sort_list) - 1
    while beginning_idx <= end_idx:
        swap = False
        for i in range(beginning_idx, end_idx):
            if sort_list[i] > sort_list[i + 1]:
                sort_list[i], sort_list[i + 1] = sort_list[i + 1], sort_list[i]
                swap = True
                end_idx = i
        if not swap:
            break
        swap = False
        for i in reversed(range(beginning_idx, end_idx)):
            if sort_list[i] > sort_list[i + 1]:
                sort_list[i], sort_list[i + 1] = sort_list[i + 1], sort_list[i]
                swap = True
                beginning_idx = i
        if not swap:
            break
    return sort_list


if __name__ == "__main__":
    count = 20

    source_list = []
    random.seed()
    for j in range(0, count):
        source_list.append(random.randint(0, 100))

    print("Input:", source_list)
    shaker_sort(source_list)
    print("Output:", source_list)

# Part of Cosmos by OpenGenus Foundation
import numpy as np


def bead_sort(arr):
    """
    >>> bead_sort([5, 3, 1, 7, 4, 1, 1, 20])
    [1, 1, 1, 3, 4, 5, 7, 20]
    """
    # expand input array to table of beads
    beads = np.zeros((len(arr), max(arr)), int)
    for i, x in enumerate(arr):
        beads[i, :x] = 1

    # move beads down
    for j, s in enumerate(beads.sum(axis=0)):
        beads[:-s, j] = 0
        beads[-s:, j] = 1

    # reduce table of moved down beads back to array
    return list(beads.sum(axis=1))

# Code inspiration taken from Wikipedia's Python Implementation
import functools

MISERE = "misere"
NORMAL = "normal"


def nim(heaps, game_type):
    """
    Computes next move for Nim, for both game types normal and misere.
    Assumption : Both players involved would play without making mistakes.

    if there is a winning move:
        return tuple(heap_index, amount_to_remove)
    else:
        return "You will lose :("
    """

    print(game_type, heaps, end=" ")

    is_misere = game_type == MISERE

    endgame_reached = False
    count_non_0_1 = sum(1 for x in heaps if x > 1)
    endgame_reached = count_non_0_1 <= 1

    # nim sum will give the correct end-game move for normal play but
    # misere requires the last move be forced onto the opponent
    if is_misere and endgame_reached:
        moves_left = sum(1 for x in heaps if x > 0)
        is_odd = moves_left % 2 == 1
        sizeof_max = max(heaps)
        index_of_max = heaps.index(sizeof_max)

        if sizeof_max == 1 and is_odd:
            return "You will lose :("

        # reduce the game to an odd number of 1's
        return index_of_max, sizeof_max - int(is_odd)

    nim_sum = functools.reduce(lambda x, y: x ^ y, heaps)
    if nim_sum == 0:
        return "You will lose :("

    # Calc which move to make
    for index, heap in enumerate(heaps):
        target_size = heap ^ nim_sum
        if target_size < heap:
            amount_to_remove = heap - target_size
            return index, amount_to_remove


if __name__ == "__main__":
    import doctest

    doctest.testmod()

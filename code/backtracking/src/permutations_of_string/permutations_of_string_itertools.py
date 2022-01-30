# Part of Cosmos by OpenGenus Foundation
import itertools
import typing


def permute(string: str) -> typing.Iterator[str]:
    """
    >>> list(permute('ABC'))
    ['ABC', 'ACB', 'BAC', 'BCA', 'CAB', 'CBA']
    """
    yield from map("".join, itertools.permutations(string))

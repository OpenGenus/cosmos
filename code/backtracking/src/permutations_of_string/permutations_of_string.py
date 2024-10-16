# Part of Cosmos by OpenGenus Foundation
import typing


def permute(s: str, i: int = 0) -> typing.Iterator[str]:
    """
    >>> list(permute('ABC'))
    ['ABC', 'ACB', 'BAC', 'BCA', 'CBA', 'CAB']
    """
    if i == len(s) - 1:
        yield "".join(s)
    else:
        for j in range(i, len(s)):
            yield from permute(s[:i] + s[i : j + 1][::-1] + s[j + 1 :], i + 1)

from itertools import zip_longest, islice


def to_int_keys(l):
    """
    l: iterable of keys
    returns: a list with integer keys
    """
    index = {v: i for i, v in enumerate(sorted(set(l)))}
    return [index[v] for v in l]


def suffix_matrix(to_int_keys, s):
    n = len(s)
    k = 1
    line = to_int_keys(s)
    ans = [line]
    while k < n:
        line = to_int_keys(
            list(zip_longest(line, islice(line, k, None),
                             fillvalue=-1)))
        ans.append(line)
        k <<= 1
    return ans

suffix_matrix(to_int_keys, 'banana')

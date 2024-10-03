# Part of Cosmos by OpenGenus Foundation
def bead_sort(obj):
    if all([type(x) == int and x >= 0 for x in obj]):
        ref = [range(x) for x in obj]  # for reference
    else:
        raise ValueError("All elements must be positive integers")
    inter = []  # for intermediate
    ind = 0  # for index
    prev = sum([1 for x in ref if len(x) > ind])  # prev for previous
    while prev:
        inter.append(range(prev))
        ind += 1
        prev = sum([1 for x in ref if len(x) > ind])
    ind = 0
    prev = sum([1 for x in inter if len(x) > ind])
    out = []
    while prev:
        out.append(prev)
        ind += 1
        prev = sum([1 for x in inter if len(x) > ind])
    out = out[::-1]
    return out

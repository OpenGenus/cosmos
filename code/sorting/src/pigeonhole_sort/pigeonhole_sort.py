# Part of Cosmos by OpenGenus Foundation
def pigeonhole_sort(a):
    # size of range of values in the list
    m_min = min(a)
    m_max = max(a)
    size = m_max - m_min + 1

    # our list of pigeonholes
    holes = [0] * size

    # Populating the pigeonholes.
    for x in a:
        assert type(x) is int, "integers only"
        holes[x - m_min] += 1

    # Putting the elements back into the array in order
    i = 0
    for count in xrange(size):
        while holes[count] > 0:
            holes[count] -= 1
            a[i] = count + m_min
            i += 1

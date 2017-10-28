# Part of Cosmos by Open Genus Foundation

import sys, time
gk = lambda i,j:str(i)+','+str(j)
MAX = sys.maxint
def memoized_matrix_chain(p):
    n = len(p)-1
    m = {}
    for i in xrange(1, n+1):
        for j in xrange (i, n+1):
            m[gk(i, j)] = MAX
    return lookup_chain(m, p, 1, n)

def lookup_chain(m, p, i, j):
    if m[gk(i, j)] < MAX:
        return m[gk(i, j)]
    if i == j:
        m[gk(i, j)] = 0
    else:
        for k in xrange(i, j):
            q = lookup_chain(m, p, i, k) + lookup_chain(m, p, k+1, j) + p[i-1]*p[k]*p[j]
            if q < m[gk(i, j)]:
                m[gk(i, j)] = q
    return m[gk(i, j)]

def main():
    p = [30,35,15,5,10,20,25,5,16,34,28,19,66,34,78,55,23]
    print memoized_matrix_chain(p)

if __name__ == '__main__':
    b = time.time()
    main()
    print 'total run time is:', time.time()-b

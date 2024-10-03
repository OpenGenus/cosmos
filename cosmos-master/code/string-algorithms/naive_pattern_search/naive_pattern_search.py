# Part of Cosmos by OpenGenus Foundation
def search(pat, txt):
    M = len(pat)
    N = len(txt)
 
    # Iterate pat[]
    for i in xrange(N-M+1):
        # For current index i, check for pattern match
        for j in xrange(M):
            if txt[i+j] != pat[j]:
                break
        if j == M-1: # if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            print "Pattern found at index " + str(i)

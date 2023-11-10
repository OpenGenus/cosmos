# Rabin Karp Algorithm in python using hash values
# d is the number of characters in input alphabet
d = 2560


def search(pat, txt, q):
    M = len(pat)
    N = len(txt)
    i = 0
    j = 0

    p = 0
    t = 0
    h = 1

    for i in range(M - 1):
        h = (h * d) % q

    for i in range(M):
        p = (d * p + ord(pat[i])) % q
        t = (d * t + ord(txt[i])) % q

    for i in range(N - M + 1):
        if p == t:
            for j in range(M):
                if txt[i + j] != pat[j]:
                    break

            j += 1
            if j == M:
                print("Pattern found at index " + str(i))

        if i < N - M:
            t = (d * (t - ord(txt[i]) * h) + ord(txt[i + M])) % q
            if t < 0:
                t = t + q


# Driver program to test the above function
txt = "ALL WORLDS IS A STAGE AND ALL OF US ARE A PART OF THE PLAY"
pat = "ALL"

q = 101  # A prime number
search(pat, txt, q)

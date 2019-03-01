def getLPS(pattern):
    m = len(pattern)
    lps = [0] * (m + 1)
    i = 0
    j = -1
    lps[i] = j
    while i < m:
        while j >= 0 and pattern[i] != pattern[j]:
            j = lps[j]
        i += 1
        j += 1
        lps[i] = j

    return lps


text = "ABC ABCDAB ABCDABCDABDE"
pattern = "ABCDABD"
lps = getLPS(pattern)

# Matching part
i = 0
j = 0
n = len(text)
m = len(pattern)

while i < n - 1:
    while j >= 0 and text[i] != pattern[j]:
        j = lps[j]
    i += 1
    j += 1

    if j == m:
        print("Match found at index: " + str(i - j))
j = lps[j]

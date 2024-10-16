def expand_center(s, l, r):
    while l >= 0 and r < len(s) and s[l] == s[r]:
        l -= 1
        r += 1
    return s[l + 1 : r]


def longest_pal_substr(s):
    ans = ""
    for c in range(len(s)):
        s1 = expand_center(s, c, c)
        s2 = expand_center(s, c, c + 1)
        ans = max(ans, s1, s2, key=len)
    return ans


if __name__ == "__main__":
    print(longest_pal_substr("belle"))
    print(longest_pal_substr("racecar"))

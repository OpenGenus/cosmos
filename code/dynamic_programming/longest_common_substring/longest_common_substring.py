def longestCommonSubstring(s1, s2):
    T = [[0 for col in range(600)]for row in range(600]] #adjustable array
    maximum = 0

    for i in range(len(s1)):
        for j in range(len(s2)):
            if s1[i-1] == s2[j-1]:
                T[i][j] = T[i-1][j-1] + 1
                if maximum < T[i][j]:
                    maximum = T[i][j]

    return maximum

if __name__ == '__main__':
    print(longestCommonSubstring("abcdedwwop", "abeeedcedwcdedop"))

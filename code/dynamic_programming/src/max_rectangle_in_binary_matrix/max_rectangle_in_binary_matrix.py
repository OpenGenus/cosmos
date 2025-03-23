# Part of Cosmos by OpenGenus Foundation

"""
Given a 2D binary matrix filled with 0’s and 1’s.
Find the Largest Rectangle containing all ones and return its Area.

Example:
    Input : [  [1, 1, 1],
               [0, 1, 1],
               [1, 0, 0]
            ]
    Output : 4

    Explanation:
        As the max area rectangle is created by the 2x2 rectangle
        created by (0,1), (0,2), (1,1) and (1,2)

Time Complexity : O(r*c)
Space Complexity : O(r*c), where r and c are the
number of rows and columns in the given binary matrix
"""


def find_max_area_in_histogram(hist):
    """
    :param hist: List[int]
    :return: int
    """
    right_max = [-1] * (len(hist))
    left_max = [-1] * (len(hist))
    st = [0]
    for i in range(1, len(hist)):
        while st != [] and hist[st[-1]] > hist[i]:
            right_max[st[-1]] = i
            st.pop()
        st.append(i)

    st = [len(hist) - 1]
    for i in range(len(hist) - 2, -1, -1):
        while st != [] and hist[st[-1]] > hist[i]:
            left_max[st[-1]] = i
            st.pop()
        st.append(i)

    ans = 0
    for i in range(len(hist)):
        left = left_max[i] + 1 if left_max[i] >= 0 else 0
        right = right_max[i] - 1 if right_max[i] >= 0 else len(hist) - 1
        ans = max(ans, (right - left + 1) * hist[i])
    return ans


def max_rectangle(mat):
    """

    :param mat: List[List[int]]
    :return: int
    """
    rows, cols = len(mat), len(mat[0])
    pref_mat = [[0] * cols for _ in range(rows)]

    for i in range(rows):
        count = 0
        for j in range(cols - 1, -1, -1):
            if mat[i][j] == 0:
                count = 0
            else:
                count += 1
                pref_mat[i][j] = count
    ans = 0
    for i in range(cols):
        hist = []
        for j in range(rows):
            if pref_mat[j][i] == 0:
                ans = max(ans, find_max_area_in_histogram(hist))
                hist = []
            else:
                hist.append(pref_mat[j][i])
        ans = max(ans, find_max_area_in_histogram(hist))
    return ans

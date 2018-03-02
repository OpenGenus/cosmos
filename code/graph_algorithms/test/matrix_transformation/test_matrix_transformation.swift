// Part of Cosmos by OpenGenus Foundation

import Foundation

class TestMatrixTransformation {
    let mt = MatrixTransformation()

    var matrix: [[Int]] = []

    let m0: [[Int]] = []
    let m1 = [[1]]
    let m2 = [[1, 2],
              [3, 4]]
    let m4 = [[ 1,  2,  3,  4],
              [ 5,  6,  7,  8],
              [ 9, 10, 11, 12],
              [13, 14, 15, 16]]
    let m5 = [[ 1,  2,  3,  4,  5],
              [ 6,  7,  8,  9, 10],
              [11, 12, 13, 14, 15],
              [16, 17, 18, 19, 20],
              [21, 22, 23, 24, 25]]

    func test() {
        test_rotate()
        test_symmetric()
    }

    func test_symmetric() {
        let s2 = [[1, 3],
                  [2, 4]]
        let s4 = [[ 1,  5,  9, 13],
                  [ 2,  6, 10, 14],
                  [ 3,  7, 11, 15],
                  [ 4,  8, 12, 16]]
        let s5 = [[ 1,  6, 11, 16, 21],
                  [ 2,  7, 12, 17, 22],
                  [ 3,  8, 13, 18, 23],
                  [ 4,  9, 14, 19, 24],
                  [ 5, 10, 15, 20, 25]]

        let r2 = [[4, 2],
                  [3, 1]]
        let r4 = [[16, 12,  8,  4],
                  [15, 11,  7,  3],
                  [14, 10,  6,  2],
                  [13,  9,  5,  1]]
        let r5 = [[25, 20, 15, 10,  5],
                  [24, 19, 14,  9,  4],
                  [23, 18, 13,  8,  3],
                  [22, 17, 12,  7,  2],
                  [21, 16, 11,  6,  1]]

        let ms = [m0, m1, m2, m4, m5]
        // symmetric of the matrices
        let ss = [m0, m1, s2, s4, s5]
        // reverse symmetric of the matrices
        let rs = [m0, m1, r2, r4, r5]

        for i in 0..<ms.count {
            matrix = ms[i]

            mt.square_transpose(&matrix)
            assert(same(matrix, ss[i]))
        }

        for i in 0..<ms.count {
            matrix = ms[i]

            mt.anti_square_transpose(&matrix)
            assert(same(matrix, rs[i]))
        }
    }

    func test_rotate() {
        let r2 = [[3, 1],
                  [4, 2]]
        let r4 = [[13,  9,  5,  1],
                  [14, 10,  6,  2],
                  [15, 11,  7,  3],
                  [16, 12,  8,  4]]
        let r5 = [[21, 16, 11,  6,  1],
                  [22, 17, 12,  7,  2],
                  [23, 18, 13,  8,  3],
                  [24, 19, 14,  9,  4],
                  [25, 20, 15, 10,  5]]

        let ms = [m0, m1, m2, m4, m5]
        // rotate of the matrices
        let rs = [m0, m1, r2, r4, r5]

        for i in 0..<ms.count {
            matrix = ms[i]

            mt.rotate(&matrix)
            assert(same(matrix, rs[i]))

            mt.reverse_rotate(&matrix)
            assert(same(matrix, ms[i]))
        }
    }

    private func same(_ matrix1: [[Int]], _ matrix2: [[Int]]) -> Bool {
        if matrix1.count != matrix2.count {
            return false
        }

        for i in 0..<matrix1.count {
            if matrix1[i].count != matrix2[i].count {
                return false
            }

            for j in 0..<matrix1[i].count {
                if matrix1[i][j] != matrix2[i][j] {
                    return false
                }
            }
        }

        return true
    }
}

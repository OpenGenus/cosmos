// Part of Cosmos by OpenGenus Foundation

import Foundation

class MatrixTransformation {
    func rotate<T>(_ matrix: inout [[T]]) {
        guard matrix.count > 0 && matrix.count == matrix[0].count else {
            return
        }

        // 1 2 3      7 8 9      7 4 1
        // 4 5 6  =>  4 5 6  =>  8 5 2
        // 7 8 9      1 2 3      9 6 3
        matrix.reverse()
        square_transpose(&matrix)
    }

    func reverse_rotate<T>(_ matrix: inout [[T]]) {
        guard matrix.count > 0 && matrix.count == matrix[0].count else {
            return
        }

        // 1 2 3      3 2 1      3 6 9
        // 4 5 6  =>  6 5 4  =>  2 5 8
        // 7 8 9      9 8 7      1 4 7
        for i in 0..<matrix.count {
            matrix[i].reverse()
        }
        square_transpose(&matrix)
    }

    func square_transpose<T>(_ matrix: inout [[T]]) {
        guard matrix.count > 0 && matrix.count == matrix[0].count else {
            return
        }

        // 1 2 3      1 4 7
        // 4 5 6  =>  2 5 8
        // 7 8 9      3 6 9
        for i in 0..<matrix.count {
            for j in i..<matrix.count {
                (matrix[i][j], matrix[j][i]) = (matrix[j][i], matrix[i][j])
            }
        }
    }

    func anti_square_transpose<T>(_ matrix: inout [[T]]) {
        guard matrix.count > 0 && matrix.count == matrix[0].count else {
            return
        }

        // 1 2 3      9 6 3
        // 4 5 6  =>  8 5 2
        // 7 8 9      7 4 1
        for i in 0..<matrix.count {
            for j in 0..<matrix.count - i {
                (matrix[i][j], matrix[matrix.count - j - 1][matrix.count - i - 1])
                    = (matrix[matrix.count - j - 1][matrix.count - i - 1], matrix[i][j])
            }
        }
    }

    func square_shearing<T: Numeric>(matrix: inout [[T]], coefficient: [[T]]) {
        guard matrix.count > 0 && matrix.count == matrix[0].count else {
            return
        }

        // 1 2 3    1 2 0      1  4  3
        // 4 5 6  x 0 1 0  =>  4 13  6
        // 7 8 9    0 0 1      7 22  9
        let ct = matrix.count
        var res = [[T]](repeating: [T](repeating: 0, count: ct), count: ct)
        for i in 0..<matrix.count {
            for j in 0..<matrix.count {
                for n in 0..<matrix.count {
                    res[i][j] += matrix[i][n] * coefficient[n][j]
                }
            }
        }
        matrix = res
    }
}

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
        symmetric(&matrix)
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
        symmetric(&matrix)
    }

    func symmetric<T>(_ matrix: inout [[T]]) {
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

    func reverse_symmetric<T>(_ matrix: inout [[T]]) {
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
}

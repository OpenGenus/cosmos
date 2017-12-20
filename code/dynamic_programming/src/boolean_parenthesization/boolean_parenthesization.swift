// dynamic programming | boolean parenthesization | Swift
// Part of Cosmos by OpenGenus Foundation

// Dynamic programming implementation of the boolean
// parenthesization problem using 'T' and 'F' as characters
// and '&', '|' and '^' as the operators
class BooleanParenthesization {
  
  private var characters = [Character]()
  private var operators = [Character]()
  private var memo = [[(Int, Int)]]()
  
  public func booleanParenthesization(_ expression: String) -> Int {
    
    parse(expression)
    
    memo = [[(Int, Int)]](repeating: [(Int, Int)](repeating: (-1, -1),
                          count: characters.count), count: characters.count)
    
    return solve(0, characters.count - 1).0
  }
  
  private func parse(_ expression: String) {
    
    characters = []
    operators = []
    for char in expression {
      
      if char == "T" || char == "F" {
        characters.append(char)
      }
      else if char == "&" || char == "|" || char == "^" {
        operators.append(char)
      }
    }
    
  }
  
  private func solve(_ i: Int, _ j: Int) -> (Int, Int) {
    
    if(i == j) {
      return characters[i] == "T" ? (1, 0) : (0, 1)
    }
    
    if(memo[i][j] > (-1, -1)) {
      return memo[i][j]
    }
    
    var total = (0, 0)
    
    for k in i..<j {
      
      let left = solve(i, k)
      let right = solve(k+1, j)
      var answer = (0, 0)
      
      if operators[k] == "&" {
        answer.0 = left.0 * right.0
        answer.1 = left.0 * right.1 + left.1 * right.0 + left.1 * right.1
      }
      else if operators[k] == "|" {
        answer.0 = left.0 * right.0 + left.0 * right.1 + left.1 * right.0
        answer.1 = left.1 * right.1
      }
      else if operators[k] == "^" {
        answer.0 = left.0 * right.1 + left.1 * right.0
        answer.1 = left.0 * right.0 + left.1 * right.1
      }
      
      total.0 += answer.0
      total.1 += answer.1
    }
    
    memo[i][j] = total
    return total
  }
  
}

func test() {
  
  let solution = BooleanParenthesization()
  
  let testCases = [
    "T|T&F^T", // 4
    "T^F|F",   // 2
    "T&F^F|T", // 5
  ]
  
  for test in testCases {
    print(solution.booleanParenthesization(test))
  }
  
}

test()

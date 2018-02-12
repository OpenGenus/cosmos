extension Int {
    func factorial() -> Int {
        guard self > 0 else { return 1 }
        return self * (self - 1).factorial()
    }
}

let x = -5
print(x.factorial())
print(0.factorial())
print(5.factorial())

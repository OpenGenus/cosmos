import Foundation

class MorseCode {
    let morseAlphabet = ["A": ".-", "B": "-...", "C": "-.-.", "D": "-..", "E": ".", "F": "..-.",
                         "G": "--.", "H": "....", "I": "..", "J": ".---", "K": "-.-", "L": ".-..",
                         "M": "--", "N": "-.", "O": "---", "P": ".--.", "Q": "--.-", "R": ".-.",
                         "S": "...", "T": "-", "U": "..-", "V": "...-", "W": ".--", "X": "-..-",
                         "Y": "-.--", "Z": "--..", "1": ".----", "2": "..---", "3": "...--",
                         "4": "....-", "5": ".....", "6": "-....", "7": "--...", "8": "---..",
                         "9": "----.", "0": "-----"]
    
    func encode(input: String) -> String {
        let result = NSMutableString()
        for i in input.characters.indices[input.startIndex..<input.endIndex] {
            if let morseCode = morseAlphabet[String(input[i])] {
                result.append(morseCode)
                result.append(" ")
            }
        }
        return String(result)
    }
    
    func decode(input: String) -> String {
        let codes = input.components(separatedBy: " ")
        let result = NSMutableString()
        for code in codes {
            let chars = char(forMorseCode: code)
            if chars.count > 0 {
                result.append(chars[0])
            }
        }
        return String(result)
    }
    
    func char(forMorseCode val: String) -> [String] {
        return morseAlphabet.filter { $1 == val }.map { $0.0 }
    }
}

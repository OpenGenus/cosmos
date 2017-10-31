class Vigenere
  @@alphabet = 'abcdefghijklmnopqrstuvwxyz'
  def initialize(key)
    @key = key.downcase
  end

  def encrypt(message)
    message = message.downcase
    result = ''
    for i in 0..message.length - 1
      letterNum = @@alphabet.index(message[i])
      keyNum = @@alphabet.index(@key[i % @key.length]) + 1
      resultNum = (letterNum + keyNum) % @@alphabet.length
      result << @@alphabet[resultNum]
    end
    result
  end

  def decrypt(cipher)
    cipher = cipher.downcase
    result = ''
    for i in 0..cipher.length - 1
      letterNum = @@alphabet.index(cipher[i])
      keyNum = @@alphabet.index(@key[i % @key.length]) + 1
      resultNum = (letterNum - keyNum) % @@alphabet.length
      result << @@alphabet[resultNum]
    end
    result
  end

  def self.encryptMessage(key, message)
    message = message.downcase
    result = ''
    for i in 0..message.length - 1
      letterNum = @@alphabet.index(message[i])
      keyNum = @@alphabet.index(key[i % key.length]) + 1
      resultNum = (letterNum + keyNum) % @@alphabet.length
      result << @@alphabet[resultNum]
    end
    result
  end

  def self.decryptMessage(key, cipher)
    cipher = cipher.downcase
    result = ''
    for i in 0..cipher.length - 1
      letterNum = @@alphabet.index(cipher[i])
      keyNum = @@alphabet.index(key[i % key.length]) + 1
      resultNum = (letterNum - keyNum) % @@alphabet.length
      result << @@alphabet[resultNum]
    end
    result
  end
end

# vig = Vigenere.new("abc")
# cipher = vig.encrypt("hello")
# puts cipher
# puts vig.decrypt(cipher)
# cipher2 = Vigenere.encryptMessage("abc", "hello")
# puts cipher2
# puts Vigenere.decryptMessage("abc", cipher2)

# Part of Cosmos by OpenGenus Foundation

require 'optparse'

options = {}
OptionParser.new do |opt|
  opt.banner = 'Usage: rail_fence.rb  [options]'

  opt.on('-e', '--encipher KEY') do |o|
    options[:encipher] = o
  end

  opt.on('-d', '--decipher KEY') do |o|
    options[:decipher] = o
  end
end.parse!

##
# A class for enciphering and deciphering messages using the Rail-fence cipher.
#
# See: http://practicalcryptography.com/ciphers/rail-fence-cipher/
class RailFence
  ##
  # Encipher a +message+ with the Rail-fence result.
  #
  # Params:
  # +message+::Message to encipher.
  # +key+::Key to encipher message with.
  def self.encipher(message, key)
    message.tr! ' ', '_'

    # Handle case where key = 1
    return message if key == 1

    # Initialize a matrix of characters
    matrix = Array.new(key.to_i) do
      Array.new(message.length, '.')
    end

    down = false
    row = 0
    col = 0

    # Iterate over characters in message to create matrix
    message.split('').each do |char|
      # Swap direction at the top or bottom row
      down = !down if (row == 0) || (row == (key - 1))

      # Fill corresponding letter in matrix
      matrix[row][col] = char
      col += 1

      # Increment or decrement row
      down ? row += 1 : row -= 1
    end

    # Construct result from matrix
    cipher = []

    matrix.each do |array|
      array.each do |char|
        cipher.push(char) unless char == '.'
      end
    end

    cipher.join('')
  end

  ##
  # Decipher a +message+ with the Rail-fence result.
  #
  # Params:
  # +message+::Message to decipher.
  # +key+::Key to decipher message.
  def self.decipher(message, key)
    message.tr! ' ', '_'

    # Handle case where key = 1
    return message if key == 1

    # Initialize a matrix of characters
    matrix = Array.new(key.to_i) do
      Array.new(message.length, '.')
    end

    down = false
    row = 0
    col = 0

    # Iterate over characters in message to create matrix
    message.split('').each do |_char|
      # Determine direction
      down = true if row == 0
      down = false if row == key - 1

      # Fill corresponding position with marker
      matrix[row][col] = '*'
      col += 1

      # Increment or decrement row
      down ? row += 1 : row -= 1
    end

    index = 0
    characters = message.split('')

    # Fill the matrix with the message
    matrix.each_with_index do |array, i|
      array.each_with_index do |char, j|
        if char == '*'
          matrix[i][j] = characters[index]
          index += 1
          end
      end
    end

    # Construct result from matrix
    result = []

    down = false
    row = 0
    col = 0

    while col < message.length

      # Determine which direction to move in
      down = true if row == 0
      down = false if row == key - 1

      result.push matrix[row][col]
      col += 1

      # Increment or decrement row
      down ? row += 1 : row -= 1

    end

    result.join('')
  end
end

if options.key? :encipher
  key = options[:encipher]
  puts RailFence.encipher ARGV.join(' '), key.to_i
end

if options.key? :decipher
  key = options[:decipher]
  puts RailFence.decipher ARGV.join(' '), key.to_i
end

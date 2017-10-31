# Part of Cosmos by OpenGenus Foundation
class Shuffler
  # This shuffle uses Fisher-Yates shuffle algorithm
  def self.arr!(array)
    len = array.length
    while len > 0
      len -= 1
      i = rand(len)
      array[i], array[len] = array[len], array[i]
    end
  end

  def self.arr(array)
    a = array.clone
    arr! a
    a
  end
end

def test
  puts 'Testing Array.shuffle'
  array = [1, 2, 3, 4, 5, 6, 7, 8, 9]
  puts '  Non-manipulated array: '
  puts '    ' + array.join(',')
  array2 = Shuffler.arr array
  puts '  array after Shuffler.arr'
  puts '    ' + array.join(',')
  puts '  Result of Shuffler.arr'
  puts '    ' + array2.join(',')
  Shuffler.arr! array
  puts '  array after Shuffler.arr!'
  puts '    ' + array.join(',')
end

test if $PROGRAM_NAME == __FILE__

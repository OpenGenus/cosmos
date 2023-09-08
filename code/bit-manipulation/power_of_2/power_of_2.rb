=begin

    Part of Cosmos by OpenGenus Foundation
    Created by Jiraphapa Jiravaraphan on 14/10/2017 
    Check if a number is a power of 2 - Ruby implementation

=end


def isPowerOfTwo(num)
    # 0 is excluded
    num != 0 && (num & (num - 1)) == 0
  end
  
isPowerOfTwo(64)
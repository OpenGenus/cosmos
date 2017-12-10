# Part of Cosmos by OpenGenus Foundation
def sleep_sort(arr, time = 0.01)
  require 'thread'
  # We need a semaphore to synchronize the access of the shared resource result
  mutex = Mutex.new
  result = []
  # For each element in the array, create a new thread which will sleep.
  threads = arr.collect do |e|
    Thread.new do
      sleep time * e
      mutex.synchronize { result << e }
    end
  end
  # Let all threads finish
  threads.each(&:join)

  result
end

def test
  puts 'Testing sleep_sort on array'
  array = [1, 4, 4, 2, 5, 8, 7, 6, 12]
  puts '  Before: ' + array.join(',')
  array = sleep_sort array, 0.05 # sleeping longer for demonstrative purpose
  puts '  After:  ' + array.join(',')
end

test if $PROGRAM_NAME == __FILE__

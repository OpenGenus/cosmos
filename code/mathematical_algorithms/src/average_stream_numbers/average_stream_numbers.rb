def stream_of_num(ar)
 sum = 0
 i = 1
 stream = []
 ar.each { 
  |x|
  sum += x
  avg = sum / i
  stream.push(avg)
  i += 1
  }
 stream
end

ar = [10, 20, 30, 40, 50, 60]
print "#{stream_of_num(ar)}"

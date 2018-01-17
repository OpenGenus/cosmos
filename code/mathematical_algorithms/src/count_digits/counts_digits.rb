def count_num(num)    
    count = 0 
    while num > 0
      num = num/10        
      count += 1
    end 
    count
end

print "#{count_num(2765)}"

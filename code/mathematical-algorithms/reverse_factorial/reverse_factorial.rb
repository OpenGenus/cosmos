def inverse_factorial(num)
  num = num.to_f
  i = 2.0
  j = 0  
  while i <= num 
    num = num/i
    if num == 1
     j = i
    end
    i+=1
  end
  j
end

num = 362880      
if inverse_factorial(num) > 0
    puts "#{inverse_factorial(num)}"   
else
    puts "No INVERSE FACTORIAL"
end

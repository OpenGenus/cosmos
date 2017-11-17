def factor_finder(num)
    i = 1
    fact = []
    while i <= num
        if num.modulo(i) == 0
            fact << i
        end
        i += 1
    end
    fact
end

def is_coprime?(num1,num2)
    f1=factor_finder(num1)
    f2=factor_finder(num2)
    common=f1 & f2
    return common.length==1
end

print "#{is_coprime?(22,21)}"  #output >> true
 

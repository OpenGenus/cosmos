def catalan(num)
    if num<=1
      return 1;
    end
    ans=0;
    i=0;
    
    while i<num
      first = catalan i;
      second = catalan num-i-1;
      ans = ans + (first*second);
      i += 1;
    end
    return ans;
end


Integer x = 1;
while x<=10
  res = catalan x;
  puts res;
  x = x + 1;
end

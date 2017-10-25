# Given an ip address, verify if it is a valid IPv4 address

def validate_ip(ip_addresss)
  components = ip_addresss.split('.')
	
  if components.length != 4
    return false
  else
    components.each do |item|
	  if !item.to_i.between?(0,255)
	    return false
	  end
	
  end
  return true
  end
end

# Correct IP address
p validate_ip('123.123.123.123')
# Incorrect IP address
p validate_ip('1234.123')
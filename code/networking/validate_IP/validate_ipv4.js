//Part of Cosmos by OpenGenus Foundation 
//javascript function to validate ipv4
const validate_ipv4 = function is_valid_ipv4(ip_addr){
	var ip_components = ip_addr.split('.')
	if(ip_components.length!= 4)
		return false;
	else{
		for (var i = ip_components.length - 1; i >= 0; i--) {
			var component = parseInt(ip_components[i]);
			if(component>255||component<0)
				return false;
		}		
	}
	return true;
}

const test_validate_ipv4 = function test(){
	var valid_IP = '192.168.1.1';
	var invalid_IP = '31.2.2';
	console.assert(validate_ipv4(valid_IP));
	console.assert(validate_ipv4(invalid_IP));
}

test_validate_ipv4();
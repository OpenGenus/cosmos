#!/usr/bin/python3
# Check if an IP address conforms to IPv4 standards
def validate_ipv4(ip_addr):
    ip_components = ip_addr.split(".")
    if len(ip_components) != 4:
        return False
    else:
        for component in ip_components:
            if int(component) not in range(0, 255):
                return False
        return True


if __name__ == "__main__":
    valid_IP = "192.168.1.1"
    invalid_IP = "31.2.2"
    assert validate_ipv4(valid_IP) == True
    assert validate_ipv4(invalid_IP) == False

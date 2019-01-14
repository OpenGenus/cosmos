# declare some system variables
iptables="/sbin/iptables"
ext_if=$(/sbin/ip route | grep default | awk '{print $5}') # giao dien mang

network_addr=$(/sbin/ip route | grep default | awk '{print $3}' | cut -d"." -f1-3) # Tach phan host ID ra
broadcast_addr="$network_addr.255" # dia chi broadast

# Mot so option
lan_allow="1" # Chap nhan moi connection tu LAN
blacklist_block="1" # Block moi ip blacklist
whitelist_allow="1" # Allow moi ip whitelist

# ------------------------------------------------------------------------------------
incoming_tcp="80,443"            # allow incoming tcp request
incoming_udp=""                  # allow incoming udp request
outgoing_tcp="22,53,80,443"      # allow outgoing tcp request
outgoing_udp="53,123"            # allow outgoing udp request
HTTP="80,443"
OK_ICMP="0 3 4 8 11"
# ------------------------------------------------------------------------------------

# file
black_list="blacklist.txt"
white_list="whitelist.txt"

### MAIN ###
case "$1" in
    start)
		echo -n "Starting firewall: "
		stop_firewall="0"
        ;;
    stop)
		echo -n "Stopping firewall: "
		stop_firewall="1"
        ;;
    *) 
        echo "Chay day du cau lenh: filewall.sh {start|stop}"
        exit 2
esac

# check if file is found
if [ $blacklist_block = "1" ] && [ ! -f $black_list ]; then
	echo "File $black_list not found."
	exit 1
fi

if [ $whitelist_allow = "1" ] && [ ! -f "$white_list" ]; then
	echo "File $white_list not found."
	exit 1
fi

### Start
# tuning network protection
echo 1 > /proc/sys/net/ipv4/tcp_syncookies                          # enable TCP SYN cookie protection for youngbuffalo DoS - 
echo 0 > /proc/sys/net/ipv4/conf/all/accept_source_route            # disable IP Source routing
echo 0 > /proc/sys/net/ipv4/conf/all/accept_redirects               # disable ICMP Redirect acceptance
echo 1 > /proc/sys/net/ipv4/conf/all/rp_filter                      # enable IP spoofing protection
echo 1 > /proc/sys/net/ipv4/icmp_echo_ignore_broadcasts             # ignore echo broadcast requests to prevent smurf attacks
echo 1 > /proc/sys/net/ipv4/ip_forward                              # enable ip forwarding

# reset lai cac rule hien tai cua iptables
$iptables -F # xoa chuoi dc chon hoac tung chuoi 1 trong bang neu k co chuoi nao duoc khai bao
$iptables -X 
# -X co 2 chuc nang chinh: Xoa moi chuoi duoc dinh nghia cua user, hoac neu k co tham so thi no se co gang xoa moi chuoi k co trong bang hien tai
$iptables -t nat -F
$iptables -t nat -X
# Xoa bang NAT. Xem them phan giai thich ve bang NAT trong bao cao hoac README.md
$iptables -t mangle -F
$iptables -t mangle -X
# tuong tu voi bang mangle

# default policy
if [ "$stop_firewall" = "0" ]; then
	$iptables -P INPUT   DROP
	$iptables -P FORWARD DROP
	$iptables -P OUTPUT  DROP
	echo "done"
elif [ "$stop_firewall" = "1" ]; then
	$iptables -P INPUT   ACCEPT
	$iptables -P FORWARD ACCEPT
	$iptables -P OUTPUT  ACCEPT
	echo "done"
	exit 0
fi

# drop broadcast (do not log)
$iptables -A INPUT -i $ext_if -d 255.255.255.255 -j DROP
$iptables -A INPUT -i $ext_if -d $broadcast_addr -j DROP

# allow allow loopback
$iptables -A INPUT  -i lo -j ACCEPT
$iptables -A OUTPUT -o lo -j ACCEPT

# allow all LAN connection
if [ "$lan_allow" = "1" ] && [ "$gateway" = "1" ]; then
	for eth in $int_if; do
		$iptables -A INPUT -i $eth -j ACCEPT
		$iptables -A OUTPUT -o $eth -j ACCEPT
	done
fi

# allow incoming SSH
$iptables -A INPUT -i $ext_if -p tcp --dport 22 -m state --state NEW,ESTABLISHED -j ACCEPT
$iptables -A OUTPUT -o $ext_if -p tcp --sport 22 -m state --state ESTABLISHED -j ACCEPT

# masquerading
if [ "$gateway" = "1" ]; then
	$iptables -t nat -A POSTROUTING -o $ext_if -j MASQUERADE 
	for eth in $int_if; do
		$iptables -A FORWARD -i $ext_if -o $eth -m state --state RELATED,ESTABLISHED -j ACCEPT
		$iptables -A FORWARD -i $eth -o $ext_if -j ACCEPT
	done
fi

# allow good ip from whitelist file
if [ "$whitelist_allow" = "1" ]; then
	$iptables -N acceptlist
	good_ips=$(egrep -v -E "^#|^$" $white_list)
	for ip in $good_ips; do
		$iptables -A acceptlist -s $ip -j LOG --log-prefix "Allow packet came from :"
		$iptables -A acceptlist -s $ip -j ACCEPT

	done
	# insert or append our acceptlist
	$iptables -I INPUT -j acceptlist
	$iptables -I OUTPUT -j acceptlist
	$iptables -I FORWARD -j acceptlist
fi

# block bad ip from blacklist file
if [ "$blacklist_block" = "1" ]; then
	$iptables -N droplist
	bad_ips=$(egrep -v -E "^#|^$" $black_list)
	for ip in $bad_ips; do
		$iptables -A droplist -s $ip -j LOG --log-prefix "Drop ip in blacklist: "
		echo -n "blacklists: "
		echo $ip
		$iptables -A droplist -s $ip -j DROP
	done
	# insert or append our droplist 
	$iptables -I INPUT -j droplist
	$iptables -I OUTPUT -j droplist
	$iptables -I FORWARD -j droplist
fi

# allow incoming TCP
if [ ! -z "$incoming_tcp" ]; then
	$iptables -A INPUT -i $ext_if -p tcp -m multiport --dports $incoming_tcp -m state --state NEW,ESTABLISHED -j ACCEPT
	$iptables -A OUTPUT -o $ext_if -p tcp -m multiport --sports $incoming_tcp -m state --state ESTABLISHED -j ACCEPT
fi

# allow incoming UDP
if [ ! -z "$incoming_udp" ]; then
	$iptables -A INPUT -i $ext_if -p udp -m multiport --dports $incoming_udp -m state --state NEW,ESTABLISHED -j ACCEPT
	$iptables -A OUTPUT -o $ext_if -p udp -m multiport --sports $incoming_udp -m state --state ESTABLISHED -j ACCEPT
fi

# allow outgoing TCP
if [ ! -z "$outgoing_tcp" ]; then
	$iptables -A OUTPUT -o $ext_if -p tcp -m multiport --dports $outgoing_tcp -m state --state NEW,ESTABLISHED -j ACCEPT
	$iptables -A INPUT -i $ext_if -p tcp -m multiport --sports $outgoing_tcp -m state --state ESTABLISHED -j ACCEPT
fi

# allow outgoing UDP
if [ ! -z "$outgoing_udp" ]; then
	$iptables -A OUTPUT -o $ext_if -p udp -m multiport --dports $outgoing_udp -m state --state NEW,ESTABLISHED -j ACCEPT
	$iptables -A INPUT -i $ext_if -p udp -m multiport --sports $outgoing_udp -m state --state ESTABLISHED -j ACCEPT
fi

# make sure to drop bad packages
$iptables -A INPUT -f -j DROP # Drop packages with incoming fragments
$iptables -A INPUT -p tcp --tcp-flags ALL ALL -j DROP # Drop incoming malformed XMAS packets
$iptables -A INPUT -p tcp --tcp-flags ALL NONE -j DROP # Drop all NULL packets
$iptables -A INPUT -p tcp ! --syn -m state --state NEW -j DROP # Drop all new connection are not SYN packets

# drop LAN subnet
$iptables -t mangle -A PREROUTING -s 224.0.0.0/3 -j DROP 
$iptables -t mangle -A PREROUTING -s 169.254.0.0/16 -j DROP 
$iptables -t mangle -A PREROUTING -s 172.16.0.0/12 -j DROP 
$iptables -t mangle -A PREROUTING -s 192.0.2.0/24 -j DROP 
$iptables -t mangle -A PREROUTING -s 192.168.0.0/16 -j DROP 
$iptables -t mangle -A PREROUTING -s 10.0.0.0/8 -j DROP 
$iptables -t mangle -A PREROUTING -s 0.0.0.0/8 -j DROP 
$iptables -t mangle -A PREROUTING -s 240.0.0.0/5 -j DROP 
$iptables -t mangle -A PREROUTING -s 127.0.0.0/8 ! -i lo -j DROP
########################################################################
# Chong lai steath scan - steath scan attack measures -nmap

$iptables -N STEALTH_SCAN # Tao moi chain "STEAlTH_SCAN" - make a chain
$iptables -A STEALTH_SCAN -j LOG --log-prefix "stealth_scan_attack: "
$iptables -A STEALTH_SCAN -j DROP
# Chuyen qua chain "STEALTH_SCAN" cho nhung packet da duoc stealth scan
# Jump to the "STEALTH_SCAN" chain for stealth scanned packets
$iptables -A INPUT -p tcp --tcp-flags SYN,ACK SYN,ACK -m state --state NEW -j STEALTH_SCAN

$iptables -A INPUT -p tcp --tcp-flags SYN,FIN SYN,FIN         -j STEALTH_SCAN
$iptables -A INPUT -p tcp --tcp-flags SYN,RST SYN,RST         -j STEALTH_SCAN
$iptables -A INPUT -p tcp --tcp-flags ALL SYN,RST,ACK,FIN,URG -j STEALTH_SCAN

$iptables -A INPUT -p tcp --tcp-flags FIN,RST FIN,RST -j STEALTH_SCAN
$iptables -A INPUT -p tcp --tcp-flags ACK,FIN FIN     -j STEALTH_SCAN
$iptables -A INPUT -p tcp --tcp-flags ACK,PSH PSH     -j STEALTH_SCAN
$iptables -A INPUT -p tcp --tcp-flags ACK,URG URG     -j STEALTH_SCAN
#########################################################################

# ping flood projection 5 per second
for item in $OK_ICMP; do
$iptables -A INPUT -i $ext_if -s $network_addr -p icmp --icmp-type $item -j ACCEPT
$iptables -A OUTPUT -o $ext_if -s $network_addr -p icmp --icmp-type $item -j ACCEPT
done

$iptables -A INPUT -p icmp -m limit --limit 5/s -j ACCEPT
$iptables -A OUTPUT -p icmp -m limit --limit 5/s -j ACCEPT
$iptables -A INPUT -p icmp -j DROP
$iptables -A OUTPUT -p icmp -j DROP

# Chong lai HTTP/Dos - DDos
# Counter HTTP/Dos - DDos
$iptables -N HTTP_DOS # Make chain with the name "HTTP_DOS"
$iptables -A HTTP_DOS -p tcp -m multiport --dports $HTTP \
         -m hashlimit \
         --hashlimit 1/s \
         --hashlimit-burst 100 \
         --hashlimit-htable-expire 300000 \
         --hashlimit-mode srcip \
         --hashlimit-name t_HTTP_DOS \
         -j RETURN

# Huy ket noi vuot qua gioi han
# Discard connection exceeding limit
$iptables -A HTTP_DOS -j LOG --log-prefix "http_dos_attack: "
echo "DDoS incomminggg"
$iptables -A HTTP_DOS -j DROP

# Nhay den chain HTTP_DOS
# Packets to HTTP jump to "HTTP_DOS" chain
$iptables -A INPUT -p tcp -m multiport --dports $incoming_tcp -j HTTP_DOS

# Log lai tat ca truoc khi drop
$iptables -A INPUT   -j LOG --log-prefix "IN: "
$iptables -A INPUT   -j DROP
$iptables -A OUTPUT  -j LOG --log-prefix "OU: "
$iptables -A OUTPUT  -j DROP
$iptables -A FORWARD -j LOG --log-prefix "FW: "
$iptables -A FORWARD -j DROP

### End
echo "done"
<?php

function is_ipv4($str) {
	$ret = filter_var($str, FILTER_VALIDATE_IP, FILTER_FLAG_IPV4);

	return $ret;
}

function is_ipv6($str) {
	$ret = filter_var($str, FILTER_VALIDATE_IP, FILTER_FLAG_IPV6);

	return $ret;
}

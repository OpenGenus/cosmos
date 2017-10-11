//Sleep Sort in PHP
//Author: Amit Kr. Singh
//Github: @amitsin6h
//Social: @amitsin6h
//OpenGenus Contributor

<?php
$list = range(1,10);
shuffle($list);
foreach($list as $li){
    $pid = pcntl_fork();
    if($pid == -1){
	die('could not fork');
    }else if($pid == 0){
	sleep($li);
	echo $li."\n";
	exit();
    }
}
?>

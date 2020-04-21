<?php

/* Part of Cosmos by OpenGenus Foundation */

/* Example Usage:
    echo morseEncode('HELLO');
    echo morseDecode('.... . .-.. .-.. ---');
*/

function morseDecode($str)
{

	$toCharMorseMap = ["A"=> ".-", "B"=> "-...", "C"=> "-.-.", "D"=> "-..", "E"=> ".", "F"=> "..-.", "G"=> "--.", "H"=> "....", "I"=> "..", "J"=> ".---", "K"=> "-.-", "L"=> ".-..", "M"=> "--", "N"=> "-.", "O"=> "---", "P"=> ".--.", "Q"=> "--.-", "R"=> ".-.", "S"=> "...", "T"=> "-", "U"=> "..-", "V"=> "...-", "W"=> ".--", "X"=> "-..-", "Y"=> "-.--", "Z"=> "--..", "1"=> ".----", "2"=> "..---", "3"=> "...--", "4"=> "....-", "5"=> ".....", "6"=> "-....", "7"=> "--...", "8"=> "---..", "9"=> "----.", "0"=> "-----"];
	$fromMorseMap = array_flip($toCharMorseMap);

	$charArray = [];

	$chars = explode(' ', strtoupper($str));
	foreach ($chars as $char) {
		$charArray[] = $fromMorseMap[$char];
	}

	return implode('', $charArray);

}

function morseEncode($str)
{

	$toCharMorseMap = ["A"=>".-", "B"=> "-...", "C"=> "-.-.", "D"=> "-..", "E"=> ".", "F"=> "..-.", "G"=> "--.", "H"=> "....", "I"=> "..", "J"=> ".---", "K"=> "-.-", "L"=> ".-..", "M"=> "--", "N"=> "-.", "O"=> "---", "P"=> ".--.", "Q"=> "--.-", "R"=> ".-.", "S"=> "...", "T"=> "-", "U"=> "..-", "V"=> "...-", "W"=> ".--", "X"=> "-..-", "Y"=> "-.--", "Z"=> "--..", "1"=> ".----", "2"=> "..---", "3"=> "...--", "4"=> "....-", "5"=> ".....", "6"=> "-....", "7"=> "--...", "8"=> "---..", "9"=> "----.", "0"=> "-----" ];

	$chars = str_split(strtoupper($str));
	$morseArray = [];

	foreach ($chars as $char) {
		$morseArray[] = $toCharMorseMap[$char];
	}

	return implode(' ', $morseArray);
}

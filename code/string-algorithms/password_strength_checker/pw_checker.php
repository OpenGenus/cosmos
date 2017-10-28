<?php
/**
 * Created by PhpStorm.
 * User: Ahmad khan
 * Date: 10/23/2017
 * Time: 10:17 AM
 */

$has_upper_letter = false;
$has_lower_letter = false;
$has_digits_letter = false;
$has_approved_length = false;
$storng_password = false;
$MIN_LENGTH = 8;
// password input
$input_password = "pak123@r";
// echo $input_password;
$has_approved_length = strlen($input_password) >= 8 ? true : false;
if ($has_approved_length) {

    for ($i = 0; $i < strlen($input_password); $i++) {

        if (ctype_upper($input_password[$i]) && $has_upper_letter == false) {
            $has_upper_letter = true;
        } else if (ctype_lower($input_password[$i]) && $has_lower_letter == false) {
            $has_lower_letter = true;
        } else if (is_numeric($input_password[$i]) && $has_digits_letter == false) {
            $has_digits_letter = true;
        }

        // check all condittions
        if ($has_upper_letter && $has_lower_letter && $has_digits_letter && $has_approved_length) {
            $storng_password = true;
            break;
        }

    }

    // display password strength
    if ($storng_password) {
        echo "Password is strong\n";
    } else {
        echo "Password is week\n";
        if (!$has_upper_letter) echo "You must have one upper case letter\n";
        if (!$has_lower_letter) echo "You must have one lower case letter\n";
        if (!$has_digits_letter) echo "You must have one digits case letter\n";
    }

} else {
    echo "You must have 8 digits lenght\n";
}
?>
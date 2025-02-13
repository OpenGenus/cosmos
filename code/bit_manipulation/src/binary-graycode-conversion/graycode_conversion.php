<?php
// Binary to Gray
function binaryToGray($n) {
    return $n ^ ($n >> 1);
}

// Gray to Binary
function grayToBinary($n) {
    $binary = $n;
    while ($n > 0) {
        $n >>= 1;
        $binary ^= $n;
    }
    return $binary;
}

$num = 7;
echo "Gray Code: " . binaryToGray($num) . "\n";  // Output: 4
echo "Binary Code: " . grayToBinary(binaryToGray($num)) . "\n"; // Output: 7
?>

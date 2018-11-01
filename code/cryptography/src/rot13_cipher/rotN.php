<?php
  // Translated from existing rotN.js
  function rotN($str, $n) {
    $output = '';
	$text = str_split($str);
    
    foreach($text as $char) {
      // Get ASCII code
      $ascii = ord($char);
      // Check if character is not a letter
      if ($ascii < 65 || $ascii > 122) {
        $output .= strval($char);
      } else {
        // Subtract 'A' if uppercase, 'a' if lowercase
        $sub = ($ascii >= 65 && $ascii <= 90) ? 'A' : 'a';
        // Convert to alphabet index starting from zero (0 - 25)
        $ascii -= ord($sub);
        // Shift
        $ascii += $n;
        // Wrap around
        $ascii = $ascii % 26;
        // Convert back to ASCII code and add to output
        $output .= strval(chr($ascii + ord($sub)));
      }
    }
    
    return $output;
  };

  // Examples
  echo rotN('Hello, world!', 13);  // Outputs "Uryyb, jbeyq!"
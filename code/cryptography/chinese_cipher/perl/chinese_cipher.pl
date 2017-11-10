#!/usr/bin/env perl

sub encrypt
{
  my $data = shift;

  my $encoded_data = '';

  my $length = length $data;
  my $sqrt = int(sqrt($length));
  $sqrt++ unless (($sqrt * $sqrt) >= $length);
  my @unencoded = split(//, $data);
  my @message;
  my $minside = $sqrt;
  if (($sqrt * $sqrt) > $length) {
    while (($minside * $sqrt) > $length) { $minside--;};
    $minside++; # ensure square can hold the string
  }

  for (my $j = 0; $j < $sqrt; $j++) {
    if ((($sqrt - $j)%2) == 0) {
      for (my $i = $minside-1; $i >= 0; $i--) {
        my $char = shift @unencoded;
        $message[$i][$j] = $char;
      }
    } else {
      for (my $i = 0; $i < $minside; $i++) {
        my $char = shift @unencoded;
        $message[$i][$j] = $char;
      }
    }
  }
  
  for (my $i = 0; $i < $minside; $i++) {
    for (my $j = 0; $j < $sqrt; $j++) {
      if (defined $message[$i][$j]) {
        $encoded_data .= $message[$i][$j];
      } else {
        $encoded_data .= " ";
      }
    }
  }

  return $encoded_data;
}

sub decrypt
{
  my $data = shift;

  my @chars = split(//, $data);
  my $length = length $data;
  my $sqrt = int(sqrt($length));
  if (($sqrt * $sqrt) < $length) {
    $sqrt++;
  }
  my $minside = $sqrt;
  if (($sqrt * $sqrt) > $length) {
    while (($minside * $sqrt) > $length) { $minside--;};
    $minside++; # ensure square can hold the string
  }

  my @message;
  for (my $i = 0; $i < $minside; $i++) {
    for (my $j = 0; $j < $sqrt; $j++) {
      my $char = shift @chars;
      $message[$i][$j] = $char;
    }
  }

  my $decoded_data = '';
  for (my $j = 0; $j < $sqrt; $j++) {
    if ((($sqrt - $j)%2) == 0) {
      for (my $i = $minside-1; $i >= 0; $i--) {
        $decoded_data .= $message[$i][$j];
      }
    } else {
      for (my $i = 0; $i < $minside; $i++) {
        $decoded_data .= $message[$i][$j];
      }
    }
  }

  #trim decoded_data
  $decoded_data =~ s/\s+$//;

  return $decoded_data;
}

sub test {
  my $text = shift;
  my $encrypted = encrypt($text);
  my $decrypted = decrypt($encrypted);
  return $decrypted eq $text;
}

print "Got expected message\n" if test('This is a test');

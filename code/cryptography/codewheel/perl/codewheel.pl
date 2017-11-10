#!/usr/bin/env perl

sub letters
{
  return join('', map {chr} (ord(' ') .. ord('~')));
}

sub num_letters
{
  return ord('~') - ord(' ') + 1;
}

sub rotate_amount
{
  my $num = shift;

  return 2 if $num <= 1;
  return 541 if $num >= 100;

  my @primes = (
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
    127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
    179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
    233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
    283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
    353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
    419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
    467, 479, 487, 491, 499, 503, 509, 521, 523, 541);

  return ($primes[$num - 1] % num_letters());
}

sub initialize_wheels
{
  my $num_wheels = shift;

  my $i = 0;
  while ($i < $num_wheels) {
    if ($i) {
      # subsequent wheels start shifted, odd wheels shift left
      $wheel_set->[$i] = rotate_wheel(letters(), rotate_amount($i + 1), $i % 2);
    } else {
      # initial wheel starts normal
      $wheel_set->[$i] = letters();
    }
    $i++;
  }

  return $wheel_set;
}

sub rotate_wheel
{
  my ($wheel, $num, $rotate_left) = @_;

  my $result;
  if ($rotate_left) {
    my ($front, $rest) = ($wheel =~ /^(.{$num})(.*)$/);
    $result = $rest . $front;
  } else {
    my ($rest, $end) = ($wheel =~ /^(.*)(.{$num})$/);
    $result = $end . $rest;
  }

  return $result;
}

sub read_wheels
{
  my ($wheel_set, $letter, $pos, $encode) = @_;
  my $encoded_letter;

  # ensure we can encode the letter, otherwise just emit it unchanged.
  return $letter if ord($letter) < ord(' ') || ord($letter) > ord('~');

  # encoding reads top down, decoding reads bottom up
  my $chosen = $pos % (scalar (@$wheel_set) - 1);
  if ($encode) {
    my $idx = index $wheel_set->[$chosen], $letter;
    $encoded_letter = substr $wheel_set->[$#wheel_set], $idx, 1;
  } else {
    my $idx = index $wheel_set->[$#wheel_set], $letter;
    $encoded_letter = substr $wheel_set->[$chosen], $idx, 1;
  }

  return $encoded_letter;
}

sub rotate_wheels
{
  my $wheel_set = shift;
  my $i = 0;

  # odd wheels rotate left
  while ($i < scalar (@$wheel_set)) {
    $wheel_set->[$i] = rotate_wheel($wheel_set->[$i], rotate_amount($i + 1), $i % 2);
    $i++;
  }
}

sub encrypt
{
  my ($data, $num_wheels) = @_;

  $num_wheels = 2 unless $num_wheels > 2;

  my $wheel_set = initialize_wheels($num_wheels);

  my $encoded_data;

  my @chars = split(//, $data);
  for (my $pos = 0; $pos < scalar @chars; $pos++) {
    $encoded_data .= read_wheels($wheel_set, $chars[$pos], $pos, 1);
    rotate_wheels($wheel_set);
  }

  return $encoded_data;
}

sub decrypt
{
  my ($data, $num_wheels) = @_;

  $num_wheels = 2 unless $num_wheels > 2;
  my $wheel_set = initialize_wheels($num_wheels);

  my $decoded_data;
  my @chars = split(//, $data);
  for (my $pos = 0; $pos < scalar @chars; $pos++) {
    $decoded_data .= read_wheels($wheel_set, $chars[$pos], $pos, 0);
    rotate_wheels($wheel_set);
  }

  return $decoded_data;
}

my $num_wheels = int(rand(101));
$num_wheels = 2 unless $num_wheels >= 2;

my $text;
{
  local $/;
  $text = <DATA>;
}

my $encrypted = encrypt($text, $num_wheels);
my $decrypted = decrypt($encrypted, $num_wheels);

if ($decrypted eq $text) {
  print "Decrypted matches original\n";
} else {
  print "Encrypted = $encrypted\n";
  print "Decrypted = $decrypted\n";
}

__DATA__
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis a lectus est. Donec a quam eu risus sagittis
rutrum quis at felis. Curabitur scelerisque aliquam nisi eu pharetra. Nulla eget nisl eu tellus efficitur
molestie. Aliquam fermentum eget enim non hendrerit. Suspendisse potenti. Nam iaculis ligula id felis
rhoncus, eu porta eros dictum. Sed consequat libero id augue tincidunt, vitae venenatis sapien condimentum.
Donec blandit commodo urna, non vestibulum sem tristique sed. Nam ornare, massa in ullamcorper feugiat,
elit nulla blandit sapien, non congue justo libero et nulla. Nunc faucibus ac tellus non semper. Proin
vehicula lacus lectus, id convallis tortor cursus quis. Vivamus egestas ex non magna cursus, sed maximus
est hendrerit. Vestibulum mi nunc, volutpat ut enim id, consequat scelerisque ante. Vivamus ut elit quis
augue hendrerit sagittis. Ut et tincidunt tortor.

Sed finibus ante vitae semper scelerisque. Mauris pellentesque leo ut lacus commodo, dapibus fringilla erat
malesuada. Morbi eleifend pellentesque lorem, eget sollicitudin erat egestas in. Nunc felis magna, semper
ac vehicula ac, lacinia eget risus. Suspendisse potenti. Cras id elit ante. Vivamus viverra lacinia purus,
at condimentum risus sagittis et. Integer fermentum mauris non nunc scelerisque, non ornare nibh lacinia.
Cras ac dolor ultrices, egestas tellus eget, pulvinar turpis. Vestibulum pellentesque libero sapien, non
rutrum nunc volutpat vel. Aliquam erat volutpat. Pellentesque molestie iaculis erat at varius. Proin
tincidunt tristique est, nec congue elit. Sed eu elementum massa, at euismod quam. Maecenas egestas neque at
interdum aliquet. Phasellus pretium, ante vel accumsan interdum, magna sem volutpat ante, et ullamcorper
nisi lectus sit amet est.

Praesent sed pretium nibh, vel dignissim libero. In hac habitasse platea dictumst. Aenean at gravida erat,
sit amet volutpat elit. Duis ac orci non dolor euismod tincidunt non vel velit. Phasellus at metus et lectus
tempus eleifend ut at nunc. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos
himenaeos. Proin ac maximus elit, at ultricies mauris. Vestibulum vehicula quam sed est mollis, et interdum
urna venenatis. Sed ac tortor dictum, pulvinar nibh sed, mollis tortor. Mauris lacus nisl, faucibus at nunc
ac, aliquam bibendum erat. Nullam faucibus dolor urna, id commodo nibh mattis quis.

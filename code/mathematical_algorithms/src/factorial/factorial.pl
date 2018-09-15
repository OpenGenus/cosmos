use strict;
use warnings;

sub factorial {
    my $factorial_of = shift;
    if ($factorial_of == 0) {
        return 1;
    }
    return $factorial_of * factorial($factorial_of - 1);
}

my $result = factorial(shift);
print "$result\n";
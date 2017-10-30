#!/usr/bin/env perl

use utf8;
use 5.024;
use warnings;
use feature qw(signatures);
no warnings qw(experimental::signatures);

{
    package FenwickTree;

    sub new($class, %args) {
        return bless {
            arr => [ (0) x ($args{max}+1) ], # arr[k] = x[k-phi(k)+1] + ... + x[k]
            n   => $args{max} + 1,
        }, 'FenwickTree';
    }

    sub phi($n) { return $n & -$n; }
    sub get($self, $k) { # returns x[1] + x[2] + x[3] + ... + x[k]
        return $k <= 0 ? 0 : $self->{arr}->[$k] + $self->get( $k - phi($k) );
    }
    sub add($self, $k, $c) { # x[k] += c
        return if $k > $self->{n};
        $self->{arr}->[$k] += $c;
        $self->add( $k+phi($k), $c );
    }
}

use Test::More tests => 2;

my $tree = FenwickTree->new( max => 12 );
my @values = (2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9);
$tree->add($_, $values[$_-1]) for (1..12);

is( $tree->get(5), 2+1+1+3+2, 'sum of first 5 elements' );

$tree->add(4, 4);

is( $tree->get(5), 2+1+1+(3+4)+2, 'sum after adding' );

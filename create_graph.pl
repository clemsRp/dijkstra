#!/usr/bin/perl
use strict;
use warnings;

my $n = int(rand(5)) + 3; # moins de nœuds pour simplifier
my @nodes = map { chr(65 + $_) } 0 .. $n - 1;

my $max_edges = $n * ($n - 1) / 2; # maximum sans doubles sens
my $m = int(rand($max_edges - $n + 1)) + $n;
my %seen;
my $edges = 0;

while ($edges < $m) {
    my $u = int(rand($n));
    my $v = int(rand($n));
    next if $u == $v; # pas d'auto-boucle

    my $key1 = "$u-$v";
    my $key2 = "$v-$u";
    next if exists $seen{$key1} || exists $seen{$key2}; # évite double sens et doublons

    my $d = int(rand(90)) + 10; # distance entre 10 et 99
    $seen{$key1} = 1;
    print "$nodes[$u]->$nodes[$v]:$d\n";
    $edges++;
}

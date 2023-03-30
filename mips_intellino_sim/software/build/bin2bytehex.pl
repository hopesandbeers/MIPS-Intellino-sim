#!/usr/bin/perl

if ($#ARGV < 1) {
    die "Error: No Argument!\n";
}
$file_input = $ARGV[0];
$file_output = $ARGV[1];
if (not -e "$file_input") {
    die "Error: \"$file_input\" does not exists!\n";
}


open (FH, "<$file_input") or die "oooops: $!";
open (WH, ">$file_output") or die "oooops: $!";


binmode FH;

while (read(FH, $_, 1)) {
    $hex = ord($_);
    printf WH "%02X\n", $hex;
}

close(FH);
close(WH);

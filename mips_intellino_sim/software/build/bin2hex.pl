#!/usr/bin/perl

if ($#ARGV < 0) {
    die "Error: No Argument!\n";
}
$filename = $ARGV[0];
if (not -e "$filename.bin") {
    die "Error: \"$filename.bin\" does not exists!\n";
}


open (FH, "<$filename.bin") or die "oooops: $!";
open (WH0, ">$filename"."0.hex") or die "oooops: $!";
open (WH1, ">$filename"."1.hex") or die "oooops: $!";
open (WH2, ">$filename"."2.hex") or die "oooops: $!";
open (WH3, ">$filename"."3.hex") or die "oooops: $!";


binmode FH;
$count = 0;
while (read(FH, $_, 1))
{
	$count += 1;
	$rem = $count % 4;
	if ($rem == 0) { 
        $hex3 = ord($_);
        printf WH0 "%02X\n", $hex0;
        printf WH1 "%02X\n", $hex1;
        printf WH2 "%02X\n", $hex2;
        printf WH3 "%02X\n", $hex3;
    }
	if ($rem == 1) { $hex0 = ord($_); }
	if ($rem == 2) { $hex1 = ord($_); }
	if ($rem == 3) { $hex2 = ord($_); }
}
close(FH);
close(WH0);
close(WH1);
close(WH2);
close(WH3);

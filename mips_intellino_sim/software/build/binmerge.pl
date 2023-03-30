#!/usr/bin/perl

use POSIX;

if ($#ARGV < 3) {
    die "Error: No Argument!\n";
}
$ifile0 = $ARGV[0];
$ifile1 = $ARGV[1];
$ifile2 = $ARGV[2];
$ofile = $ARGV[3];

if (not -e "$ifile0.bin") {
    die "Error: \"$ifile0.bin\" does not exists!\n";
}

if (not -e "$ifile1.bin") {
    die "Error: \"$ifile1.bin\" does not exists!\n";
}

if (not -e "$ifile2.bin") {
    die "Error: \"$ifile2.bin\" does not exists!\n";
}

open (RH0, "<$ifile0.bin") or die "oooops: $!";
open (RH1, "<$ifile1.bin") or die "oooops: $!";
open (RH2, "<$ifile2.bin") or die "oooops: $!";
open (WH,  ">$ofile.bin" ) or die "oooops: $!";
open (WHU, ">useg.bin"   ) or die "oooops: $!";

binmode RH0;
binmode RH1;
binmode RH2;
binmode WH;
binmode WHU;


# Write Useg Program Data
$count = 0;
$len_urom = 0;
$len_uram = 0;
$len_kram = 0;
while (read(RH0, $_, 1)) {
    $t = $_;
    print WH $t;
    print WHU $t;
	$count += 1;
}
$len_urom = $count;
if ( $count > 65536 ) {
    die "Error: Useg Program Data exceeded 64KB!\n";
} else {
    for (; $count < 65536; $count++) {
        print WH chr(0);
        print WHU chr(0);
    }
}

# Write Useg Static Data
while (read(RH1, $_, 1)) {
    $t = $_;
    print WH $t;
    print WHU $t;
	$count += 1;
}
$len_uram = $count - 65536;
if ( $count > 131072 ) {
    die "Error: Useg Static Data exceeded 64KB!\n";
} else {
    for (; $count < 131072 ; $count++) {
        print WH chr(0);
        print WHU chr(0);
    }
}

# Write Kseg Data
while (read(RH2, $_, 1)) {
    print WH $_;
	$count += 1;
}
$len_kram = $count - 131072;
if ( $count > 139264 ) {
    die "Error: Kseg Data exceeded 8KB!\n";
} else {
    for (; $count < 139264 ; $count++) {
        print WH chr(0);
    }
}

# Write metadata
for (; $count < 262144 - 3; $count++) {
    print WH chr(0);
}
print "Compilation Summary\n";
print "----------------------------\n";
print "TEXT_SIZE: $len_urom byte\n";
print "DATA_SIZE: $len_uram byte\n";
print "KSEG_SIZE: $len_kram byte\n";
$len_urom = ceil($len_urom / 256);
$len_uram = ceil($len_uram / 256);
$len_kram = ceil($len_kram / 256);

print WH chr($len_kram);
print WH chr($len_uram);
print WH chr($len_urom);
print "----------------------------\n";
print "TEXT_PAGE_SIZE: $len_urom\n";
print "DATA_PAGE_SIZE: $len_uram\n";
print "KSEG_PAGE_SIZE: $len_kram\n";


close(RH0);
close(RH1);
close(RH2);
close(WH);
close(WHU);

#! /usr/bin/perl
#
# $OpenBSD$
#
# Hack to convert an executable Linux shared library into an executable file.
#

use Fcntl;

$ldd = $ARGV[0];

print "Binary patching $ldd\n";

open(LDD, "+< $ldd") || die("open \"$ldd\" failed");
binmode(LDD);

# turn of dynamic tag
seek(LDD, 8, 0) || die("seek failed");
print LDD chr(0);

# ET_DYN -> ET_EXEC
seek(LDD, 16, 0) || die("seek failed");
print LDD chr(2);

close(LDD);

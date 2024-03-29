# ex:ts=8 sw=4:
# $OpenBSD$
#
# Copyright (c) 2010 Marc Espie <espie@openbsd.org>
#
# Permission to use, copy, modify, and distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
use strict;
use warnings;
package AddInfo;

sub add
{
	my ($class, $var, $o, $value, $parent) = @_;
	return if $value =~ m/^[\s\-]*$/;
	$o->{$var} = $class->new($value, $o, $parent);
}

sub new
{
	my ($class, $value) = @_;
	bless \$value, $class;
}

sub string
{
	my $self = shift;
	return $$self;
}

sub quickie
{
	return 0;
}

package AddIgnore;
our @ISA = qw(AddInfo);
sub string
{
	my $self = shift;
	my $msg = $$self;
	$msg =~ s/\\//g;
	$msg =~ s/\"\s+\"/\; /g;
	return $msg;
}



package AddYesNo;
our @ISA = qw(AddInfo);

sub add
{
	my ($class, $var, $o, $value, $parent) = @_;
	return if $value =~ m/^no$/i;
	$o->{$var} = $class->new($value, $o, $parent);
}

sub new
{
	my ($class, $value) = @_;
	my $a = 1;
	bless \$a, $class;
}

# micro-optimisation: to save space and time, we only create value if
# PERMIT_DISTFILES* is != yes.

package AddNegative;
our @ISA = qw(AddInfo);

sub add
{
	my ($class, $var, $o, $value, $parent) = @_;
	return if $value =~ m/^yes$/i;
	$o->{$var} = $class->new($value, $o, $parent);
}

sub new
{
	my ($class, $value) = @_;
	my $a = 0;
	bless \$a, $class;
}

package AddInfoShow;
our @ISA = qw(AddInfo);
sub quickie
{
	return 1;
}

package AddList;
our @ISA = qw(AddInfo);

sub make_list
{
	my ($class, $value) = @_;
	$value =~ s/^\s+//;
	$value =~ s/\s+$//;
	return split(/\s+/, $value);
}

sub new
{
	my ($class, $value) = @_;
	my %values = map {($_, 1)} $class->make_list($value);
	bless \%values, $class;
}

sub string
{
	my $self = shift;
	return join(', ', keys %$self);
}

package AddOrderedList;
our @ISA = qw(AddList);
sub new
{
	my ($class, $value) = @_;
	bless [$class->make_list($value)], $class;
}

sub string
{
	my $self = shift;
	return join(' ', @$self);
}

package FetchManually;
our @ISA = qw(AddOrderedList);
sub add
{
	my ($class, $var, $o, $value, $parent) = @_;
	return if $value =~ /^\s*no\*$/i;
	$class->SUPER::add($var, $o, $value, $parent);
}

sub make_list
{
	my ($class, $value) = @_;
	$value =~ s/^\s*\"//;
	$value =~ s/\"\s*$//;
	return split(/\"\s*\"/, $value);
}

sub string
{
	my $self = shift;
	return join("\n", @$self);
}

package AddDepends;
our @ISA = qw(AddList);
sub extra
{
	return 'EXTRA';
}

sub new
{
	my ($class, $value, $self, $parent) = @_;
	my $r = {};
	for my $_ ($class->make_list($value)) {
		my $copy = $_;
		next if m/^$/;
		s/^\:+//;
		s/^[^\/]*\://;
		if (s/\:(?:patch|build|configure)$//) {
			Extra->add($class->extra, $self, $_);
		} else {
			s/\:$//;
			if (m/[:<>=]/) {
				die "Error: invalid *DEPENDS $copy";
			} else {
				my $info = DPB::PkgPath->new($_);
				$info->{parent} //= $parent;
				$info->{wantbuild} = 1;
				$r->{$info} = $info;
			}
		}
	}
	bless $r, $class;
}

sub string
{
	my $self = shift;
	return '['.join(';', map {$_->logname} (values %$self)).']';
}

sub quickie
{
	return 1;
}

package AddRegressDepends;
our @ISA = qw(AddDepends);
sub extra
{
	return 'EXTRA2';
}

package Extra;
our @ISA = qw(AddDepends);

sub add
{
	my ($class, $key, $self, $value, $parent) = @_;
	$self->{$key} //= bless {}, $class;
	my $path = DPB::PkgPath->new($value);
	$path->{wantinfo} = 1;
	$path->{parent} //= $parent;
	$self->{$key}{$path} = $path;
	return $self;
}

package DPB::PortInfo;
my %adder = (
	FULLPKGNAME => "AddInfoShow",
	RUN_DEPENDS => "AddDepends",
	BUILD_DEPENDS => "AddDepends",
	LIB_DEPENDS => "AddDepends",
	REGRESS_DEPENDS => "AddRegressDepends",
	NO_REGRESS => "AddYesNo",
	REGRESS_IS_INTERACTIVE => "AddYesNo",
	SUBPACKAGE => "AddInfo",
	MULTI_PACKAGES => "AddList",
	BUILD_PACKAGES => "AddList",
	DPB_PROPERTIES => "AddList",
	EXTRA => "Extra",
	EXTRA2 => "Extra",
	BEXTRA => "Extra",
	DEPENDS => "AddDepends",
	BDEPENDS => "AddDepends",
	RDEPENDS => "AddDepends",
	DIST => "AddDepends",
	FDEPENDS => "AddDepends",
	IGNORE => "AddIgnore",
	FLAVOR => "AddList",
	NEEDED_BY => "AddDepends",
	BNEEDED_BY => "AddDepends",
	DISTFILES => 'AddList',
	PATCHFILES => 'AddList',
	SUPDISTFILES => 'AddList',
	DIST_SUBDIR => 'AddInfo',
	CHECKSUM_FILE => 'AddInfo',
	FETCH_MANUALLY => 'FetchManually',
	MISSING_FILES => 'AddList',
	MASTER_SITES => 'AddOrderedList',
	MASTER_SITES0 => 'AddOrderedList',
	MASTER_SITES1 => 'AddOrderedList',
	MASTER_SITES2 => 'AddOrderedList',
	MASTER_SITES3 => 'AddOrderedList',
	MASTER_SITES4 => 'AddOrderedList',
	MASTER_SITES5 => 'AddOrderedList',
	MASTER_SITES6 => 'AddOrderedList',
	MASTER_SITES7 => 'AddOrderedList',
	MASTER_SITES8 => 'AddOrderedList',
	MASTER_SITES9 => 'AddOrderedList',
	PERMIT_DISTFILES_FTP => 'AddNegative',
	PERMIT_DISTFILES_CDROM => 'AddNegative',
);

sub wanted
{
	my ($class, $var) = @_;
	return $adder{$var};
}

sub new
{
	my ($class, $pkgpath) = @_;
	$pkgpath->{info} = bless {}, $class;
}

sub add
{
	my ($self, $var, $value, $parent) = @_;
	$adder{$var}->add($var, $self, $value, $parent);
}

sub dump
{
	my ($self, $fh) = @_;
	for my $k (sort keys %adder) {
		print $fh "\t $k = ", $self->{$k}->string, "\n"
		    if defined $self->{$k};
	}
}

my $string = "ignored already";
my $s2 = "stub name";
my $stub_info = bless { IGNORE => bless(\$string, "AddIgnore"),
		FULLPKGNAME => bless(\$s2, "AddInfoShow")}, __PACKAGE__;

sub stub
{
	return $stub_info;
}

use Data::Dumper;
sub quick_dump
{
	my ($self, $fh) = @_;
	for my $k (sort keys %adder) {
		if (defined $self->{$k} and $adder{$k}->quickie) {
			print $fh "\t $k = ";
			if (ref($self->{$k}) eq 'HASH') {
				print $fh "????\n";
			} else {
				print $fh $self->{$k}->string, "\n" ;
			}
		}
	}
}

sub fullpkgname
{
	my $self = shift;

	return (defined $self->{FULLPKGNAME}) ?
	    $self->{FULLPKGNAME}->string : undef;
}

1;

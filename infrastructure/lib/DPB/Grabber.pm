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


use DPB::Vars;
use DPB::Util;

package DPB::Grabber;
sub new
{
	my ($class, $state, $endcode) = @_;

	my $o = bless { 
		loglist => DPB::Util->make_hot($state->logger->open("vars")),
		engine => $state->engine,
		state => $state,
		keep_going => 1,
		errors => 0,
		endcode => $endcode
	    }, $class;
	if ($state->{want_fetchinfo}) {
		require DPB::Fetch;
		$o->{dpb} = "fetch";
		$o->{fetch} = DPB::Fetch->new($state->distdir, $state->logger,
		    $state);
	} else {
		$o->{dpb} = "normal";
		$o->{fetch} = DPB::FetchDummy->new;
	}
	return $o;
}

sub expire_old_distfiles
{
	my ($self, $core, $opt_e) = @_;
	# don't bother if dump-vars wasn't perfectly clean
	return 0 if $self->{errors};
	return $self->{fetch}->run_expire_old($core, $opt_e);
}

sub finish
{
	my ($self, $h) = @_;
	for my $v (values %$h) {
		if ($v->{broken}) {
			delete $v->{info};
			$self->{engine}->add_fatal($v, $v->{broken});
			delete $v->{broken};
		} elsif ($v->{wantbuild}) {
			delete $v->{wantbuild};
			$self->{engine}->new_path($v);
		}
	}
	$self->{keepgoing} = &{$self->{endcode}};
}

sub ports
{
	my $self = shift;
	return $self->{state}->ports;
}

sub make
{
	my $self = shift;
	return $self->{state}->make;
}

sub make_args
{
	my $self = shift;
	return $self->{state}->make_args;
}

sub logger
{
	my $self = shift;
	return $self->{state}->logger;
}

sub grab_subdirs
{
	my ($self, $core, $list) = @_;
	DPB::Vars->grab_list($core, $self, $list,
	    $self->{loglist}, $self->{dpb},
	    sub {
	    	my $h = shift;
		for my $v (values %$h) {
			$v->{wantbuild} = 1;
		}
		$self->finish($h);
	});
}

sub grab_signature
{
	my ($self, $core, $pkgpath) = @_;
	return DPB::PortSignature->grab_signature($core, $self, $pkgpath);
}

sub clean_packages
{
	my ($self, $core, $pkgpath) = @_;
	return DPB::CleanPackages->clean($core, $self, $pkgpath);
}

sub complete_subdirs
{
	my ($self, $core) = @_;
	# more passes if necessary
	while ($self->{keep_going}) {
		my $subdirlist = {};
		for my $v (DPB::PkgPath->seen) {
			if (defined $v->{info}) {
				delete $v->{tried};
				delete $v->{wantinfo};
				if (defined $v->{wantbuild}) {
					delete $v->{wantbuild};
					$self->{engine}->new_path($v);
				}
				next;
			}
			next if defined $v->{category};
			if (defined $v->{tried}) {
				$self->{engine}->add_fatal($v, "tried and didn't get it") 
				    if !defined $v->{errored};
				$v->{errored} = 1;
				$self->{errors}++;
			} elsif ($v->{wantinfo} || $v->{wantbuild}) {
				$v->add_to_subdirlist($subdirlist);
				$v->{tried} = 1;
			}
		}
		last if (keys %$subdirlist) == 0;

		DPB::Vars->grab_list($core, $self, $subdirlist,
		    $self->{loglist}, $self->{dpb},
		    sub {
			$self->finish(shift);
		    });
	}
}

package DPB::FetchDummy;
sub new
{
	my $class = shift;
	bless {}, $class;
}

sub build_distinfo
{
}

sub run_expire_old
{
	return 0;
}

1;

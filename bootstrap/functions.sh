#!/bin/sh
#
# Copyright (c) 2012 Antti Harri <iku@openbsd.fi>
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
#

extract_distfile()
{
	local url subdir distfile
	for i in "$@"; do
		url=$(printf '%s\n' "$i" | cut -f 2 -d ';')
		subdir=$(printf '%s\n' "$i" | cut -f 1 -d ';')
		distfile=$(basename "$url")
		# if url==subdir then there is no subdir defined
		test "$url" = "$subdir" && subdir=
		mkdir -p "$DISTDIR/$subdir/"
		if [ ! -f "$DISTDIR/$subdir/$distfile" ]; then
			(cd "$DISTDIR/$subdir" && $FETCH_CMD "$url")
		fi
		case "$distfile" in
			*.tar.gz|*.tgz)
				tar zxf "$DISTDIR/$subdir/$distfile" ;;
			*.tar.bz2|*.tbz2)
				tar jxf "$DISTDIR/$subdir/$distfile" ;;
			*.tar.xz|*.txz)
				tar Jxf "$DISTDIR/$subdir/$distfile" ;;
		esac
	done
}

build_done()
{
	cd "$WRKDIR"
	touch ".${1}_done"
}

clean()
{
	for i in "$@"; do
		test -d "$WRKDIR/$i" && \
			mv -f "$WRKDIR/$i" "$WRKDIR/.removing_$i" && \
			( rm -rf "$WRKDIR/.removing_$i" & )
	done
}

apply_patch()
{
	for i in "$PORTSDIR/bootstrap/patches/"binutils-*; do
		(cd "$WRKDIR" && patch -b -p0 -i "$i")
	done
}

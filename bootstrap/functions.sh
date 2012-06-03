#!/bin/sh

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
			rm -rf "$WRKDIR/.removing_$i" &
	done
}

apply_patch()
{
	for i in "$PORTSDIR/bootstrap/patches/"binutils-*; do
		(cd "$WRKDIR" && patch -b -p0 -i "$i")
	done
}

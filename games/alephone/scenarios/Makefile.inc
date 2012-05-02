#	$OpenBSD: ports/games/alephone/scenarios/Makefile.inc,v 1.4 2012/01/27 21:35:24 phessler Exp $

DIST_SUBDIR ?=	alephone

CATEGORIES =	games

MAINTAINER =	Peter Hessler <phessler@openbsd.org>

MASTER_SITES =	http://trilogyrelease.bungie.org/files/
MASTER_SITES0 =	ftp://ftp2.fileball.net/fileball/marathon/aleph1/alterations/
MASTER_SITES1 =	http://www.lhowon.org/
MASTER_SITES2 =	http://nardofiles.bungie.org/
MASTER_SITES3 =	http://www.appleswitch.com/uploads/
MASTER_SITES4 = http://archives2.bungie.org/manuals/
MASTER_SITES5 = http://files3.bungie.org/trilogy/

RUN_DEPENDS =	games/alephone/alephone


NO_BUILD =	Yes
NO_REGRESS =	Yes
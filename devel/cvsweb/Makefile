# $OpenBSD$

COMMENT=	WWW CGI script to browse CVS repository trees

DISTNAME=	cvsweb-2.0.6
REVISION =	11
CATEGORIES=	devel www
HOMEPAGE=	http://www.freebsd.org/projects/cvsweb.html

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${MASTER_SITE_FREEBSD_LOCAL:=scop/} \
		http://people.FreeBSD.org/~scop/cvsweb/

NO_BUILD=	Yes
NO_REGRESS=	Yes
PKG_ARCH=	*

PREFIX=		/var/www
CONFDIR=	${PREFIX}/conf

CONFFILES=	cvsweb.conf cvsweb.conf-freebsd cvsweb.conf-netbsd \
		cvsweb.conf-openbsd cvsweb.conf-ruby
ICONS=		back.gif dir.gif text.gif \
		miniback.gif minidir.gif minitext.gif

SUBST_VARS=	CONFDIR

do-configure:
	@perl -i -pe 's@%%CONFDIR%%@${CONFDIR}@g' ${WRKSRC}/cvsweb.cgi

do-install:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/cvsweb.cgi ${PREFIX}/cgi-bin/cvsweb
	${INSTALL_DATA_DIR} ${CONFDIR}/cvsweb
.for file in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${CONFDIR}/cvsweb/${file}.dist
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/icons/cvsweb
.for file in ${ICONS}
	${INSTALL_DATA} ${WRKSRC}/icons/${file} ${PREFIX}/icons/cvsweb/${file}
.endfor

.include <bsd.port.mk>

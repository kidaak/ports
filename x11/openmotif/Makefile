# $OpenBSD$

COMMENT-main=		Motif toolkit
COMMENT-demos=		Motif toolkit demos

VERSION=		2.3.3
DISTNAME=		openmotif-${VERSION}
PKGNAME-main=		openmotif-${VERSION}
PKGNAME-demos=		openmotif-demos-${VERSION}

REVISION-main=		4
REVISION-demos= 	2

SHARED_LIBS=		Mrm	4.1	\
			Uil	5.0	\
			Xm	6.0

CATEGORIES=		x11
#MASTER_SITES=		ftp://ftp.ics.com/openmotif/2.3/${VERSION}/
MASTER_SITES=		http://distfiles.nl/ \
			ftp://ftp.openbsd.org/pub/OpenBSD/distfiles/openmotif/
DIST_SUBDIR=		openmotif

HOMEPAGE=		http://www.opengroup.org/openmotif/

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_FTP=	Yes

MULTI_PACKAGES= 	-demos -main

USE_GROFF =		Yes
CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--enable-themes \
			--enable-xft \
			--enable-jpeg \
			--disable-printing \
			--enable-png
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng" \
			LDFLAGS="-L${LOCALBASE}/lib -lm"

USE_LIBTOOL=		Yes

MAKE_FLAGS=		SOMRMREV=${LIBMrm_VERSION}	\
			SOUILREV=${LIBUil_VERSION}	\
			SOXMREV=${LIBXm_VERSION}
FAKE_FLAGS+=		bindir=${PREFIX}/bin/

MODULES=		converters/libiconv

LIB_DEPENDS=		graphics/jpeg \
			graphics/png
LIB_DEPENDS-demos=	x11/openmotif \
			${MODLIBICONV_LIB_DEPENDS} \
			${LIB_DEPENDS}
WANTLIB=		ICE SM X11 Xext Xt c Xau Xdmcp Xft Xmu Xrender \
			expat fontconfig freetype m z pthread-stubs xcb \
			jpeg png
WANTLIB-demos=		${WANTLIB} Xm Mrm

# XXX  Large, complicated, only partially automated test suite available
NO_REGRESS=	Yes

pre-configure:
# fix sections
	@cd ${WRKSRC}/doc/man/man1 && perl -pi -e "s|user cmd|1|" *.1
	@cd ${WRKSRC}/doc/man/man3 && perl -pi -e "s|library call|3|" *.3
# mwmrc is not a kernel interface!!
	@cd ${WRKSRC}/doc/man/man4 && perl -pi -e "s|special file|5|" *.4
	@cd ${WRKSRC}/doc/man/man5 && perl -pi -e "s|file formats|5|" *.5
	@mkdir -p ${WRKSRC}/imports/x11
	@cd ${WRKSRC}/imports/x11 && for i in bin include lib ; do \
	    if [ -f $$i ] ; then rm $$i; fi; \
	    ln -s ${X11BASE}/$$i $$i; \
	done

	${SUBST_CMD} ${WRKSRC}/config/cf/host.def \
		${WRKSRC}/config/cf/Motif.tmpl \
		${WRKSRC}/lib/Xm/Makefile.in

DOCS=BUGREPORT COPYRIGHT.MOTIF LICENSE README RELEASE RELNOTES TODO
DOCDIR=${PREFIX}/share/doc/openmotif

post-install:
	@${INSTALL_DATA_DIR} ${DOCDIR}
	@for i in ${DOCS}; do ${INSTALL_DATA} ${WRKSRC}/$$i ${DOCDIR}; done
	@${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/config
	@${INSTALL_DATA} ${WRKSRC}/config/cf/Motif.rules \
	    ${PREFIX}/lib/X11/config/Motif.rules
	@${INSTALL_DATA} ${WRKSRC}/config/cf/Motif.tmpl \
	    ${PREFIX}/lib/X11/config/Motif.tmpl

.include <bsd.port.mk>

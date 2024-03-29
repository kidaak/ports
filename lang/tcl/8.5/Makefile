# $OpenBSD$

COMMENT =		Tool Command Language

DISTNAME =		tcl8.5.12
PKGNAME =		tcl-8.5.12
SHARED_LIBS =		tcl85 1.2
CATEGORIES =		lang lang/tcl
HOMEPAGE =		http://www.tcl.tk/
MAINTAINER =		Stuart Cassoff <stwo@users.sourceforge.net>

# BSD
PERMIT_PACKAGE_CDROM =	Yes
PERMIT_PACKAGE_FTP =	Yes
PERMIT_DISTFILES_CDROM =Yes
PERMIT_DISTFILES_FTP =	Yes

WANTLIB =		c m

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=tcl/}
DISTFILES =		${DISTNAME}-src.tar.gz

MAKE_FLAGS +=		TCL_PACKAGE_PATH='$$(prefix)/lib/tcl' \
			TCL_LIBRARY='$$(prefix)/lib/tcl/tcl$$(VERSION)'

FAKE_FLAGS =		INSTALL_DATA_DIR="${INSTALL_DATA_DIR}" \
			INSTALL_LIBRARY="${INSTALL_DATA}" \
			INSTALL_DATA="${INSTALL_DATA}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			CONFIG_INSTALL_DIR='$$(SCRIPT_INSTALL_DIR)' \
			MAN1_INSTALL_DIR='$$(MAN_INSTALL_DIR)/cat1' \
			MAN3_INSTALL_DIR='$$(MAN_INSTALL_DIR)/cat3' \
			MANN_INSTALL_DIR='$$(MAN_INSTALL_DIR)/catn'

REGRESS_FLAGS =		HOME=${TESTHOME} TESTFLAGS="${TESTFLAGS}"
SEPARATE_BUILD =	Yes
USE_GROFF =		Yes
CONFIGURE_STYLE =	gnu old

CONFIGURE_ARGS +=	${CONFIGURE_SHARED} \
			--includedir="${PREFIX}/include/tcl8.5" \
			--mandir="${PREFIX}/lib/tcl/tcl8.5/man" \
			--sysconfdir="${SYSCONFDIR}" \
			--enable-man-symlinks \
			--disable-rpath \
			EXTRA_INSTALL="install-private-headers" \
			SHLIB_VERSION="${LIBtcl85_VERSION}"

FLAVORS =		threaded
FLAVOR ?=

.if ${FLAVOR:Mthreaded}
CONFIGURE_ARGS +=	--enable-threads
WANTLIB +=		pthread
.endif

.include <bsd.port.arch.mk>

.if ${NO_SHARED_LIBS:L} == "no"
ALL_TARGET =		all libtcl85.a
CONFIGURE_ARGS +=	EXTRA_INSTALL_BINARIES='@echo "Installing libtcl85.a to $$(LIB_INSTALL_DIR)/" \
			&& $$(INSTALL_DATA) libtcl85.a $$(LIB_INSTALL_DIR)/libtcl85.a \
			&& (cd $$(LIB_INSTALL_DIR) ; $$(RANLIB) libtcl85.a)'
.endif

WRKSRC =		${WRKDIST}/unix
REGRESS_TARGET =	test
SUBST_VARS +=		_README_DIR

TESTHOME =		${WRKDIR}/testhome
# Use TESTFLAGS to control the Tcl tests
TESTFLAGS =

pre-regress:
	mkdir -p ${TESTHOME}

post-install:
	${INSTALL_DATA} ${WRKDIST}/license.terms ${PREFIX}/lib/tcl/tcl8.5/man
.if ${NO_SHARED_LIBS:L} == "no"
	ln -s libtcl85.a ${PREFIX}/lib/libtcl85_pic.a
	ln -s libtclstub85.a ${PREFIX}/lib/libtclstub85_pic.a
.endif

.include <bsd.port.mk>

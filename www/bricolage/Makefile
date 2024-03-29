# $OpenBSD$

COMMENT=	content management system

DISTNAME=	bricolage-1.10.3
REVISION=	1
CATEGORIES=	www perl5

HOMEPAGE=	http://www.bricolage.cc/

# BSD
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	${HOMEPAGE}downloads/

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	databases/p5-DBD-Pg \
		databases/postgresql,-server>=7.3 \
		devel/p5-Cache-Mmap \
		devel/p5-Data-UUID \
		devel/p5-DateTime \
		devel/p5-List-MoreUtils \
		devel/p5-MLDBM \
		devel/p5-Term-ReadPassword \
		devel/p5-Test-Class \
		devel/p5-Test-File-Contents \
		devel/p5-Test-MockModule \
		editors/xinha \
		net/p5-Net-SFTP \
		graphics/p5-Image-Info \
		sysutils/p5-Unix-Syslog \
		textproc/p5-Template \
		textproc/p5-Text-Diff-HTML \
		textproc/p5-Text-LevenshteinXS \
		textproc/p5-Text-WordDiff \
		textproc/p5-XML-Simple \
		textproc/p5-XML-Writer \
		www/p5-Apache-Session \
		www/p5-HTML-Template-Expr \
		www/p5-MasonX-Interp-WithCallbacks \
		www/p5-SOAP-Lite

# needed for other settings to take effect
CONFIGURE_STYLE=perl

MAKE_FLAGS=	INSTALL_VERBOSITY=QUIET
ALL_TARGET=	build

USE_GROFF =	Yes
PKG_ARCH=	*

do-configure:
	@sed -e "s,%%PREFIX%%,${PREFIX}," -e "s,%%X11BASE%%,${X11BASE}," \
		${FILESDIR}/openbsd > ${WRKSRC}/inst/defaults/standard
	@perl -pi -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/inst/config.pl \
		${WRKSRC}/INSTALL ${WRKSRC}/bin/bric_* \
		${WRKSRC}/inst/upgrade/lib/bric_upgrade.pm
	@cd ${WRKSRC} && make all

# bulk creation of man pages fails for these, perl bug?
post-build:
	@rm ${WRKSRC}/lib/blib/man3/Bric::Dist::Action::DTDValidate.3p
	@rm ${WRKSRC}/lib/blib/man3/Bric::Util::Alerted.3p
	@cd ${WRKSRC}/lib && perl "-MExtUtils::Command::MM" -e pod2man "--" \
		--section=3 --perm_rw=644 \
		Bric/Dist/Action/DTDValidate.pm blib/man3/Bric::Dist::Action::DTDValidate.3p \
		Bric/Util/Alerted.pm blib/man3/Bric::Util::Alerted.3p

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/bricolage/sql/Pg
	${INSTALL_DATA} ${WRKSRC}/inst/Pg.sql ${PREFIX}/share/bricolage/sql/Pg
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bricolage
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/bricolage
	ln -s /var/www/xinha ${PREFIX}/share/bricolage/comp/media/wysiwyg/xinha
	${INSTALL_DATA_DIR} ${PREFIX}/share/bricolage/upgrade
	${INSTALL_DATA} ${WRKSRC}/inst/versions.txt \
		${PREFIX}/share/bricolage/upgrade
	cp -R ${WRKSRC}/inst/upgrade/* ${PREFIX}/share/bricolage/upgrade
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/bricolage/upgrade

.include <bsd.port.mk>

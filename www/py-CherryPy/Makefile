# $OpenBSD$

COMMENT=	pythonic, object-oriented web development framework

MODPY_EGG_VERSION=	3.2.0
REVISION=		1
DISTNAME=		CherryPy-${MODPY_EGG_VERSION}
PKGNAME=		py-${DISTNAME}
CATEGORIES=		www

HOMEPAGE=	http://www.cherrypy.org/ 

MAINTAINER=	Joerg Zinke <mail@umaxx.net>

# BSD 
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

MASTER_SITES=	http://download.cherrypy.org/cherrypy/${MODPY_EGG_VERSION}/

MODULES=	lang/python

REGRESS_DEPENDS =	devel/py-nose \
			www/py-routes

MODPY_SETUPTOOLS =	Yes

# test_antistampede requires higher file descriptor limit
# test_cache_control requires higher SECONDS variable
# test_states requires signal handling fixed
REGRESS_IS_INTERACTIVE =Yes

do-regress:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/nosetests -s -v \
		py2/cherrypy/test

.include <bsd.port.mk>

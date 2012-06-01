# $OpenBSD$

COMMENT=		the Git library, take 2

DISTNAME=		libgit2-0.14.0
REVISION=		0
SHARED_LIBS +=  git2                      1.0 # 0.14

MODULES=		devel/cmake

WANTLIB+= z

do-regress:
	cd ${WRKSRC} && ./libgit2_test

.include <bsd.port.mk>

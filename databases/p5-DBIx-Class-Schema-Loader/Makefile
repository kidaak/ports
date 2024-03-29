# $OpenBSD$

COMMENT=	dynamic definition of a DBIx::Class::Schema

MODULES=	cpan
DISTNAME=	DBIx-Class-Schema-Loader-0.07015
CATEGORIES=	databases

MAINTAINER=	Simon Bertrang <simon@openbsd.org>

# Artistic + GPL
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

RUN_DEPENDS=	databases/p5-DBIx-Class \
		databases/p5-DBIx-Class-IntrospectableM2M \
		devel/p5-Class-Unload \
		devel/p5-Data-Dump \
		p5-Universal-exports-<0.05|p5-Universal-require->=0.11:devel/p5-Universal-require \
		textproc/p5-Lingua-EN-Inflect \
		textproc/p5-Lingua-EN-Inflect-Phrase \
		textproc/p5-Lingua-EN-Inflect-Number \
		textproc/p5-Lingua-EN-Tagger \
		textproc/p5-String-ToIdentifier-EN \
		textproc/p5-String-CamelCase

BUILD_DEPENDS=	${RUN_DEPENDS} \
		databases/p5-DBD-SQLite \
		devel/p5-Test-Warn \
		devel/p5-Task-Weaken \
		devel/p5-Try-Tiny
REGRESS_DEPENDS=devel/p5-Config-Any \
		devel/p5-Config-General \
		databases/p5-DBD-SQLite \
		databases/p5-DBI \
		devel/p5-Moose \
		devel/p5-MooseX-MarkAsMethods \
		devel/p5-MooseX-NonMoose \
		devel/p5-Test-Exception \
		devel/p5-Test-Warn \
		devel/p5-namespace-autoclean

MAKE_ENV=	SCHEMA_LOADER_TESTS_BACKCOMPAT=Yes \
		TEST_POD=Yes

TEST_PG ?=	No
.if ${TEST_PG:L:Myes}
MAKE_ENV +=	DBICTEST_PG_DSN='dbi:Pg:dbname=test;host=localhost' \
		DBICTEST_PG_USER=postgres \
		DBICTEST_PG_PASS=
REGRESS_DEPENDS +=	databases/p5-DBD-Pg
.endif

TEST_MYSQL ?=	No
.if ${TEST_MYSQL:L:Myes}
MAKE_ENV +=	DBICTEST_MYSQL_DSN='dbi:mysql:database=test;host=localhost' \
		DBICTEST_MYSQL_USER=root \
		DBICTEST_MYSQL_PASS= \
		DBICTEST_MYSQL_INNODB=1
REGRESS_DEPENDS +=	databases/p5-DBD-mysql
.endif

.include <bsd.port.mk>

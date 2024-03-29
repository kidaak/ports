# $OpenBSD$

COMMENT=	robust and small HTTP server and mail proxy server

DISTNAME=	nginx-${VERSION}
CATEGORIES=	www

MASTER_SITES=	http://nginx.org/download/
MASTER_SITES0=	http://dropbox.eait.uq.edu.au/uqdgwynn/distfiles/

HOMEPAGE=	http://nginx.org/

MAINTAINER=	William Yodlowsky <william@openbsd.org>

# BSD-like
PERMIT_PACKAGE_CDROM=	yes
PERMIT_PACKAGE_FTP=	yes
PERMIT_DISTFILES_CDROM=	yes
PERMIT_DISTFILES_FTP=	yes

WANTLIB=	c crypto pcre ssl z

LIB_DEPENDS+=	devel/pcre

NGINX_DIR=	/var/nginx
SUBST_VARS=	NGINX_DIR

CONFIGURE_STYLE=	simple
CONFIGURE_ARGS=		--prefix=${SYSCONFDIR}/nginx \
			--conf-path=${SYSCONFDIR}/nginx/nginx.conf \
			--sbin-path=${PREFIX}/sbin/nginx \
			--pid-path=/var/run/nginx.pid \
			--lock-path=/var/run/nginx.lock \
			--http-client-body-temp-path=${NGINX_DIR}/tmp/client_body_temp \
			--http-proxy-temp-path=${NGINX_DIR}/tmp/proxy_temp \
			--http-fastcgi-temp-path=${NGINX_DIR}/tmp/fastcgi_temp \
			--http-scgi-temp-path=${NGINX_DIR}/tmp/scgi_temp \
			--http-uwsgi-temp-path=${NGINX_DIR}/tmp/uwsgi_temp \
			--http-log-path=/var/www/logs/access.log \
			--error-log-path=/var/www/logs/error.log \
			--user=www \
			--group=www \
			--with-http_gzip_static_module \
			--with-http_ssl_module \
			--with-http_stub_status_module \
			--with-http_mp4_module \
			--with-http_flv_module \
			--with-http_realip_module \
			--with-mail \
			--with-mail_ssl_module \
			--with-ipv6

FLAVORS=		lua passenger
FLAVOR?=

DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
LUADISTFILES+=		simpl-ngx_devel_kit-v0.2.17-0-gbc97eea.tar.gz:0
LUADISTFILES+=		chaoslawful-lua-nginx-module-v0.6.1-0-ge282c1c.tar.gz:0
SUBSTFILES=		conf/nginx.conf

.if ${FLAVOR:L:Mpassenger}
CONFIGURE_ARGS+=	--add-module=${LOCALBASE}/lib/phusion-passenger19/ext/nginx
BUILD_DEPENDS+=		www/ruby-passenger,-main,ruby19
RUN_DEPENDS+=		ruby-passenger-*|ruby19-passenger-*:www/ruby-passenger,-main
WANTLIB+=		m pthread stdc++
.endif

.if ${FLAVOR:L:Mlua}
CONFIGURE_ARGS+=	--add-module=${WRKSRC}/simpl-ngx_devel_kit
CONFIGURE_ARGS+=	--add-module=${WRKSRC}/chaoslawful-lua-nginx-module
CONFIGURE_ENV+=		MODLUA_INCL_DIR=${MODLUA_INCL_DIR} \
			MODLUA_LIB=${MODLUA_LIB}
MODULES=		lang/lua
WANTLIB+=		${MODLUA_WANTLIB} m
PATCH_LIST=		patch-* lua-*
SUBSTFILES+=		chaoslawful-lua-nginx-module/config
DISTFILES+=		${LUADISTFILES}
.else
SUPDISTFILES+=		${LUADISTFILES}
.endif

NO_REGRESS=		Yes
ALL_TARGET=

.if ${FLAVOR:L:Mlua}
pre-patch:
	cd ${WRKSRC} && \
	    mv ../simpl-ngx_devel_kit-* simpl-ngx_devel_kit && \
	    mv ../chaoslawful-lua-nginx-module-* chaoslawful-lua-nginx-module
.endif

pre-configure:
	@cd ${WRKSRC} && ${SUBST_CMD} ${SUBSTFILES}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/nginx/
	${INSTALL_PROGRAM} ${WRKSRC}/objs/nginx ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/objs/nginx.8 ${PREFIX}/man/man8/
.for i in koi-win koi-utf win-utf mime.types nginx.conf \
	fastcgi_params scgi_params uwsgi_params
	${INSTALL_DATA} ${WRKSRC}/conf/${i} ${PREFIX}/share/nginx/
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/nginx/html/
	${INSTALL_DATA} ${WRKSRC}/html/* ${PREFIX}/share/nginx/html/

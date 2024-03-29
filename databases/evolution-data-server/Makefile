# $OpenBSD$

SHARED_ONLY=		Yes

COMMENT=		unified backend for PIM programs

GNOME_PROJECT=		evolution-data-server
GNOME_VERSION=		3.6.0
REVISION=		0

# Only get the first x.y which is needed in the PLIST.
R=			${GNOME_VERSION:C/^([0-9]+\.[0-9]+).*/\1/}
SUBST_VARS=		R

CATEGORIES=		databases productivity

SHARED_LIBS +=  camel-1.2            34.0     # 40.0
SHARED_LIBS +=  edataserver-1.2      17.0     # 17.0
SHARED_LIBS +=  ebackend-1.2         3.0      # 5.0
SHARED_LIBS +=  ebook-1.2            17.0     # 17.1
SHARED_LIBS +=  edata-book-1.2       14.0     # 15.0
SHARED_LIBS +=  ecal-1.2             14.0     # 15.0
SHARED_LIBS +=  edata-cal-1.2        16.0     # 18.0
SHARED_LIBS +=  edataserverui-3.0    2.0      # 4.0

HOMEPAGE=	http://www.gnome.org/projects/evolution/

MAINTAINER=	Jasper Lievisse Adriaanse <jasper@openbsd.org>, \
		Antoine Jacoutot <ajacoutot@openbsd.org>

# LGPLv2
PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

WANTLIB += GL ICE SM X11 Xau Xcomposite Xcursor Xdamage Xdmcp
WANTLIB += Xext Xfixes Xi Xinerama Xrandr Xrender Xxf86vm asn1
WANTLIB += atk-1.0 atk-bridge-2.0 atspi c cairo cairo-gobject
WANTLIB += com_err crypto curl db dbus-1 drm expat ffi fontconfig
WANTLIB += freetype gck-1 gcr-base-3 gcrypt gdata gdk-3 gdk_pixbuf-2.0
WANTLIB += gio-2.0 glib-2.0 gmodule-2.0 gnome-keyring goa-1.0
WANTLIB += gobject-2.0 gpg-error gssapi gthread-2.0 gtk-3 gweather-3
WANTLIB += harfbuzz ical icalss icalvcal icudata icule icuuc idn
WANTLIB += krb5 lber-2.4 ldap-2.4 m nspr4 nss3 nssutil3 oauth
WANTLIB += p11-kit pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre
WANTLIB += pixman-1 plc4 plds4 png pthread pthread-stubs sasl2
WANTLIB += smime3 softokn3 soup-2.4 soup-gnome-2.4 sqlite3 ssl
WANTLIB += ssl3 stdc++ xcb xcb-render xcb-shm xml2 z

MODULES=		devel/gettext \
			devel/dconf \
			lang/python \
			x11/gnome

BUILD_DEPENDS=		devel/bison \
			devel/gperf
LIB_DEPENDS= 		databases/db/v4 \
			databases/openldap \
			net/liboauth \
			textproc/libical \
			x11/gnome/gcr>=3.6.0 \
			x11/gnome/libgweather \
			devel/libgdata>=0.10.1 \
			x11/gnome/online-accounts

YACC=			bison

MODPY_RUNDEP=		No
MODPY_ADJ_FILES=	addressbook/libebook/gen-western-table.py

AUTOCONF_VERSION=	2.68
AUTOMAKE_VERSION=	1.10

MODGNOME_TOOLS= 	goi vala

CONFIGURE_STYLE= 	autoconf
CONFIGURE_ARGS=		--enable-ssl \
			--enable-smime \
			--enable-ipv6 \
			--enable-weather \
			--enable-nntp \
			--with-krb5 \
			--with-krb5-libs=/usr/lib \
			--with-krb5-includes=/usr/include/kerberosV \
			--with-libdb=${LOCALBASE} \
			--with-openldap=${LOCALBASE}
MODGNOME_CPPFLAGS=	-I${LOCALBASE}/include/db4
MODGNOME_LDFLAGS=	-pthread

post-install:
	rm ${PREFIX}/lib/evolution-data-server/*/*.{a,la}

.include <bsd.port.mk>

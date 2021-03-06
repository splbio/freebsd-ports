# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	libgphoto2
PORTVERSION=	2.5.10
CATEGORIES=	graphics
MASTER_SITES=	SF/gphoto/libgphoto/${PORTVERSION}

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Universal digital camera control library

LICENSE=	LGPL21

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		gmake iconv libtool pkgconfig tar:bzip2
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LTDLINCL="-I${LOCALBASE}/include" \
		LIBLTDL="-L${LOCALBASE}/lib -lltdl" \
		PATH="${PATH:C,${HOME}/bin,,}" \
		ac_cv_path_DOT=false \
		ac_cv_path_DOXYGEN=false \
		udevscriptdir=${WRKDIR}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="${PORTVERSION}" VERSION_PORT=0.12.0

OPTIONS_DEFINE=		DOCS GD JPEG LIBEXIF NLS XML
OPTIONS_DEFAULT=	GD JPEG LIBEXIF XML
OPTIONS_SUB=		yes

GD_LIB_DEPENDS=		libgd.so:graphics/gd
GD_CONFIGURE_OFF=	--with-gdlib=no
JPEG_USES=		jpeg
JPEG_CONFIGURE_WITH=	jpeg
LIBEXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
LIBEXIF_CONFIGURE_OFF=	--with-libexif=no
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
XML_USE=		GNOME=libxml2
XML_CONFIGURE_OFF=	--with-libxml-2.0=no

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000040
CONFIGURE_ENV+=	LIBUSB1_CFLAGS=" " LIBUSB1_LIBS="-lusb"
.endif

post-patch:
.for i in configure libgphoto2_port/configure
	@${REINPLACE_CMD} -e \
		'/FLAGS/s|-g|| ; \
		 /grep -i linux/s|; fi ; then|; else false; fi ; then| ; \
		 /pkgconfig/s|$${libdir}|$${prefix}/libdata|' \
		${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e \
		'/^doc_DATA/s|COPYING||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-lusb-1.0|-lusb|' \
		${WRKSRC}/libgphoto2_port/configure
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|linux-hotplug||' \
		${WRKSRC}/packaging/Makefile.in

.include <bsd.port.mk>

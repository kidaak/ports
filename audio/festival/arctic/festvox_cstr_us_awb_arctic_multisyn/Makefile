# $OpenBSD$

COMMENT=	Scottish English male speaker (AWB), cstr
DISTNAME=	festvox_cstr_us_awb_arctic_multisyn-1.0
PKGNAME=	${DISTNAME}
REVISION=	1
DIST_SUBDIR=	festival

RUN_DEPENDS=	${ARCTIC_US_DEPS}

do-install:
	${INSTALL_DATA_DIR} ${ARC_PRE}-multisyn/english/cstr_us_awb_arctic_multisyn/festvox
	${INSTALL_DATA_DIR} ${ARC_PRE}-multisyn/english/cstr_us_awb_arctic_multisyn/awb/coef
	${INSTALL_DATA_DIR} ${ARC_PRE}-multisyn/english/cstr_us_awb_arctic_multisyn/awb/lpc
	${INSTALL_DATA_DIR} ${ARC_PRE}-multisyn/english/cstr_us_awb_arctic_multisyn/awb/utt
	${INSTALL_DATA} ${ARC_WRK}-multisyn/english/cstr_us_awb_arctic_multisyn/festvox/* \
		${ARC_PRE}-multisyn/english/cstr_us_awb_arctic_multisyn/festvox
	${INSTALL_DATA} ${ARC_WRK}-multisyn/english/cstr_us_awb_arctic_multisyn/awb/utts.* \
		${ARC_PRE}-multisyn/english/cstr_us_awb_arctic_multisyn/awb
	${INSTALL_DATA} ${ARC_WRK}-multisyn/english/cstr_us_awb_arctic_multisyn/awb/coef/* \
		${ARC_PRE}-multisyn/english/cstr_us_awb_arctic_multisyn/awb/coef
	${INSTALL_DATA} ${ARC_WRK}-multisyn/english/cstr_us_awb_arctic_multisyn/awb/lpc/*.res \
		${ARC_PRE}-multisyn/english/cstr_us_awb_arctic_multisyn/awb/lpc
	${INSTALL_DATA} ${ARC_WRK}-multisyn/english/cstr_us_awb_arctic_multisyn/awb/lpc/*.lpc \
		${ARC_PRE}-multisyn/english/cstr_us_awb_arctic_multisyn/awb/lpc
	${INSTALL_DATA} ${ARC_WRK}-multisyn/english/cstr_us_awb_arctic_multisyn/awb/utt/* \
		${ARC_PRE}-multisyn/english/cstr_us_awb_arctic_multisyn/awb/utt

.include <bsd.port.mk>

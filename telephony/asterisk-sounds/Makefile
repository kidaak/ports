# $OpenBSD$

    SUBDIR =
    SUBDIR += core-sounds
    SUBDIR += extra-sounds
.for i in gsm alaw ulaw g722 sln16 wav # g729 siren7 siren14
    SUBDIR += moh-opsound,$i
.endfor

.include <bsd.port.subdir.mk>

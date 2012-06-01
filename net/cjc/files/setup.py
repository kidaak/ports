# $OpenBSD$

from distutils.core import setup

setup(
        name = "Console Jabber Client",
        version = "1.0.1",
        description = "Jabber/XMPP client for text terminals",
        author = "Jacek Konieczny",
        author_email = "jajcus@bnet.pl",
        license = "GPL",
        url = "http://jabberstudio.org/projects/cjc",
        packages = ('cjc', 'cjc.ui'),
)

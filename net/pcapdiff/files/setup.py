# $OpenBSD$

from distutils.core import setup
import sys, os

setup(
        name = "pcapdiff",
        version = "0.1",
        description = "packet capture comparison tool",
        author = "Electronic Frontier Foundation",
        license = "GPL",
        packages = [''],
        packagedata = {'pcapdiff' : "pcapdiff_helper.py"},
        url = "http://www.eff.org/testyourisp/pcapdiff/",
        scripts = ('pcapdiff.py','printpackets.py',)
)

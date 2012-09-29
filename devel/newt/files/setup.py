# $OpenBSD$

import os
from distutils.core import setup, Extension

setup ( name = 'newt',
	version = '${VERSION}',
	description = 'Python interface to Newt module',
	py_modules = ['snack'],
	ext_modules = [ Extension(
		name='_snack',
		sources=['snackmodule.c'],
		include_dirs=['.', '${LOCALBASE}'+'/include', '${TRUEPREFIX}'+'/include'],
		library_dirs=['.', '${LOCALBASE}'+'/lib', '${TRUEPREFIX}'+'/lib'],
		libraries=['newt', 'popt', 'slang', 'ncurses']
	)])

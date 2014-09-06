#!/bin/sh

#touch NEWS README AUTHORS Changelog
#aclocal
#automake --add-missing
#autoconf
#autoreconf

LDFLAGS=-L/opt/local/lib \
CPPFLAGS=-I/opt/local/include \
	./configure \
		--prefix=/usr/local/hplip \
		--enable-scan-build=no \
		--enable-fax-build=no \
		--enable-dbus-build=no \
		--enable-gui-build=no

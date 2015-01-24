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
		--enable-gui-build=no \
		--enable-hpijs-install=no \
		--enable-pp-build=no \
		--enable-cups11-build=no \
		--enable-foomatic-ppd-install=no \
		--enable-foomatic-drv-install=no \
		--enable-foomatic-rip-hplip-install=no \
		--enable-qt4=no \
		--enable-policykit=no \
		--enable-hpcups-only-build=yes \
		--enable-cups-ppd-install=no \
		--enable-cups-drv-install=yes \
		--enable-hpcups-install=yes \
		--with-cupsfilterdir=/usr/libexec/cups/filter \
		--with-cupsbackenddir=/usr/libexec/cups/backend \
		--with-drvdir=/usr/share/cups/drv 

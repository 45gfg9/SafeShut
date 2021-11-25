SUBDIRS = include src

ACLOCAL_AMFLAGS = -I m4
AM_LDFLAGS = -shared -O3

clean-local:
	@rm -r autom4te.cache m4
	@rm configure config.log config.status
	@rm src/Makefile.in src/Makefile
	@rm include/Makefile.in include/Makefile
	@rm libtool
	@rm aclocal.m4 Makefile

# Copyright (C) 2000 John Kassebaum <jak@kassebaum.net>
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

#AUTOMAKE_OPTIONS = 

lib_LTLIBRARIES = libMP.la
libMP_la_SOURCES = MP_Int.cc MP_Ratio.cc MP_Float.cc

bin_PROGRAMS = bisnet
bisnet_SOURCES = main.cc BisNet.cc 
bisnet_LDADD = -L/usr/local/lib -lgmp ./libMP.la


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

lib_LTLIBRARIES = libdataset.la libbis.la
lib_LIBRARIES = libdataset.a libbis.a

libdataset_la_SOURCES = DataSet.cc DataSet.h DataSet.inl

libdataset_a_SOURCES = DataSet.cc DataSet.h DataSet.inl

libbis_la_SOURCES = BisNet.cc BisNet.h BisNet.inl \
    BisTree.cc BisTree.h BisTree.inl  \
	BitInterleavedSort.cc BitInterleavedSort.h BitInterleavedSort.inl

libbis_a_SOURCES = BisNet.cc BisNet.h BisNet.inl \
    BisTree.cc BisTree.h BisTree.inl  \
	BitInterleavedSort.cc BitInterleavedSort.h BitInterleavedSort.inl

include_HEADERS =  DataSet.h DataSet.inl BisNet.h BisNet.inl BisTree.h BisTree.inl \
    BitInterleavedSort.h BitInterleavedSort.inl

bin_PROGRAMS = bisnet
bisnet_SOURCES = main.cc 
bisnet_LDADD = -L/usr/local/lib -lgmp -lgmp_pp -L. -ldataset -lbis


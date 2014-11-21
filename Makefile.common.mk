AM_CXXFLAGS = -stdlib=libc++ -std=c++11
AM_CXXFLAGS += -Wall -Wextra
AM_CXXFLAGS += $(APERTIUM_XML2CPP_CFLAGS)
AM_CXXFLAGS += -I$(abs_top_srcdir)/src/include
AM_LDFLAGS = $(APERTIUM_XML2CPP_LIBS)

#
# Copyright (C) 2013 TeYen Liu
#

TREMA = ../../../trema

CC = gcc
CXX = g++
AR = ar
RANLIB = ranlib

TREMA_CONFIG = $(shell which trema-config)
ifeq ($(TREMA_CONFIG),)
  TREMA_CONFIG = $(TREMA)/trema-config
endif

CFLAGS = $(shell $(TREMA_CONFIG) --cflags) -D_GNU_SOURCE -g -fno-strict-aliasing -Wall -Wextra -Wformat=2 -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wfloat-equal -Wpointer-arith -I. -I.. -I../libs
LDFLAGS = -L/var/lib/gems/1.8/gems/trema-0.3.20/objects/lib -lstdc++ -ljansson -ltrema -lrt -lpthread -lsqlite3 -L.. -ltrema_restapi_manager #$(shell $(TREMA_CONFIG) --libs)

TARGET = ticker
SRCS = ticker.c cJSON.c 
TSRCS = trader.cpp traderproxy.cpp
OBJS = $(SRCS:.c=.o) $(TSRCS:.cpp=.o) thosttraderapi.so

DEPENDS = .depends

.PHONY: all clean

.SUFFIXES: .c .cpp .o

all: depend $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) -c $<
.c.o:
	$(CC) $(CFLAGS) -c $<
tick:
	$(CC) $(CFLAGS) -Wunused-parameter $(LDFLAGS) $(SRCS) $(TSRCS) thosttraderapi.so -o ticker
depend:
	$(CC) -MM $(CFLAGS) $(SRCS) > $(DEPENDS)

clean:
	@rm -rf $(DEPENDS) $(OBJS) $(TARGET) *~

-include $(DEPENDS)

srcdir = .
VPATH = $(srcdir)

PREFIX = /usr/local

cflags = -Wall -pedantic $(CFLAGS)
cppflags = $(CPPFLAGS) #-DDEBUG -DDEBUG_EV -DSHAPE
ldlibs = -lXext -lX11

objs = client.o color.o cursor.o error.o event.o grab.o key.o main.o manage.o menu.o

all: rio xshove

.PHONY: all clean install uninstall
.SUFFIXES:
.SUFFIXES: .c .o
$(V).SILENT:

rio: $(objs)
	@echo "LINK $@"
	$(CC) $(LDFLAGS) -o $@ $(objs) $(ldlibs)

$(objs): Makefile dat.h fns.h

.c.o:
	@echo "CC $@"
	$(CC) $(cflags) $(cppflags) -c -o $@ $<

xevents: Makefile printevent.o xevents.o
	@echo "LINK $@"
	$(CC) $(LDFLAGS) -o $@ printevent.o xevents.o $(ldlibs)
	
xshove: Makefile xshove.o
	@echo "LINK $@"
	$(CC) $(LDFLAGS) -o $@ xshove.o $(ldlibs)

clean:
	rm -f *.o rio xevents xshove

install: all
	@echo "INSTALL bin/rio"
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp rio $(DESTDIR)$(PREFIX)/bin/
	chmod 755 $(DESTDIR)$(PREFIX)/bin/rio
	@echo "INSTALL bin/xshove"
	cp xshove $(DESTDIR)$(PREFIX)/bin/
	chmod 755 $(DESTDIR)$(PREFIX)/bin/xshove

uninstall:
	@echo "REMOVE bin/rio"
	rm -f $(DESTDIR)$(PREFIX)/bin/rio
	@echo "REMOVE bin/xshove"
	rm -f $(DESTDIR)$(PREFIX)/bin/xshove


CC=gcc
CFLAGS= `pkg-config --cflags --libs glib-2.0`


dist: dist.c
	$(CC) -g -Wall dist.c splay.c $(CFLAGS) -o dist

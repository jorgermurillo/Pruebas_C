CC=gcc
CFLAGS= `pkg-config --cflags --libs glib-2.0`

shift_hash: shift_hash.c murmurhash3.c
	$(CC) -g -Wall shift_hash.c murmurhash3.c $(CFLAGS) -o shift_hash 
	 
SHARDS_fixed_rate: SHARDS_fixed_rate.c murmurhash3.c
	$(CC) -g  -Wall SHARDS_fixed_rate.c splay.c murmurhash3.c $(CFLAGS) -o SHARDS_fixed_rate 

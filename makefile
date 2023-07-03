.PHONY = cbuild,rsearch,rqueue,rstack,rstring

cbuild:
	cmake --build ./build

rsearch:
	./build/search

rqueue:
	./build/queue

rstack:
	./build/stack

rstring:
	./build/string

rqsort:
	./build/qsort

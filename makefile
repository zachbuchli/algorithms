.PHONY = cbuild,rsearch,rqueue,rstack

cbuild:
	cmake --build ./build

rsearch:
	./build/search

rqueue:
	./build/queue

rstack:
	./build/stack

.PHONY = cbuild, run, rqueue,rstack

cbuild:
	cmake --build ./build

run-main:
	./build/main

rqueue:
	./build/queue

rstack:
	./build/stack

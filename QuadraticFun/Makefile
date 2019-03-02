# linux
release: QFun
	./QFun	
	
QFun: main.o QFun.o
	g++ main.o QFun.o -o QFun

main.o: main.cpp QFun.h
	g++ -c -Wall -pedantic main.cpp

QFun.o: QFun.cpp QFun.h
	g++ -c -Wall -pedantic QFun.cpp

clear:
	rm -rf *o QFun
	rm -rf *o QFunDebug

debug: QFunDebug
	gdb QFunDebug

QFunDebug: main.cpp QFun.cpp QFun.h
	g++ -g main.cpp QFun.cpp QFun.h -o QFunDebug
	






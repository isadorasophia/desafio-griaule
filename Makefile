

desafio-griaule: desafio.o util.o
	g++ -g -o desafio-griaule desafio.o util.o -lbin/linux -LGBSFingerprint

desafio.o: src/desafio.cpp inc/util.h inc/3rd/tinydir.h inc/3rd/GBSFingerprint.h
	g++ -Iinc/ -c src/desafio.cpp

util.o: src/util.cpp inc/util.h inc/3rd/tinydir.h inc/3rd/GBSFingerprint.h
	g++ -Iinc/ -c src/util.cpp
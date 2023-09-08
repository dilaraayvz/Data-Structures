all: derle bagla calistir
derle:
	g++  -c -I "./include" ./src/Node.cpp -o ./lib/Node.o
	g++  -c -I "./include" ./src/LinkedList.cpp -o ./lib/LinkedList.o
	g++  -c -I "./include" ./src/BaseNode.cpp -o ./lib/BaseNode.o
	g++  -c -I "./include" ./src/BaseList.cpp -o ./lib/BaseList.o
	g++  -c -I "./include" ./src/FileOperator.cpp -o ./lib/FileOperator.o
	g++  -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/Node.o ./lib/LinkedList.o ./lib/BaseNode.o ./lib/BaseList.o ./lib/FileOperator.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program
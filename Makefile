all: typing-assistant

typing-assistant: main.o Dentro.o Treenode.o
	g++ main.o Dentro.o Treenode.o -o typing-assistant

main.o: main.cpp
	g++ -c main.cpp

Trie.o: Trie.cpp
	g++ -c Treenode.cpp

Node.o: Node.cpp
	g++ -c Node.cpp

clean:
	rm -rf *o typing-assistant

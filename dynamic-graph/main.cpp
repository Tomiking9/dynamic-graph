#include <iostream>
#include "graph.cpp"

int main(int argc, const char* argv[]) {

	Node* n1 = new Node(0);
	Node* n2 = new Node(1);
	Node* n3 = new Node(2);
	Node* n4 = new Node(3);

	Edge* e1 = new Edge(n1, n2);
	Edge* e2 = new Edge(n3, n4);
	Edge* e3 = new Edge(n1, n3);
	Edge* e4 = new Edge(n1, n4);

    vector<Edge*> edges = {e1, e2, e3, e4};

    Graph graph(4, edges);

    printGraph(graph);
	graph.set_friend(n1);
	n1->friends->print();
	
    return 0;
}

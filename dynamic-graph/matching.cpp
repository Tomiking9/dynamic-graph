#include <map>
#include <set>
#include "node.cpp"

class Matching{
public:
	std::set<Edge*> matching;
	
	Node* mate(Node* node) {
		for (Edge* edge : matching){
			if (edge->src == node) { return edge->dest; }
			if (edge->dest == node) { return edge->src; }
		}
		return nullptr;
	}
};
#include <map>
#include <set>
#include <vector>
#include <iterator>
#include <string>
#include <iostream>
#include <algorithm>
#include "matching.cpp"
using namespace std;
 
struct comp{
    bool operator()(const Node* lhs, const Node* rhs) const{
        if (lhs->key == rhs->key){
            return lhs->key > rhs->key;
        }
        return lhs->key < rhs->key;
    }
};

class Graph{
public:
    int n;
    map<Node*, set<Node*>, comp> graph;
    Matching matching;
    
    Graph(int n, vector<Edge*> const &edges){
        this->n = n;

        for (int i = 0; i < edges.size(); i++){
            graph[edges[i]->src].insert(edges[i]->dest);
            graph[edges[i]->dest].insert(edges[i]->src);                 // undirected
        }
    }


    void set_friend(Node* node){
        set<Node*>::const_iterator it;
        node->friends = new Friend(this->n);

        // set current_free_neighbors
        int i = 0;
        for (const auto &pair : this->graph) {
            // if connected -> current neighbor
            if (graph[node].count(pair.first) == 0){
                node->friends->current_free_neighbors[i] = false;
                i++;
                continue;
            }
            // if not mates -> free
            if (matching.mate(node) != pair.first){
                node->friends->current_free_neighbors[i] = true;
            }
            i++;
        }

        // set counter array
        int counter = 0;
        for (int i = 0; i < this->n; i+=(int)sqrt(n)){
            int temp = 0;
            for (int j = i; j < i + (int)sqrt(this->n); j++){
                temp += node->friends->current_free_neighbors[j];
            }
            node->friends->counter_array[counter] = temp;
            counter++;
        }

        // set total friends
        for (int i = 0; i < n; i++){
            node->friends->total_free_neigbors += (node->friends->current_free_neighbors[i] == 1 ? 1 : 0);  // fix clean code
        }
    }
};


string set_to_string(set<Node*> nodes){
    string res = "";
    for (Node* node : nodes){
        res += to_string(node->key) += " ";
    }
    return res;
}

void printGraph(Graph const &graph){
    map<Node*, set<Node*>>::const_iterator it = graph.graph.begin();
     

    while (it != graph.graph.end()){                     // nice naming dumbass
        Node* node = it->first;                          // key
        set<Node*> adjacent_nodes = it->second;          // value

        cout << node->key << " connected to: " << set_to_string(adjacent_nodes) << endl;
        it++;
    }
}
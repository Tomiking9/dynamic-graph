#include <cmath>
#include <vector>
class Friend;

class Node {
public:
	int key;
    int degree;
    Friend* friends;


    Node(){}
    Node(int key){
        this->key = key;
    }

};

struct Edge{
    Node* src;
    Node* dest;

    Edge(Node* src, Node* dest){
        this->src = src;
        this->dest = dest;
    }
};

class Friend{
public:
    int n;
    bool* current_free_neighbors;       // size n
    int* counter_array;                // size sqrt(n)
    int total_free_neigbors;

    Friend(int n) {
        this->n = n;
        this->current_free_neighbors = new bool[n];
        this->counter_array = new int[(int)(sqrt(n))];
        memset(current_free_neighbors, 0, sizeof(int*));
        memset(counter_array, 0, sizeof(int*));
    }

    Node* get_free(Node* node) {return nullptr;}
    bool has_free(Node* node) {return true;}


    void print(){
        for (int i = 0; i < n; i++){
            std::cout << current_free_neighbors[i] << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < (int)sqrt(n); i++){
            std::cout << counter_array[i] << " ";
        }
        std::cout << std::endl;
        std::cout << total_free_neigbors;
    }
};
#ifndef NODE_H
#define NODE_H

using namespace std;

template <class T>
class Node {
public:
    int x, y;
    T data; 
    Node* next;
    Node* down;
public:
	Node(){
		next=nullptr;
		down=nullptr;

	};

	Node(int pos){
		x=pos;
		next=nullptr;
		down=nullptr;
		//data=0;
	};

	
	Node(Node* next,Node* down, int x,int y,T data){
		this->x=x;
		this->y=y;
		this->next=next;
		this->down=down;
		this->data=data;
	};
};

#endif
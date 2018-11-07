#ifndef NODE_H
#define NODE_H

using namespace std;

template <class T>
class Node {
    int x, y;
    T data; 
    Node* next;
    Node* down;
public:
	Node(int cant, int pos){

		if (cant<0)
		{
			x=pos;
			--cant;
			++pos;
			this.next-> new Node<T>(cant,pos);
		}

	}
	Node(int cant, int pos, bool r){

		if (cant<0)
		{
			y=pos;
			--cant;
			++pos;
			this.down-> new Node<T>(cant,pos,r);
		}

	}
};

#endif
#include <iostream>
using namespace std;

class Node {
    public:
        int m_data;
        Node *m_next;
};

class LinkedList {
    public:
        int len;
        Node *head;

        // methods
        void push(int data) {
            Node *node = new Node();
            node->m_data = data;
            node->m_next = this->head;
            this->head = node;
            this->len++;
        }


		void append(int data) {
			Node *node = new Node();
			node->m_data = data;

			if (this->head == NULL) {
				node->m_next = head;
				head = node;
			} else {
				Node *tmp = head;
				while (tmp->m_next != NULL) {
					tmp = tmp->m_next;
				}
				tmp->m_next = node;
			}
		}

		void reverse() {
			Node *prev = NULL;
			Node *current = this->head;
			Node *next = NULL;

			while (current != NULL) {
				// store next
				next = current->m_next;
				// reverse current node's pointer
				current->m_next = prev;
				// move pointers one position ahead
				prev = current;
				current = next;
			}
			this->head = prev;
		}

		void insert_after(int data, int insert_after)
		{

			Node *node = new Node();
			node->m_data = data;

			Node *tmp = this->head;

			while (tmp != NULL) {
				if (tmp->m_data == insert_after) {
					node->m_next = tmp->m_next;
					tmp->m_next = node;
				}
				tmp = tmp->m_next;
			}
		}


        void print() {
            Node *head = this->head;
            int i = 1;
            while (head) {
                std::cout << i << ": " << head->m_data << std::endl;
                head = head->m_next;
                i++;
            }
        }

};


int main()
{
    LinkedList *list = new LinkedList();
    
	list->push(3);
	list->push(2);
	list->push(1);
	list->append(7);
    
    list->print();

	cout << "reverse list" << endl;

	list->reverse();
	list->print(); 

	cout << "insert 10 after 2" << endl;
	list->insert_after(10, 2);

	list->print(); 

	delete list;

	return 0;
}


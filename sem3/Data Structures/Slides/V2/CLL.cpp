#include<iostream>
using namespace std;

// Circular Linked List with dummy head + tail
class CircularLinkedList {
private:
    node* head; // dummy head
    node* tail; // last node pointer
int size;
public:
    CircularLinkedList() {
        head = new node();  // dummy head
        head->setNext(head);  // initially points to itself
        tail = head;        // tail = head in empty list
    size=0;
	}

    // Insert at end
    void insertAtTail(int value) {
        node* newNode = new node(value);
        newNode->nextNext(head);   // new node points to dummy head
        tail->setNext(newNode);   // old tail points to new node
        tail = newNode;         // new node becomes tail
     size++;
	}

    // Insert at beginning (after dummy head)
    void insertAtHead(int value) {
        node* newNode = new node(value);
        newNode->setNext(head->getNext());
        head->setNext(newNode);
        if (tail == head) { 
            tail = newNode;
            //tail->setNext(head);
        } size++;
    }
void insertInOrder(int value)
{
	if(size==0)
	{insertAtHead(value);
	}else if(value<=(head->getNext())->get())
	{insertAtHead(value);
	}else if(value>=tail->get())
	{insertAtTail(value);
	}else
	{
		Node<T> *newNode=new Node<T>(value,NULL);
		Node<T> *current=head->getNext();
		Node<T> *prev=head;
		while(current!=head&& value>=current->get())
		{prev=current;
		current=current->getNext();
		}
		prev->setNext(newNode);
		newNode->setNext(current);
size++;		
	}
void removeAtHead()
{if(size=0)
return;
node *temp=head->getNext();
head->setNext(temp->getNext());
if(tail==temp) tail=head;
delete temp;
size--;
}
void removeAtTail()
{if(size==0) return;
node* temp=head;
while(temp->getNext()!=tail)
  temp=temp->getNext();
  delete tail;
  tail=temp;
  tail->setNext(head);
  size--;
}
    // Delete a node
    void removeNode(int value) {
        if (size==0) {
            cout << "List is empty!" << endl;
            return;
        }

        node* curr = head->getNext();
        node* prev = head;

        while (curr != head) {
            if (curr->data == value) {
                prev->setNext(curr->getNext());
                if (curr == tail) { // deleting tail
                    tail = prev;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->getNext();
        }
        }

   
    // Find node
    bool find(int value) {
        Node* temp = head->getNext();
        while (temp != head) {
            if (temp->get() == value) return true;
            temp = temp->getNext();
        }
        return false;
    }
};

// Main function
int main()
{



return 0;}
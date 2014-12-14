#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Node {
private:
	int value;
	Node *next;
public:
    Node(){
        value = 0;
        next = NULL;
    }

    Node(int value){
        this->value = value;
        next = NULL;
    }
    Node(Node *next){
        this->next = next;
        value = 0;
    }
    Node(int value, Node *next){
        this->value = value;
        this->next = next;
    }

    int getValue(){
        return value;
    }
    Node* getNext(){
        return next;
    }

    void setValue(int value){
        this->value = value;
    }
    void setNext(Node *next){
        this->next = next;
    }
};


class LinkedList {
private:
	Node *head; //declares a Node pointer head on stack
	Node *tail; //declares a Node pointer tail on stack
    int length;
public:

    LinkedList(){
        head = NULL;
        tail = NULL;
        length = 0;
    }
    /**
        initializes the list to an empty list.
        In an empty list the length should be 0 and the head should point to NULL.
    */
    void init_list(){
        if(is_list_empty()){
            return;
        }
        Node *temp = head->getNext();
        while(temp!=NULL){ // to delete all the nodes in the linked list to prevent the memory leak
            delete head;
            head = temp;
            temp = temp->getNext();
        }
        delete head;
        length = 0;
        head = NULL;
        tail = NULL;
    }
    /**
        will return 'true' if the list is empty and 'false' otherwise.
    */
    bool is_list_empty(){
        if(length == 0){
            return true;
        }
        else{return false;}
    }
    /**
        return a pointer to the first node in the list which contains the search item
        if it is present in the list. Else return NULL.
    */
    //bug proofed
    Node* search(int value){
        Node *temp = head;
        while(temp!=NULL){
            if(temp->getValue()== value){
                return temp;
            }
            temp = temp->getNext();
        }
        return NULL;
    }
    /**
        remove the first instance of the item from the list
        if the item is present in the list at least once,
        and return the item that is removed from the list.
        If the item is not present in the list, it should return NULL.
    */
// bug proofed
    int deleteNode(int value){
        if(length == 0){
          return 0;
        }
        if(length == 1 && head->getValue()!=value){
            return 0;
        }

        if(head->getValue()== value){
            Node *about_to_delete = head;
            head = head->getNext();
            delete about_to_delete;
            return value;
        }

        Node *temp1 = head;
        Node *temp2 = head->getNext();
        while(temp2!=NULL){
            if(temp2->getValue()== value){
                if(temp2->getNext()==NULL){
                    tail=temp1;
                }//////////////////////////////////////////////////////////////paused !!!
                temp1->setNext(temp2->getNext());
                delete temp2; // avoid memory leak
                length--;
                return value;
            }
            temp1=temp1->getNext();
            temp2=temp2->getNext();
        }
        return 0;
    }
    /**
        remove the item in the i th location of the list and return the item that is removed from the list.
        If the specified position is higher than the actual amount of items in the list,
        it should return NULL. The location indices start from 1.
    */
    // bug proofed
    int deleteat(int i){
        if(i == 0 || length < i){
            cout << "No such location in the list!!!"<<endl;
            return 0;
        }

        Node *temp1 = head;
        Node *temp2 = head->getNext();
        int temp;
        if(i == 1){
            temp = head->getValue();
            head = temp2;
            delete temp1;
            length--;
            return temp;
        }
        for(int n =2; n<i; n++){
            temp1=(temp1->getNext());
            temp2=(temp2->getNext());
        }
        temp = temp2->getValue();
        if(temp2->getNext() == NULL){
            tail=temp1;
        }
        temp1->setNext(temp2->getNext());
        delete temp2;
        length--;
        return temp;
    }
    /**
        Place element at the end of the list and return whether insert was successful or not
    */
    // bug proofed
    void insert(int value){
        Node *temp = new Node(value);
        if(length == 0){
            tail=temp;
            head=temp;
        }
        else{
            tail->setNext(temp);
            tail=temp;
        }
        length++;

    }

    /**
        place element to the i th location of the list and return whether insert was successful or not.
        If the specified location i is higher than actual number of elements in the list,
        the item will be added to the end of the list.
    */
    // bug proofed
    bool insertat(int value, int i){
        if(i == 0){
            cout << "Invalid position"<< endl;
            return false;
        }
        if(i>length){
            insert(value);
            length++;
            return true;
        }
        if(i == 1){
            Node *temp = new Node(value, head);
            head = temp;
            length++;
            return true;
        }
        Node *temp1 = head;
        Node *temp2 = new Node(value,head->getNext());
        for(int n = 2; n<i; n++){
            temp1=temp1->getNext();
            temp2=temp2->getNext();
        }
        head->setNext(temp2);
        length++;
        return true;
    }
    /**
        Return the number of elements in the list
    */
    int list_length(){
        return length;
    }
};

class Stack{
private:
    LinkedList *values;
public:
    Stack(){
        values = new LinkedList();
    }
    void init_stack(){
        values->init_list();
    }
    bool is_stack_empty(){
        if(values->is_list_empty()){
            return true;
        }
        return false;
    }
    void push(int val){
        values->insertat(val,1);
    }
    int pop(){
        if(values->is_list_empty()){
            cout << "Stack is empty"<<endl;
            return 0;
        }
        return values->deleteat(1);
    }
    int peek(){
        int j;
        if(values->is_list_empty()){
            cout << "Stack is empty"<<endl;
            return 0;
        }
        j = pop();
        push(j);
        return j;

    }

};

class Queue{
private:
    LinkedList *values;
public:
    Queue(){
        values = new LinkedList();
    }
    void init_queue(){
        values->init_list();
    }
    bool is_queue_empty(){
        if(values->is_list_empty()){
            return true;
        }
        return false;
    }
    void enqueue(int val){
        values->insert(val);
    }
    int dequeue(){
        if(values->is_list_empty()){
            cout << "Queue is empty"<<endl;
            return 0;
        }
        return values->deleteat(1);
    }
    int peek(){
        int j;
        if(values->is_list_empty()){
            cout << "Queue is empty"<<endl;
            return 0;
        }
        j = dequeue();
        values->insertat(j,1);
        return j;

    }
    int search_queue(int i){
        if(values->search(i)){ // this could be NULL
            return values->search(i)->getValue();
        }
        cout << "item isn't in the queue" << endl;
        return 0;
    }

};

int main(int argc, char* argv[]){

    Stack s;
	Queue q;
	cout << "************ Demo of the stack *****************"<<endl << "pushing 1,2,3,4,5 in to the stack (in this order)" << endl;
	for(int i = 1; i<=5; i++){
        s.push(i);
	}
	cout << "pushed successfully."<< endl <<"now popping back" <<endl;
	for(int i = 1; i<=5; i++){
        cout << s.pop()<< endl;
	}

    cout <<endl<< "************ Demo of the Queue *****************"<<endl << "enqueueying 1,2,3,4,5 in to the queue (in this order)" << endl;
	for(int i = 1; i<=5; i++){
        q.enqueue(i);
	}
	cout << "Enqueued successfully."<< endl <<"now dequeueying back" <<endl;
	for(int i = 1; i<=5; i++){
        cout << q.dequeue()<< endl;
	}
	return 0;
}

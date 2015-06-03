#include <iostream>
#include <string>

using namespace std;

class LinkedList
{
public:

    struct Node
    {
        Node()
        {
            data = "";
            next = 0;
        }
        Node(string data)
        {
            this->data = data;
            next = 0;
        }

        string data;
        Node* next;
    };

    Node* start;
    Node* end;

    LinkedList()
    {
        start = new Node();
        end = start;
    }

    Node* operator[](int i) // get element at position. kakto pri masivi
    {
        if(i<0) return 0;//invalid position
        int iterator = 0;
        Node* it = start;
        for(iterator = 0; iterator < i ; iterator++)
        {
            it=it->next;
            if(!it) return 0; //invalid position
        }
        return it;
    }

    void push_front(string s)
    {
        Node* new_node = new Node(s);
        new_node->next = start;
        start = new_node;
    }

    void push_back(string s)
    {
        Node* new_node = new Node(s);
        end->next = new_node;
        end = new_node;
    }

    void insertAfter(Node* pos, string s)
    {
        Node* iterator = start;
        while(iterator!=pos)
        {
            iterator=iterator->next;
            if(!iterator) return; //Reached end of list without finding match
        }
        Node* new_node = new Node(s);
        new_node->next = iterator->next;
        iterator->next = new_node;
    }

    void pop_front()
    {
        Node* pop = start;
        start = start->next;
        delete pop;
    }

    void pop_back()
    {
        Node* iterator = start;
        while(iterator->next != end) iterator = iterator->next;
        Node* pop = end;
        iterator->next = 0;
        end = iterator;
        delete pop;
    }

    void erase(Node* pos)
    {
        Node* iterator = start;
        while(iterator->next!=pos)
        {
            iterator=iterator->next;
            if(!iterator) return; //Reached end of list without finding match
        }
        Node* pop = iterator->next;
        iterator->next = iterator->next->next;
        delete pop;
    }

    ~LinkedList()
    {
        Node* iterator = start;
        Node* del;
        while(iterator)
        {
            del = iterator;
            iterator = iterator->next;
            delete del;
        }
    }
};

int main()
{
    LinkedList ll;
    ll.push_front("this?");  //         this?
    ll.push_front("is ");    //      is this?
    ll.push_front("what ");  // what is this?
    ll.push_back(" shit?");  // what is this? shit?
    ll.erase(ll[1]);         // what    this? shit?
    ll.pop_back();           // what    this?
    for(int i=0;i<=10;i++)
    {
        if(ll[i]) cout <<ll[i]->data;
    }
    cout << endl;
}

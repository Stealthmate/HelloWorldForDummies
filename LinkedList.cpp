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

void sort_list(const LinkedList &ll)
{
    LinkedList::Node* outer = ll.start;
    LinkedList::Node* inner = outer;
    for(outer = ll.start; outer; outer = outer->next)
    {
        for(inner = outer->next; inner; inner = inner->next)
        {
            if(outer->data.compare(inner->data)  > 0)
            ///Tova e za stringove. Obqsneno e v "Return Value" na tazi stranica http://www.cplusplus.com/reference/string/string/compare/
            /// Ako shte go pishete s chisla, prosto shte sravnqvate outer->data < inner->data primerno
            {
                string data = outer->data;
                outer->data = inner->data;
                inner->data = data;
            }
        }
    }

}

LinkedList::Node* find_by_value(const LinkedList& ll, string value)
{
    for(LinkedList::Node* iterator = ll.start; iterator; iterator = iterator->next)
    {
        if(value == iterator->data)
        {
            return iterator; //return Node containing value
        }
    }
    return 0;
}

int main()
{
    LinkedList ll;
    ll.push_front("a");  //         this?
    ll.push_front("b");    //      is this?
    ll.push_front("c");  // what is this?
    ll.push_back("d");  // what is this? shit?
    //ll.erase(ll[1]);         // what    this? shit?
   //ll.pop_back();           // what    this?
   cout <<"Unsorted:\n";
    for(int i=0;i<=10;i++)
    {
        if(ll[i]) cout <<ll[i]->data;
    }
    sort_list(ll);
    cout <<"\nSorted:\n";
    for(int i=0;i<=10;i++)
    {
        if(ll[i]) cout <<ll[i]->data;
    }
    cout<<"\nFind \"a\"\n";
    LinkedList::Node* found = find_by_value(ll, "a");
    if(found) cout << found->data << endl;
    cout<<"\nFind \"s\"\n";
    found = find_by_value(ll, "s");
    if(!found) cout << "Not found. Returned null\n";
    cout << endl;
}

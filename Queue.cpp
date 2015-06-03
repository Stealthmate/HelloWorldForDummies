#include <iostream>
#include <string>

using namespace std;

class Queue
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

    Queue()
    {
        start = new Node();
        end = start;
    }

    void push(string s)
    {
        Node* new_node = new Node();
        end->next = new_node;
        new_node->data = end->data;
        end->data = s;
        ///^ tova se pravi, shoto inache praznata stoinost (v sluchaq prazen string) shte ostane po sreadata na lista
        end = new_node;
    }

    void pop()
    {
        Node* pop = start;
        start = start->next;
        delete pop;
    }

    ~Queue()
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

void sort_queue(const Queue &queue)
{
    Queue::Node* outer = queue.start;
    Queue::Node* inner = outer;
    for(outer = queue.start; outer->next; outer = outer->next)
    {
        for(inner = outer->next; inner->next; inner = inner->next)
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

Queue::Node* find_by_value(const Queue& queue, string value)
{
    for(Queue::Node* iterator = queue.start; iterator; iterator = iterator->next)
    {
        if(value == iterator->data)
        {
            return iterator; //return Node containing value
        }
    }
    return 0;
}

void output_queue(const Queue &queue)
{
    for(Queue::Node* iterator = queue.start; iterator; iterator = iterator->next)
    {
        cout << iterator->data << " ";
    }
    cout << endl;
}

int main()
{
    Queue queue;
    queue.push("a");  //         this?
    queue.push("b");    //      is this?
    queue.push("c");  // what is this?
    queue.push("d");  // what is this? shit?
    queue.pop();
    cout <<"Unsorted:\n";
    output_queue(queue);
    sort_queue(queue);
    cout <<"\nSorted:\n";
    output_queue(queue);
    cout<<"\nFind \"a\"\n";
    Queue::Node* found = find_by_value(queue, "a");
    if(found) cout << found->data << endl;
    cout<<"\nFind \"s\"\n";
    found = find_by_value(queue, "s");
    if(!found) cout << "Not found. Returned nuqueue\n";
    cout << endl;
}

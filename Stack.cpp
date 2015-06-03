#include <iostream>
#include <string>

using namespace std;

class Stack
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

    Stack()
    {
        start = new Node();
        end = start;
    }

    void push(string s)
    {
        Node* new_node = new Node(s);
        new_node->next = start;
        start = new_node;
    }

    void pop()
    {
        Node* pop = start;
        start = start->next;
        delete pop;
    }

    ~Stack()
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

void sort_stack(const Stack &stack)
{
    Stack::Node* outer = stack.start;
    Stack::Node* inner = outer;
    for(outer = stack.start; outer->next; outer = outer->next)
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

Stack::Node* find_by_value(const Stack& stack, string value)
{
    for(Stack::Node* iterator = stack.start; iterator->next; iterator = iterator->next)
    {
        if(value == iterator->data)
        {
            return iterator; //return Node containing value
        }
    }
    return 0;
}

void output_stack(const Stack &stack)
{
    for(Stack::Node* iterator = stack.start; iterator; iterator = iterator->next)
    {
        cout << iterator->data << " ";
    }
    cout << endl;
}

int main()
{
    Stack stack;
    stack.push("a");  //         this?
    stack.push("b");    //      is this?
    stack.push("c");  // what is this?
    stack.push("d");  // what is this? shit?
    cout <<"Unsorted:\n";
    output_stack(stack);
    sort_stack(stack);
    cout <<"\nSorted:\n";
    output_stack(stack);
    cout<<"\nFind \"a\"\n";
    Stack::Node* found = find_by_value(stack, "a");
    if(found) cout << found->data << endl;
    cout<<"\nFind \"s\"\n";
    found = find_by_value(stack, "s");
    if(!found) cout << "Not found. Returned nustack\n";
    cout << endl;
}

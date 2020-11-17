#include <iostream>
using namespace std;



class NMSet {
private:
    
    class Node
    {
    public:
        Node* next;
        int data;

        Node(int data = int(), Node* pNext = nullptr)
        {
            this->data = data;
            this->next = pNext;
        }
    };
    int size;
    Node* head;

public:

    class Iterator {
        Node* ptr;
    public:
        Iterator() { ptr = NULL; }
        Iterator(Node* _ptr) { ptr = _ptr; }
        Iterator& operator ++() {
            if (ptr != NULL)
                ptr = ptr->next;
            return *this;
        }
        Iterator operator++(int) {
            Iterator it(*this);
            ++* this;
            return it;
        }
        Iterator operator+( int k) {
            Iterator it(*this);
            for (; k > 0; k--) {
                ++* this;
            }
            return it;
        }
        int operator*() {
            if (ptr == NULL) { throw "false *iterator"; }
            return ptr->data;
        }
        bool operator==(const Node *_ptr) {
            if (ptr == _ptr)
                return true;
            else
                return false;
        }
        bool operator!=(const Node* _ptr) {
            if (ptr != _ptr)
                return true;
            else
                return false;

        }

    };

    NMSet() { head = nullptr; size = 0; }
    ~NMSet() {}

    void push_back(int &dta)
            {
                if (head == nullptr)
                {
                    head = new Node(dta);
                    size++;
                }
                else
                {
                    Node* cur = head;
                    while (cur->next != nullptr)
                    {
                        cur = cur->next;
                    }
                    cur->next = new Node(dta);
                    size++;
                }

            }
    Node* Begin() { return head; }
    Node* End() { return NULL; }
    friend istream& operator>>(istream& is, NMSet& a)
            {
                char c[80];
                int dump = 0;
                int val = 0;
                is.getline(c,80);
                    for (int i = 0; c[i] != '\n'; i++)
                    {
                            if (c[i] == '[' && (!isdigit(c[i + 1]) && c[i + 1] != ']'))//cout whith error and abort()
                            {
                                    cout<<"incorrect input_1";  
                                    abort();
                            }
                            else if (c[i] == '[')
                            {
                                dump = i;
                            }
                            if (isdigit(c[i]) && (c[i + 1] != ']' && !isdigit(c[i + 1]) && c[i + 1] != ','))
                            {
                                throw"incorrect input_2";
                            }
                            if (c[i] == ',' && (!isdigit(c[i + 1])))
                            {
                                throw"incorrect input_3";
                            }
                            if (c[i] == ']' && (!isdigit(c[i - 1]) && c[i - 1] != '['))
                            {
                                throw"incorrect input_4";
                            }
                            else if (c[i] == ']')
                            {
                                break;
                            }
                        
                        
                    }
                for (int i = dump; c[i] != ']'; i++)
                {
                    if (isdigit(c[i]))
                    {
                        val = val * 10 + c[i] - '0';
                    }
                    if (c[i] == ',' || c[i + 1] == ']')
                    {
                        a.push_back(val);
                        val = 0;
                    }
                }
                return is;
            }
    friend ostream& operator<<(ostream& os, NMSet& a)
            {
        NMSet b;
        b = a;
                cout << '[';
                cout << b.head->data;
                b.head = b.head->next;
                for(int i=1;i<b.size;i++)
                {
                    cout<<',' << b.head->data;
                    b.head=b.head->next;
                }
                cout << ']';
                return os;
            }
    int getSize() { return size; }//мощность
    NMSet operator+( const NMSet& a)//объединение
    {
        NMSet b;
        Node* h = head;
        Node* ah = a.head;
            while (h!=nullptr&&ah!=nullptr)
            {
                if (h->data < ah->data)
                {
                    b.push_back(h->data);
                    h = h->next;
                }
                else if (h->data > ah->data)
                {
                    b.push_back(ah->data);
                    ah = ah->next;


                }
                else if (h->data == ah->data)
                {
                    b.push_back(h->data);
                    b.push_back(h->data);
                    h = h->next;
                    ah = ah->next;

                }
                
            }
            if(h!=nullptr)
            {
                while (h != nullptr)
                {
                    b.push_back(h->data);
                    h = h->next;
                }
            }
            else if (ah != nullptr)
            {
                while (ah != nullptr)
                {
                    b.push_back(ah->data);
                    ah = ah->next;
                }
            }
        return b;
    }
    NMSet operator/(const NMSet& a)//пересечение
    {
        NMSet b;
        Node* h = head;
        Node* ah = a.head;
        int dump = -1;
        if (size > a.size)
        {
            while(ah!=nullptr)
            {
                while (h != nullptr)
                {
                    if (h->data == ah->data&&h->data!=dump)
                    {
                        b.push_back(h->data);
                        dump = h->data;
                    }
                    h = h->next;
                }
                ah = ah->next;
                h = head;
            }
        }
        else
        {
            while (h != nullptr)
            {
                while (ah != nullptr)
                {
                    if (h->data == ah->data && h->data != dump)
                    {
                        b.push_back(h->data);
                        dump = h->data;
                    }
                    ah = ah->next;
                }
                h = h->next;
                ah = head;
            }
        }
        return b;
    }
    NMSet operator-(const NMSet& a)
    {
        NMSet b;
        Node* h = head;
        Node* ah = a.head;
        bool ch= true;
        while (h != nullptr)
        {
            while (ah!=nullptr)
            {
                if (h->data == ah->data) { ch = false; break; }
                ah=ah->next;
            }
            if (ch == true) { b.push_back(h->data);}
            h = h->next;
            ah = a.head;
            ch = true;
        }

        return b;
    }
    NMSet operator=(const NMSet& a)
    {
        size = a.size;
        head = a.head;
        return *this;
    }
    NMSet deltaDiff(const NMSet& a) 
    {
        NMSet a1, b1;
        a1 = *this;
        b1 = a;
        return (a1-b1)+(b1-a1);
    }
};





int main()
{
    NMSet A;
        cin >> A;
    NMSet::Iterator it(A.Begin());
    while (it != A.End())
    {
        cout << *it;
        it+5;
    }

    cout << A;


}
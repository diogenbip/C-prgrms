#include <iostream>
using namespace std;

class List {

    class Node {
    public:
        Node* next;
        int Data;

        Node(int Dta=1,Node * nxt = nullptr)//set of NN can be empty, Dta can be empty
        {
            next = nxt;
            Data = Dta;
        }
        
    };
    int Size;
    Node* head;
public:
    List(int size=0,Node* hd=nullptr) 
    {
        Size = size;
        head = hd;
    }
    ~List(){}

    void push_back(int Data)
    {
        if (head == nullptr)
        {
            head = new Node(Data);
            Size++;
        }
        else
        {
            Node* cur = head;
            while (cur->next != nullptr)
            {
                cur = cur->next;
            }
            cur->next = new Node(Data);
            Size++;
        }
    }
    void print()
    {
        for(int i=0;i<Size;i++)
        {
            cout << head->Data<<endl;
            head=head->next;
        }
    }

};

class NatureMultiSet
{
    List A;

public:
    NatureMultiSet(){
        
    }
    ~NatureMultiSet(){}

   friend istream& operator>>(istream &is, NatureMultiSet&a){
      
       char s;
       is.get(s);
       int val = 0;
       while (s != '\n')
       {
           if (isdigit(s))
           {
               val = val * 10 + s - '0';
           }
           if (s == ',')
           {
               a.A.push_back(val);
               val = 0;
           }
           is.get(s);
       }
       a.A.push_back(val);

       /*bool check = true;
        char c;
        is.get(c);
        streampos p;
        while (!is.eof() || c == ' ') {
            if (is.eof() && c != '[')
            {
                throw "Incorrect input";
            }
            else if (c == '[')
            {
                p = is.tellg();
            }
            char set;
            is.get(set);
            if (c == '[')
            {
                while (check)
                {
                    if (c == '[' && (!isdigit(set) && set != ']'))
                    {
                        throw"incorrect input_1";
                    }
                    if (isdigit(c) && (set != ']' && !isdigit(set) && set != ','))
                    {
                        throw"incorrect input_2";
                    }
                    if (c == ',' && (!isdigit(set)))
                    {
                        throw"incorrect input_3";
                    }
                    if (set == ']' && (isdigit(c) || c == '['))
                    {
                        is.seekg(p);
                        is.get(set);
                        int val = 0;
                        c = set;
                        
                        while (c != ']')
                        {
                            if (isdigit(c))
                            {
                                val = 10 * val + c - '0';
                            }
                            if (c == ',')
                            {
                                a.A.push_back(val);
                                val = 0;
                            }
                            c = set;
                            is.get(set);
                        }
                        check = false;
                    }
                    c = set;
                    is.get(set);
                }
                

            }
            is.get(c);
        }*/
  
        return is;

    }
   void printt()
   {
       A.print();
   }

};

class Iterator {
   

public:

};

int main()
{
    NatureMultiSet A;
    cin >> A;
    A.printt();
    
}



     
 

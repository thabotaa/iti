#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
using namespace std;
class LinkedList
{
    //How Many Node ?
    //Node node;
    //Node node[?????];
    private:
        Node * head;
        Node * tail;
    Node * getNodeUsingData(int data){
        Node *current=head;
        while(current != NULL){
            if(current->Data==data){
                return current;
            }
            //Jump
            current=current->Next;
        }
        return NULL;

    }


    public:
        LinkedList() {
            head=tail=NULL;
        }
        void add(int data){
            //Create Node
            Node * node = new Node(data); //Create Object Node , Data=data , next,prev=null

                if(head == NULL){//First Node
                    head=tail=node;
                    //node->Next=node->prev=NULL;
                }
                else{//Not First Node
                    tail->Next =node; //Old->Next=NewNode
                    node->Prev=tail; //newNode->prev=old(Node)
                    tail=node;//tail=node;
                }
        }
        void display(){
            Node * current =head;//NULL
            if(current == NULL){
                cout<<"Linked List is Empty \n";
                return ;
            }
            while(current != NULL){
                //Display
                cout<<current->Data<<"\t";
                //Increment Jump Node
                current=current->Next;
            }
            cout<<endl;
        }


    void removeNode(int data){
        //Search Linked List
        Node * node = getNodeUsingData(data);
        if(node == NULL){
            cout<<"Element Not Found , Can't Remove \n";
            return;
        }
        else{
            //Remove First
            if(node == head){
                if(node == tail){
                    tail=head=NULL;
                }
                else{
                    head=node->Next;
                    head->Prev=NULL;
                }

            }
            else if (node == tail){ //Remove Last
                tail=node->Prev;
                tail->Next=NULL;
            }
            else{//Remove Mid
                Node * A=node->Prev;
                Node * B=node->Next;
                A->Next=B;
                B->Prev=A;
            }

            delete(node);

        }

    }

    int search_using_data(int data){
        Node * node = getNodeUsingData(data);
        if(node == NULL){
            return 0;
        }
        else{
            return 1;
        }
    }
    int get_count()
    {
        Node *cursor;
        cursor=head;
        int counter=0;
        while(cursor!= NULL)
        {
           cursor=cursor->Next;
           counter++;
        }
        return counter;

           //cout<<"number of elemnt in list is "<<counter;
    }
    void insert_after(int exist_data,int new_data)
    {
       Node *exist_node,*added_node,*next_node;

       exist_node=getNodeUsingData(exist_data);
       added_node=new Node(new_data);

       if(exist_node==NULL)
       {
           cout<<"couldn't find this element "<<exist_data<<endl;

       }

       else if(exist_node==tail)                  ///exist in last element in list
     /*  {
              if(exist_node->Prev==NULL)     ///check only 1 element in list
              {
                exist_node->Next=added_node;
                added_node->Next=NULL;
                added_node->Prev=exist_node;
                tail=added_node;
             }
            else                            /// the last element in list
      */      {
                exist_node->Next=added_node;
                added_node->Prev=exist_node;
                added_node->Next=NULL;
                tail=added_node;
             }

       else                                                 ///exist in middle
       {
         next_node=exist_node->Next;
        // exist_node->Next=next_node;
         next_node->Prev=added_node;
         exist_node->Next=added_node;
         added_node->Next=next_node;
         added_node->Prev=exist_node;
       }
    }


    void insert_before(int exist_data,int new_data)
    {
       Node *exist_node,*added_node,*prev_node;

       exist_node=getNodeUsingData(exist_data);
       added_node=new Node(new_data);

       if(exist_node==NULL)
       {
           cout<<"couldn't find this element "<<exist_data<<endl;
       }
       else if(exist_node==head)         ///check exist in first element
       {
           added_node->Next=exist_node;
           exist_node->Prev=added_node;
           head=added_node;
       }
       else                              ///insert in middle
       {
        prev_node=exist_node->Prev;
        prev_node->Next=added_node;
        added_node->Prev=prev_node;
        added_node->Next=exist_node;
        exist_node->Prev=added_node;
       }
    }

    void get_data_by_index(int index)
    {
        int i=0;
        Node *temp_node;
        temp_node=head;
        if(index>get_count()-1)
        {
          cout<<"can't find,out of list \n";
        }
        else
        {
            while(i!=index)
            {
              temp_node=temp_node->Next;
              i++;
            }
            cout<<"the element is in list with value  "<<temp_node->Data<<endl;
        }
    }


    void push(int data)
    {
        Node *added_node,*next_node;
        added_node=new Node(data);
        if(head==NULL)
        {
            head=tail=added_node;
            added_node->Next=NULL;
            added_node->Prev=NULL;
        }


        else
        {
            tail->Next=added_node;
            added_node->Prev=tail;
            tail=added_node;
        }
    }

    int pop(int &data)
        {
            Node *temp_node;
            if(tail==NULL)
                return 0;
            else
            {
                temp_node=tail;
                tail=tail->Prev;
                data=temp_node->Data;
                return 1;
            }

        }

    void display_new()
    {
     /*  int data=0;
       if(tail==NULL)
       cout<<"it's empty\n ";
       else{
        while(tail!=NULL)
         pop(data)?cout<<data<<" ":cout<<"it's empty\n ";
          }
*/


         Node * current =head;//NULL
            if(current == NULL){
                cout<<"stack is Empty \n";
                return ;
            }


            while(current != NULL){

                if(current == tail)
                {
                     cout<<current->Data<<"\t";
                     break;
                }

                //Display
                cout<<current->Data<<"\t";
                //Increment Jump Node
                current=current->Next;
            }

            cout<<endl;
    }

          int peek(int & data){
            if(tail ==NULL){
              return 0;
               //throw Exception;
            }
               data=tail->Data;
               tail->Data=0;
               return 1;
        }









};

#endif // LINKEDLIST_H

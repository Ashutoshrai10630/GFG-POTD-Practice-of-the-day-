class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)  // simply for checking if head is null or not 
    {
        if(head == NULL) {
    Node* newNode = new Node(data);
    newNode->next = newNode;
    return newNode;
}
       if(head->data>=data)  // if element is to be inserted first
       {
           Node* dum=new Node(data);
           dum->next=head;
           Node* temp=head;
           while(temp->next!=head)
           {
               temp=temp->next;
           }
           temp->next=dum;
           return dum;
       }
       else if(head->data<data)  // if element is inserted between or at the end 
       {
           Node*temp=head->next;
           Node* prev=head;
           while(temp->data<data and temp!=head)
           {
               prev=temp;
               temp=temp->next;
           }
           if(temp==head)  // if element is inserted at end 
           {
               Node* dum3=new Node(data);
               prev->next=dum3;
               dum3->next=temp;
               return head;
           }
           else {  // for simply inserting the element in between 
               Node* dum2=new Node(data);
           prev->next=dum2;
           dum2->next=temp;
           return head;
               
           }
           
           
       }
       return NULL;
    }
};

//Let's Solve the question Together 



class Solution
{
public:
  int intersectPoint(Node* head1, Node* head2)
    {
        Node* pointer_to_L1=head1,*pointer_to_L2=head2;
        
        while(pointer_to_L1!=pointer_to_L2){
            if(pointer_to_L1->next==NULL)pointer_to_L1=head2;
            else
            pointer_to_L1=pointer_to_L1->next;
            if(pointer_to_L2->next==NULL)pointer_to_L2=head1;
            else
            pointer_to_L2=pointer_to_L2->next;
        }
        return pointer_to_L1->data;
    }
};

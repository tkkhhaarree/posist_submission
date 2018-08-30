#include<bits/stdc++.h>

using namespace std;

struct node {
    string timestamp;
    int data;
    int nodeNumber;
    string nodeId;
    string referenceNodeId;
    vector <string> childReferenceNodeId;
    string genesisReferenceNodeId;
    string hashValue;
    // a vector to store pointers to children.
    vector <node*> children;
};

int main(){
    node *genesis = new node();

    // adding basic data to genesis node.
    genesis->data = 30;

    // adding children to genesis node
    node *child1 = new node();
    node *child2 = new node();

    child1->data = 17;
    child2->data = 10;

    // pushing children node pointers to children list vector of genesis node.
    genesis->children.push_back(child1);
    genesis->children.push_back(child2);


    // adding a 3rd child to genesis node after checking if it satisfies the sum condition given in question.
    node *child3 = new node();
    child3->data = 2;
    int i=0, sum=0;
    for (i=0; i<genesis->children.size(); i++){
        sum = sum+genesis->children[i]->data;
    }
    // checking that sum does not exceed parent's value and then adding the node in children list.
    int sum2 = sum+child3->data;
    if (sum2 <= genesis->data){
        genesis->children.push_back(child3);
    }
    else{
        cout<<"Sum of children exceeded parent node!!!\n";
    }

    // print values of genesis, its children and sum of children.
    cout<<"genesis value: "<<genesis->data<<"\n";
    for (i=0; i<genesis->children.size(); i++){
        cout<<"child no. "<<i+1<<": "<<genesis->children[i]->data<<"\n";
    }

    cout<<"Sum: "<<sum2<<"\n\n";

    // creating further children and adding them in chain after checking the sum conditions.
    vector <node *> newchildren;
    node *child11 = new node();
    node *child12 = new node();
    child11->data = 5;
    child12->data = 4;
    child11->children.push_back(NULL);
    child12->children.push_back(NULL);
    newchildren.push_back(child11);
    newchildren.push_back(child12);

    // check if sum of new children is less than its parent.
    sum = 0;
    for (i=0; i<newchildren.size(); i++){
        sum = sum+newchildren[i]->data;
    }
    if (sum<=child1->data){
        for (i=0; i<newchildren.size(); i++){
            child1->children.push_back(newchildren[i]);
        }
    }
    else {
        cout<<"sum exceeded for children of child1!!";
    }

    cout<<"data of child1: "<<child1->data<<"\n";
    cout<<"data of children of child1: \n";
    for (i=0; i<child1->children.size(); i++){
        cout<<child1->children[i]->data<<"\n";
    }
    cout<<"sum of children of child1: "<<sum<<"\n\n";


    // find longest chain of genesis node.
    node *temp = genesis;
    int c = 0;
    cout<<"traversing the longest path starting from genesis... \n";
    while(temp!=NULL){
        cout<<"element found in path: "<<temp->data<<"\n";
        c++;
        temp = temp->children[0];

    }
    cout<<"Length of longest node: "<<c<<"\n";


}

#pragma once
#include<iostream>
#include<array> 
#include"queue.h"
#include"stack.h"
#include<string>
using namespace std;
int c = 0;
template <class T1, class T2 ,class T3, class T4>
class BTNode {
public:
    T1 id;
    T2 year;
    string cause113;
    string causename;
    string state;
    T3 deaths;
    T4 deathrate;
    BTNode<T1, T2, T3, T4>* left;
    BTNode<T1, T2, T3, T4>* right;
    int height;
    int line;
    string filename;


    BTNode() {
        this->id = 0;
        this->year = 0;
        this->cause113 = 0;
        this->causename = 0;
        this->state = 0;
        this->deaths = 0;
        this->deathrate = 0;
        
        left = NULL;
        right = NULL;
    }

    BTNode(T1 one, T2 two, string three, string four, string five, T3 six ,T4 Seven) {
        this->id = one;
        this->year = two;
        this->cause113 = three;
        this->causename = four;
        this->state = five;
        this->deaths = six;
        this->deathrate = Seven;
        left = NULL;
        right = NULL;
    }
    BTNode(T1 one, T2 two, string three, string four, string five, T3 six, T4 Seven, BTNode* left, BTNode* right)
    {   
        this->id = one;
        this->year = two;
        this->cause113 = three;
        this->causename = four;
        this->state = five;
        this->deaths = six;
        this->deathrate = Seven;

    
        this->left = left;
        this->right = right;
    };


    ~BTNode() {
        delete left;
        delete right;
    }



};


template <class T1, class T2, class T3, class T4>
class AVL {
public:
    BTNode<T1, T2, T3, T4>* root;




    AVL() {
        root = NULL;
    }

    BTNode<T1, T2, T3, T4>* newNode(T1 one, T2 two, string three, string four, string five, T3 six, T4 Seven)
    {
        BTNode<T1, T2, T3, T4>* node = new BTNode<T1, T2, T3, T4>( one,  two,  three,  four,  five,  six,  Seven);

        node->left = NULL;
        node->right = NULL;
        node->height = 1;

        return(node);
    }


    int height(BTNode<T1,T2,T3,T4>* N) {
        if (N == NULL)
            return 0;
        return N->height;
    }
    int getBalance(BTNode<T1, T2, T3, T4>* N)
    {
        if (N == NULL)
        {
            return 0;
        }
        return height(N->left) - height(N->right);
    }
    BTNode<T1, T2, T3, T4>* rightRotate(BTNode<T1, T2, T3, T4>* y)
    {
        BTNode<T1, T2, T3, T4>* a = y->left;
        BTNode<T1, T2, T3, T4>* b = a->right;

        a->right = y;
        y->left = b;

        y->height = max(height(y->left), height(y->right)) + 1;
        a->height = max(height(a->left), height(a->right)) + 1;
      //  cout << "RR" << endl;
        return a;
    }



    BTNode<T1, T2, T3, T4>* leftRotate(BTNode<T1, T2, T3, T4>* x)
    {
        BTNode<T1, T2, T3, T4>* a = x->right;
        BTNode<T1, T2, T3, T4>* b = a->left;

        a->left = x;
        x->right = b;

        x->height = max(height(x->left), height(x->right)) + 1;
        a->height = max(height(a->left), height(a->right)) + 1;

        return a;
    }



    BTNode<T1, T2, T3, T4>* DoubleRotateWithRight(BTNode<T1, T2, T3, T4>* K1)
    {
        K1->right = leftRotate(K1->right);

        return rightRotate(K1);
    }

    BTNode<T1, T2, T3, T4>* DoubleRotateWithLeft(BTNode<T1, T2, T3, T4>* K3)
    {

        K3->left = rightRotate(K3->left);
        return leftRotate(K3);

    }




    BTNode<T1, T2, T3, T4>* insert(BTNode<T1,T2,T3,T4>* node, T1 one, T2 two, string three, string four, string five, T3 six, T4 Seven)
    {

        if (node == NULL)
            return(newNode( one,  two,  three,  four,  five,  six,  Seven));

        if (one < node->id)
            node->left = insert(node->left,  one,  two,  three,  four,  five, six,  Seven);
        else if (one > node->id)
            node->right = insert(node->right, one, two, three, four, five, six, Seven);
        else
            return node;

        node->height = 1 + max(height(node->left),
            height(node->right));


        int balance = getBalance(node);

        // cout << balance << endl;
        if (balance > 1 && one < node->left->id)
            return rightRotate(node);


        if (balance < -1 && one > node->right->id)
            return leftRotate(node);


        if (balance > 1 && one > node->left->id)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }


        if (balance < -1 && one < node->right->id)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }


        return node;
    }





    void levelOrder(BTNode<T1,T2,T3,T4>* root)
    {
        if (root == NULL) {
            return;
        }
       // one, two, three, four, five, six, Seven
        Queue<BTNode<T1, T2, T3, T4>*> q;
        BTNode<T1, T2, T3, T4>* temp;
        q.enqueue(root);
        q.enqueue(NULL);

        while (q.getSize() > 1)
        {
            temp = q.front();
            q.dequeue();
            if (temp == NULL)
            {
                q.enqueue(NULL);
              //  cout << endl;;
            }
            else {
                if (!temp->left == NULL) {
                    q.enqueue(temp->left);
                }
                if (!temp->right == NULL)
                {
                    q.enqueue(temp->right);
                }
                c++;
                cout << temp->id   << "                    ";
            }
        }
    }


    void distribute(BTNode<T1, T2, T3, T4>* node){
      



        
    
    }

    void printInorder(BTNode<T1, T2, T3, T4>* node)
    {
        if (node == NULL)
            return;


        printInorder(node->left);
       // cout << node->id << " " << endl;

        printInorder(node->right);

    }


    string* createstatefiles(BTNode<T1, T2, T3, T4>* node)
    {
        stack< BTNode<T1, T2, T3, T4>*> s;
        BTNode<T1, T2, T3, T4>* curr = root;
        int count=0;

        while (curr != NULL || s.isEmpty() == false)
        {
            
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.TOP();
            s.pop();

        //   cout << curr->state<< " ";
            count++;

            curr = curr->right;

        }


       string *states = new string[count];


        stack< BTNode<T1, T2, T3, T4>*> s1;
        BTNode<T1, T2, T3, T4>* curr1 = root;
        int count1 = 0;



        while (curr1 != NULL || s1.isEmpty() == false)
        {

            while (curr1 != NULL)
            {
                s1.push(curr1);
                curr1 = curr1->left;
            }
            curr1 = s1.TOP();
            s1.pop();

            states[count1]= curr1->state;
            count1++;

            curr1 = curr1->right;

        }

        int a = 0;
        int n = count1;

        for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n;)
        {
            if (states[i] == states[j])
            {
                for (int k = j; k < n - 1; ++k)
                    states[k] = states[k + 1];
                --n;
            }
            else
                ++j;
        }
      //cout << "\n";
        for (int i = 0; i < n; ++i)
            //cout << states[i] << " " << endl;

       
      //  cout << n << n << endl;

        
       
        for (int i = 0; i < n; ++i)
        {
            string path = "d:/DBMS/AVL/State/";
            ofstream file(path + states[i] + ".txt");
        }
        


        return states;

    }
    // Delete a node
    //Node* deleteNode(Node* root, int key) {
    //    // Find the node and delete it
    //    if (root == NULL)
    //        return root;
    //    if (key < root->key)
    //        root->left = deleteNode(root->left, key);
    //    else if (key > root->key)
    //        root->right = deleteNode(root->right, key);
    //    else {
    //        if ((root->left == NULL) ||
    //            (root->right == NULL)) {
    //            Node* temp = root->left ? root->left : root->right;
    //            if (temp == NULL) {
    //                temp = root;
    //                root = NULL;
    //            }
    //            else
    //                *root = *temp;
    //            free(temp);
    //        }
    //        else {
    //            Node* temp = nodeWithMimumValue(root->right);
    //            root->key = temp->key;
    //            root->right = deleteNode(root->right,
    //                temp->key);
    //        }
    //    }

    //    if (root == NULL)
    //        return root;

    //    // Update the balance factor of each node and
    //    // balance the tree
    //    root->height = 1 + max(height(root->left),
    //        height(root->right));
    //    int balanceFactor = getBalanceFactor(root);
    //    if (balanceFactor > 1) {
    //        if (getBalanceFactor(root->left) >= 0) {
    //            return rightRotate(root);
    //        }
    //        else {
    //            root->left = leftRotate(root->left);
    //            return rightRotate(root);
    //        }
    //    }
    //    if (balanceFactor < -1) {
    //        if (getBalanceFactor(root->right) <= 0) {
    //            return leftRotate(root);
    //        }
    //        else {
    //            root->right = rightRotate(root->right);
    //            return leftRotate(root);
    //        }
    //    }
    //    return root;
    //}




  int noofstates(BTNode<T1, T2, T3, T4>* node)
    {
        stack< BTNode<T1, T2, T3, T4>*> s;
        BTNode<T1, T2, T3, T4>* curr = root;
        int count = 0;

        while (curr != NULL || s.isEmpty() == false)
        {

            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.TOP();
            s.pop();

   
            count++;

            curr = curr->right;

        }


        string* states = new string[count];


        stack< BTNode<T1, T2, T3, T4>*> s1;
        BTNode<T1, T2, T3, T4>* curr1 = root;
        int count1 = 0;



        while (curr1 != NULL || s1.isEmpty() == false)
        {

            while (curr1 != NULL)
            {
                s1.push(curr1);
                curr1 = curr1->left;
            }
            curr1 = s1.TOP();
            s1.pop();

            states[count1] = curr1->state;
            count1++;

            curr1 = curr1->right;

        }

        int a = 0;
        int n = count1;

        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n;)
            {
                if (states[i] == states[j])
                {
                    for (int k = j; k < n - 1; ++k)
                        states[k] = states[k + 1];
                    --n;
                }
                else
                    ++j;
            }
      

        return n;

    }





    void PutDatainstates(BTNode<T1, T2, T3, T4>* node , string  * a ,int size )
    {
        
    
        for (int i = 0; i < size; ++i)
        {
            string path = "d:/DBMS/AVL/State/";
            fstream file(path + a[i] + ".txt");

            stack< BTNode<T1, T2, T3, T4>*> s;
            BTNode<T1, T2, T3, T4>* curr = root;
            int count = 0;

            while (curr != NULL || s.isEmpty() == false)
            {

                while (curr != NULL)
                {
                    s.push(curr);
                    curr = curr->left;
                }
                curr = s.TOP();
                s.pop();

                if (curr->state == a[i]){
                  file<<curr->id<<"|"<<curr->year<<"|"<< curr->cause113<<"|"<< curr->causename<<"|"<<curr->state<<"|" <<  curr->deaths<<"|"<< curr->deathrate<<curr->filename<<"|"<< curr->line << endl;
                }

                curr = curr->right;

            }
        
        }
      

    }


    T2* createyearfiles(BTNode<T1, T2, T3, T4>* node)
    {
        

        stack< BTNode<T1, T2, T3, T4>*> s;
        BTNode<T1, T2, T3, T4>* curr = root;
        int count = 0;

        while (curr != NULL || s.isEmpty() == false)
        {

            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.TOP();
            s.pop();

              // cout << curr->year<< " ";
            count++;

            curr = curr->right;

        }


        T2 * years = new T2[count];


        stack< BTNode<T1, T2, T3, T4>*> s1;
        BTNode<T1, T2, T3, T4>* curr1 = root;
        int count1 = 0;

        while (curr1 != NULL || s1.isEmpty() == false)
        {

            while (curr1 != NULL)
            {
                s1.push(curr1);
                curr1 = curr1->left;
            }
            curr1 = s1.TOP();
            s1.pop();

            years[count1] = curr1->year;
            count1++;

            curr1 = curr1->right;

        }

        int a = 0;
        int n = count1;

        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n;)
            {
                if (years[i] == years[j])
                {
                    for (int k = j; k < n - 1; ++k)
                        years[k] = years[k + 1];
                    --n;
                }
                else
                    ++j;
            }
      //  cout << "\n";

       /* for (int i = 0; i < n; ++i)
            cout << years[i] << "<-- . -->" << endl;*/


       // cout << n << n << endl;



            for (int i = 0; i < n; ++i)
            {
                string m = to_string(years[i]);
                string path = "d:/DBMS/AVL/Years/";
                ofstream file(path +m+ ".txt");
            }



        return years;

    }


    T2 noofyears(BTNode<T1, T2, T3, T4>* node)
    {


        stack< BTNode<T1, T2, T3, T4>*> s;
        BTNode<T1, T2, T3, T4>* curr = root;
        int count = 0;

        while (curr != NULL || s.isEmpty() == false)
        {

            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.TOP();
            s.pop();

          //  cout << curr->year << " ";
            count++;

            curr = curr->right;

        }


        T2* years = new T2[count];


        stack< BTNode<T1, T2, T3, T4>*> s1;
        BTNode<T1, T2, T3, T4>* curr1 = root;
        int count1 = 0;

        while (curr1 != NULL || s1.isEmpty() == false)
        {

            while (curr1 != NULL)
            {
                s1.push(curr1);
                curr1 = curr1->left;
            }
            curr1 = s1.TOP();
            s1.pop();

            years[count1] = curr1->year;
            count1++;

            curr1 = curr1->right;

        }

        int a = 0;
        int n = count1;

        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n;)
            {
                if (years[i] == years[j])
                {
                    for (int k = j; k < n - 1; ++k)
                        years[k] = years[k + 1];
                    --n;
                }
                else
                    ++j;
            }
       // cout << "\n";

       

      //  cout << n << n << endl;






        return n;

    }

    void PutDatainyears(BTNode<T1, T2, T3, T4>* node, T2* a, int size)
    {


        for (int i = 0; i < size; ++i)
        {
            string path = "d:/DBMS/AVL/Years/";
            string m = to_string(a[i]);
            fstream file(path + m + ".txt");

            stack< BTNode<T1, T2, T3, T4>*> s;
            BTNode<T1, T2, T3, T4>* curr = root;
            int count = 0;

            while (curr != NULL || s.isEmpty() == false)
            {

                while (curr != NULL)
                {
                    s.push(curr);
                    curr = curr->left;
                }
                curr = s.TOP();
                s.pop();

                if (curr->year == a[i]) {
                    file << curr->id << "|" << curr->year << "|" << curr->cause113 << "|" << curr->causename << "|" << curr->state << "|" << curr->deaths << "|" << curr->deathrate << curr->filename << "|" << curr->line << endl;
                }

                curr = curr->right;

            }

        }


    }











};




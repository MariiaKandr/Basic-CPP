#include <iostream>
using namespace std;

//Классы - шаблонизация и полиморфизм 
template <typename T>
struct Node{
    //Поля - данные внутри узла 
    T value;
    Node* left;
    Node*  right;
    //Конструктор - ЖЦ - В момент создания Инициализация = список
    Node(T val):value(val),left(nullptr),right(nullptr){
    }
};
template <typename T>
class BST{
    Node<T>* root;
    
    Node* CreateNode(T val){
        Node* n2=new Node(val);
        return n2;
    }
    
    Node* insert(Node* another,T val){
        if(!another) return CreateNode(val);
        if(val<another->value){
            another->left=insert(another->left,val);
        }
        else if(val>another->value){
            another->right=insert(another->right,val);        
        }
        return another;
    }
    
    void Print(Node* another){
        if(!another) return;
        Print(another->left);
        cout<<another->value<<" ";
        Print(another->right);        
    }
    
    void Clear(Node* another){
        if(!another) return;
        Print(another->left);
        Print(another->right);    
        delete another;
    }
public:
    BST():root(nullptr){}
    
    ~BST(){
       //Очистки приватная
       Clear(root);
    }
    void insertIntro(T val){
        root=insert(root,val);
    }
    
    void PrintIntro(){
        Print(root);
        cout<<endl;
    }
};

int main() {
    BST t1;
    t1.insertIntro(10);
    BST t2;
    t2.insertIntro(20);
    t1.PrintIntro();
    t2.PrintIntro();    
}

    #include <iostream>
    using namespace std;

    //Классы - шаблонизация и полиморфизм 
    //Сохранение данных
    struct Node{
    //Поля - данные внутри узла 
    int value;
    Node* left;
    Node*  right;
    //Конструктор - ЖЦ - В момент создания Инициализация = список
    Node(int val):value(val),left(nullptr),right(nullptr){
    }
    };

    class BST{
    
    Node* root;
    
    Node* insert(Node* another,int val){
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
    void insertIntro(int val){
        root=insert(root,val);
    }
    
    void PrintIntro(){
        Print(root);
        cout<<endl;
    }
    
    Node* CreateNode(int val){
        Node* n2=new Node(val);
        return n2;
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

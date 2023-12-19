#include <iostream>
#include <vector>
#include <string>
#include <set>

int min_price = -1;
std::set<std::string> companies;

class Node{
    public:
        Node* parent;
        int parent_num;
        std::vector<Node*> childs;
        int price;
        std::set<std::string> comp;
        
        void add_from_child(Node* child){
            this->price += child->price;
            this->comp.insert(child->comp.begin(), child->comp.end());
        }
};

Node* add_from_childs(Node* node){
    for (auto child: node->childs){
        node->add_from_child(add_from_childs(child));
    }
    if (node->comp == companies && (node->price < min_price || min_price == -1))
        min_price = node->price;
    return node;
}

int main(){
    int n, k;
    scanf("%d %d\n", &n, &k);
    std::vector<Node*> tree(n);
    for (int i = 0; i < k; i++){
        std::string comp;
        std::cin >> comp;
        companies.insert(comp);
    }
    
    for (int i = 0; i < n; i++){
        int p, a;
        std::string c;
        scanf("%d %d ", &p, &a);
        std::cin >> c;
        Node* node = new Node();
        node->parent_num = p - 1;
        node->price = a;
        node->comp.insert(c);
        tree[i] = node;
    }
    
    Node* root;
    for (int i = 0; i < n; i++){
        Node* node = tree[i];
        if (node->parent_num == -1){
            root = node;
        }
        else {
            node->parent = tree[node->parent_num];
            tree[node->parent_num]->childs.push_back(node);
        }
    }
    
    add_from_childs(root);
    std::cout << min_price;
    return 0;
}
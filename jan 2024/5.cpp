#include <iostream>
#include <vector>

class Node{
    public:
        int num;
        std::vector<Node*> nodes;
};

int go(Node* from, int to, int w){
    if (from->nodes.size() == 1)
        return -1;
    for (auto node: from->nodes){
        if (node->num == to)
            return node->num;
        if (node->num == w)
            continue;
        int res = go(node, to, from->num);
        if (res != -1)
            return node->num;
    }
}

int main(){
    int n, q;
    scanf("%d\n", &n);
    std::vector<Node*> tree(n);
    for (int i = 0; i < n; i++){
        tree[i] = new Node();
        tree[i]->num = i;
    }
    for (int i = 0; i < n - 1; i++){
        int u, v;
        scanf("%d %d\n", &u, &v);
        tree[u - 1]->nodes.push_back(tree[v - 1]);
        tree[v - 1]->nodes.push_back(tree[u - 1]);
    }
    scanf("%d\n", &q);
    for (int i = 0; i < q; i++){
        int from, to, room;
        scanf("%d %d\n", &from, &to);
        if (tree[from - 1]->nodes.size() == 1)
            room = tree[from - 1]->nodes[0]->num;
        else
            room = go(tree[from - 1], to - 1, from - 1);
        std::cout << room + 1 << std::endl;
    }
    return 0;
}

#include <iostream>
#include <vector>

class Child{
    public:
        unsigned long long count;
        std::vector<Child*> friends;
        
        void send(int x){
            for (Child* f: this->friends)
                f->add(x);
        }
        
        void add(int x){
            this->count += x;
        }
};

int main(){
    int n, m, q;
    scanf("%d %d %d\n", &n, &m, &q);
    std::vector<Child*> childs(n);
    for (int i = 0; i < n; i++){
        childs[i] = new Child();
        unsigned long long a;
        scanf("%llu ", &a);
        childs[i]->count = a;
    }
    scanf("\n");
    
    for (int i = 0; i < m; i++){
        int v, u;
        scanf("%d %d\n", &v, &u);
        childs[v - 1]->friends.push_back(childs[u - 1]);
        childs[u - 1]->friends.push_back(childs[v - 1]);
    }
    
    for (int i = 0; i < q; i++){
        const int max_length = 10;
        char cmd[max_length] {};
        std::cin.getline(cmd, max_length);
        char c = cmd[0];
        if (c == '+'){
            int v = atoi(&cmd[2]);
            int x = atoi(&cmd[4]);
            childs[v - 1]->send(x);
        }
        else if (c == '?'){
            int v = atoi(&cmd[2]);
            std::cout << childs[v - 1]->count << std::endl;
        }
    }
    return 0;
}
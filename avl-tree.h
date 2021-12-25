#ifndef AVL-TREE_H_INCLUDED
#define AVL-TREE_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class node{
public:
    int x, h, c;
    node* l;
    node* r;
    //Constructors
    node();
    node(int val);
    //Methods
    node* add(int val);
    node* del(int val);
    node* find(int val);
    void print(int d);
    //Get values
    int get_balance();
    node* find_min();
    node* remove_min();
    //Change structure
    node* rotate_left();
    node* rotate_right();
    node* balancing();
    void update();
};

node::node() {
    h = 0; x = 0; c = 0;
    l = nullptr;
    r = nullptr;
}

node::node(int val) {
    x = val; h = 1; c = 1;
    l = nullptr;
    r = nullptr;
}

int node::get_balance() {
    if (r == nullptr && l == nullptr) {
        return 0;
    }
    if (r == nullptr) {
        return -l->h;
    }
    if (l == nullptr) {
        return r->h;
    }
    return r->h - l->h;
}

void node::update() {
    if (l == nullptr && r == nullptr) {
        h = 1;
    } else if (l == nullptr) {
        h = 1 + r->h;
    } else if (r == nullptr) {
        h = 1 + l->h;
    } else {
        h = 1 + max(l->h, r->h);
    }
}

node* node::rotate_left() {
    node* right = r;
    r = right->l;
    right->l = this;
    update();
    right->update();
    return right;
}

node* node::rotate_right() {
    node* left = l;
    l = left->r;
    left->r = this;
    update();
    left->update();
    return left;
}

node* node::balancing() {
    update();
    if (get_balance() == 2) {
        if (r->get_balance() < 0) {
            r = r->rotate_right();
        }
        return rotate_left();
    } else if (get_balance() == -2) {
        if (l->get_balance() > 0) {
            l = l->rotate_left();
        }
        return rotate_right();
    } else {
        return this;
    }
}

node* node::add(int val) {
    if (h == 0) {
        x = val; h = 1; c = 1;
        return this;
    }
    if (val > x) {
        if (r == nullptr) {
            node* nw = new node(val);
            r = nw;
            return balancing();
        } else {
            r = r->add(val);
            return balancing();
        }
    } else if (val < x) {
        if (l == nullptr) {
            node* nw = new node(val);
            l = nw;
            return balancing();
        } else {
            l = l->add(val);
            return balancing();
        }
    } else {
        c++;
        return this;
    }
}

node* node::find_min() {
    if (h == 0) {
        return nullptr;
    }
    if (l == nullptr) return this;
    return l->find_min();
}

node* node::remove_min() {
    if (l == nullptr) {
        return r;
    }
    l = l->remove_min();
    return balancing();
}

node* node::del(int val) {
    if (h == 0) {
        return this;
    }
    if (x < val) {
        if (r == nullptr) return this;
        r = r->del(val);
        return balancing();
    } else if (x > val) {
        if (l == nullptr) return this;
        l = l->del(val);
        return balancing();
    } else {
        if (r == nullptr) return l;
        node* mi = r->find_min();
        mi->r = r->remove_min();
        mi->l = l;
        return mi->balancing();
    }
}

node* node::find(int val) {
    if (h == 0) {
        return nullptr;
    }
    if (x < val) {
        if (r == nullptr) return nullptr;
        return r->find(val);
    } else if (x > val) {
        if (l == nullptr) return nullptr;
        return l->find(val);
    } else {
        return this;
    }
}

void node::print(int d = 0) {
    if (h == 0) {
        return;
    }
    if (l != nullptr) {
        l->print(d + 1);
    }
    for(int i = 0; i < d; ++i) {
        cout << "   ";
    }
    cout << x << endl;
    if (r != nullptr) {
        r->print(d + 1);
    }
}

#endif // AVL-TREE_H_INCLUDED

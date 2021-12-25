#include <bits/stdc++.h>
#include "avl-tree.h"

using namespace std;

signed main() {
    node* root = new node();
    string s;
    cout << "Commands:\n";
    cout << "add x - add element x\nfind x - find element x\n";
    cout << "get_min - get minimum\ndel_min - delete minimum\n";
    cout << "del x - delete element x\nprint - print tree\nexit - stop program\n";
    while (cin >> s) {
        if (s == "add") {
            int x; cin >> x;
            root = root->add(x);
        } else if (s == "find") {
            int x; cin >> x;
            auto res = root->find(x);
            if (res == nullptr) {
                cout << "Not in\n";
            } else {
                cout << "In\n";
            }
        } else if (s == "get_min") {
            auto res = root->find_min();
            if (res == nullptr) {
                cout << "Not in\n";
            } else {
                cout << res->x << "\n";
            }
        } else if (s == "del_min") {
            if (root->h == 0) {
                cout << "Tree is empty\n";
            }
            root = root->remove_min();
        } else if (s == "del") {
            int x; cin >> x;
            auto res = root->find(x);
            if (res == nullptr) {
                cout << "Not in\n";
            } else {
                root = root->del(x);
            }
        } else if (s == "print") {
            root->print();
        } else {
            return 0;
        }
    }
}

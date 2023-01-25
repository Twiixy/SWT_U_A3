#include <iostream>
#include <chrono>
using namespace std;

using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;

class end_list {
    struct node {
        int load{};
        node* next = nullptr;
    }* root;
    // node* root;
public:
    explicit end_list(int load): root{new node{load}} { }

    void insert(int load) const {
        node *p = root;
        // while (p->next) { p=p->next; }
        for (node *pn; (pn=p->next) != nullptr; p = pn);
        p->next = new node{load};
    }

    int count() {
        int cnt = 1;
        for (node *p = root, *pn; (pn=p->next) != nullptr; p = pn, ++cnt);
        return cnt;
    }

    // note: clean up is missing, insert is not efficient, it creates cpu load
};

int main() {
    const auto N = 100000;
    cout << "cpp end_list, N:" << N << endl;

    end_list list(0);

    auto start = high_resolution_clock::now();
    for (auto i=1; i<=N; ++i)
        list.insert(i);
    auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - start);

    cout << "-> C++, duration: " << duration.count() << "ms, list.count: " << list.count() << endl;

    return 0;
}

/*
 * -> C++,    duration: 5819ms, list.count: 100001
 * -> C++,    duration: 4926ms, list.count: 100001  // cmdline, -Ofast / -O3
 *
 * -> Java,   duration: 7397ms, list.count: 100001
 * -> Kotlin, duration:: 7049ms, list.count: 100001
 *
 * btw: changing order provides similar results, i.e. Java and Kotlin play in the same league
 */

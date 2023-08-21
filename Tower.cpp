#include <iostream>
#include <memory>

struct Disk {
    int size;
};

class HanoiStack {
private:
    struct DiskNode {
        Disk x;
        std::unique_ptr<DiskNode> next = nullptr;
    };
    std::unique_ptr<DiskNode> top = nullptr;
    int size = 0;
    int maxSize = 0;

public:
    HanoiStack(int x);
    void push(Disk);
    Disk pop();
    Disk Top();
    void print() const;
    bool empty();
    int Topsize();
    bool isfull();
};

bool HanoiStack::empty() {
    return !top;
}

bool HanoiStack::isfull() {
    return size == maxSize;
}

void HanoiStack::print() const {
    DiskNode* cursor = top.get();
    while (cursor != nullptr) {
        std::cout << cursor->x.size;
        cursor = cursor->next.get();
    }
    std::cout << "<- Tower" << std::endl;
}

HanoiStack::HanoiStack(int x) : maxSize(x) {}

void HanoiStack::push(Disk t) {
    auto newDisk = std::make_unique<DiskNode>();
    newDisk->x = t;

    if (top) {
        newDisk->next = std::move(top);
    }
    top = std::move(newDisk);
    size++;
}

Disk HanoiStack::pop() {
    if (!top) {
        std::cout << "It's empty" << std::endl;
        return {0};
    }

    Disk a = top->x;
    top = std::move(top->next);
    size--;
    return a;
}

Disk HanoiStack::Top() {
    return top->x;
}

int HanoiStack::Topsize() {
    return top->x.size;
}

int main() {
    int move1 = 0;
    int move2 = 0;
    Disk a;
    a.size = 1;
    int n;

    std::cout << "Enter the number of disks you want to add" << std::endl;
    std::cin >> n;

    std::unique_ptr<HanoiStack> c = std::make_unique<HanoiStack>(n);
    std::unique_ptr<HanoiStack> d = std::make_unique<HanoiStack>(n);
    std::unique_ptr<HanoiStack> e = std::make_unique<HanoiStack>(n);

    a.size = n;
    for (int g = n; g >= 1; g--) {
        c->push(a);
        a.size = a.size - 1;
    }

    std::cout << std::endl;
    c->print();
    d->print();
    e->print();
    std::cout << std::endl;

    while (!e->isfull() || !d->isfull()) {
        // ... Your game logic ...
    }

    std::cout << "Congrats you win" << std::endl;
    return 0;
}

#include "signal.h"
#include "linked_list.h"

Node* signal_list = nullptr;

void try_init_signals() {
    if (signal_list == nullptr) {
        signal_list = create_list();
    }
}

void register_signal(CB c) {
    push_back(signal_list, (void*)c);
}

void call_signals(Node* l) {
    int le = len(signal_list);
    for(int i = 0; i<le; i++) {
        ((CB)get(signal_list, i))(l);
    }
}
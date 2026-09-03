#ifndef SIG
#define SIG
#include "linked_list.h"

typedef void (*CB)(Node* l); // CB = callback

void try_init_signals();

void register_signal(CB c);

void call_signals(Node* l);
#endif

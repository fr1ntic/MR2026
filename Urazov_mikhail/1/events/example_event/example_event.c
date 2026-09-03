#include <stdlib.h>
#include <stdio.h>

#include "../../types.h"
#include "../../linked_list.h"

#include "../__event.h"

EVENT_REGISTRATION(example, STAGE_YOUTH)

EVENT_CHECK(example) {
    printf("\nExample check!");
}

EVENT_RESULT(example) {
    printf("\nExample result!");
}
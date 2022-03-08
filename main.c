#include <stdio.h>

#include "libs/string/tests/test_string.h"
#include "libs/string/string_.h"
#include "libs/string/tests/test_string_tasks.h"
#include "libs/string/tasks/removeExtraSpaces.h"
#include "libs/string/tasks/printWordsInReverseOrder.h"


int main() {
    test_functions_string();
    test_string_tasks();

    char s1[] = "\0";

    printWordInReverseOrder(s1);

    char s2[] = "qw rt yu io as\0";

    printWordInReverseOrder(s2);

    return 0;
}

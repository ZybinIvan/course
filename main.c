#include <stdio.h>

#include "libs/string/tests/test_string.h"
#include "libs/string/string_.h"
#include "libs/string/tests/test_string_tasks.h"
#include "libs/string/tasks/removeExtraSpaces.h"
#include "libs/string/tasks/printWordsInReverseOrder.h"


int main() {
    test_functions_string();
    test_string_tasks();

    char s[] = "A\n";
    printWordBeforeFirstWordWithA(s);

    return 0;
}

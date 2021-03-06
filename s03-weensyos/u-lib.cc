#include "u-lib.hh"

// panic, assert_fail
//    Loop forever.

void panic(const char* format, ...) {
    va_list val;
    va_start(val, format);
    char buf[160];
    memcpy(buf, "PANIC: ", 7);
    int len = vsnprintf(&buf[7], sizeof(buf) - 7, format, val) + 7;
    va_end(val);
    if (len > 0 && buf[len - 1] != '\n') {
        strcpy(buf + len - (len == (int) sizeof(buf) - 1), "\n");
    }
    console_printf(CPOS(23, 0), 0xC000, "%s", buf);

    // should never get here
    while (true) {
    }
}

void assert_fail(const char* file, int line, const char* msg) {
    console_printf(CPOS(23, 0), 0xC000,
                   "PANIC: %s:%d: assertion '%s' failed\n",
                   file, line, msg);

    // should never get here
    while (true) {
    }
}

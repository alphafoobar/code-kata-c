#include <stdlib.h>
#include <time.h> // Import string format time.

// Build representation of now for logging.
struct tm *now() {
    time_t *timer = malloc(sizeof(time_t *));
    time(timer);
    return localtime(timer);
}

// Store string representation of time in a given char array.
// Creates pointer to time struct and frees pointer.
void initialize_now_string(char *result) {
    struct tm *const time_now = now();
    strftime(result, 26, "%Y-%m-%d %H:%M:%S", time_now);
    free(time_now);
}

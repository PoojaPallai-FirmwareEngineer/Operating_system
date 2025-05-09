// we created the thread with PTHREAD_CREATE_DETACHED attribute.
// Detached thread = you cannot join it anymore.
// Detached means the thread will clean up its resources by itself after finishing.
// There is no need (and no way) to call pthread_join() on a detached thread.
// If you still call pthread_join() on a detached thread:
// --> It will fail (pthread_join will return an error) or 
// --> The program may hang (waiting forever) depending on the system.
// 
// Therefore:
// 🔴 Do NOT use pthread_join() for a detached thread.
// ✅ Use pthread_join() only if the thread is created normally (without PTHREAD_CREATE_DETACHED).

// Case                  | pthread_attr                 | pthread_join
// --------------------------------------------------------------------
// Normal thread         | No attribute (NULL)          | ✅ pthread_join(id, NULL)
// Detached thread       | Set PTHREAD_CREATE_DETACHED  | ❌ No pthread_join


#include <stdio.h>
#include <pthread.h>

pthread_t id;
pthread_attr_t attr;

void *display(void *data)
{
    printf("This is a thread\n");
    return NULL;
} 

int main(int argc, char const* argv[])
{
    pthread_attr_init(&attr); // Initialize thread attributes
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); // Set thread as detached

    printf("Before Thread Creation\n");
    pthread_create(&id, &attr, display, NULL); // Create a detached thread

    pthread_attr_destroy(&attr); // Destroy the attribute object

    printf("After thread creation\n");

    sleep(10); // Give time for detached thread to complete before main thread exits

    return 0;
}


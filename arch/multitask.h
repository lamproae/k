
#ifndef __MULTITASK_H__
#define __MULTITASK_H__

#include "arch/paging.h"

typedef struct task_t {
    int id;
    uint32_t esp, ebp; // Stack and base pointers.
    uint32_t eip;      // Instruction pointer.
    page_directory *page_dir;
    struct task_t *next;
} task;

void initialise_tasking();
void switch_task();
int fork();

// Causes the current process' stack to be forcibly moved to a new location.
void move_stack(void *new_stack_start, uint32_t size);

#endif // __MULTITASK_H__

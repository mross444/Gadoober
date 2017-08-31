#define _CRT_SECURE_NO_WARNINGS

#ifndef TASK_H
#define TASK_H

#define TASK_NAME_SIZE 128
#define TASK_ARRAY_SIZE 10
#define FORMAT_LENGTH 256

typedef struct Task Task;

struct Task
{
    int priority;
    char name[TASK_NAME_SIZE];
};

Task* taskNew(int priority, char* name);
void taskDelete(Task* task);
int taskCompare(void* left, void* right);
void taskPrint(void* value);

#endif /* TASK_H */


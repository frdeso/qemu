#ifndef _FREEZER_H_
#define _FREEZER_H_
#include <semaphore.h>

void freezer_sem_init(void);
void freezer_sem_post(void);
void freezer_sem_wait(void);

#endif // _FREEZER_H_

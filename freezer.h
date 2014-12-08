#ifndef _FREEZER_H_
#define _FREEZER_H_
#include <semaphore.h>
void freezer_prod_sem_init(void);
void freezer_prod_sem_post(void);
int freezer_prod_sem_trywait(void);


void freezer_cons_sem_init(void);
void freezer_cons_sem_post(void);
void freezer_cons_sem_wait(void);

#endif // _FREEZER_H_

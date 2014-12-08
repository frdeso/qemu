#include "freezer.h"
#include "trace.h"
static sem_t prod_sem;
static sem_t cons_sem;

void freezer_prod_sem_init(void)
{
	sem_init(&prod_sem, 0 , 0);
}
void freezer_prod_sem_post(void)
{
	sem_post(&prod_sem);
	trace_freezer_prod_post();
}
int freezer_prod_sem_trywait(void)
{
	int ret = sem_trywait(&prod_sem);
	trace_freezer_prod_trywait(ret);
	return ret;
}

void freezer_cons_sem_init(void)
{
	sem_init(&cons_sem, 0 , 0);
}
void freezer_cons_sem_post(void)
{
	trace_freezer_cons_post_before();
	sem_post(&cons_sem);
	trace_freezer_cons_post_after();
}
void freezer_cons_sem_wait(void)
{
	trace_freezer_cons_wait_before();
	sem_wait(&cons_sem);
	trace_freezer_cons_wait_after();
}

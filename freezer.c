#include "freezer.h"
#include "trace.h"
static sem_t sem;

void freezer_sem_init(void)
{
	int val;
	sem_init(&sem, 0 , 0);
	sem_getvalue(&sem, &val);
	trace_freezer_sem_init(val);
}
void freezer_sem_post(void)
{
	trace_freezer_sem_post_before();
	sem_post(&sem);
	trace_freezer_sem_post_after();
}
void freezer_sem_wait(void)
{
	trace_freezer_sem_wait_before();
	sem_wait(&sem);
	trace_freezer_sem_wait_after();
}

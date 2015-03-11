#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

enum {
	NOMBRE_TAREA_attr=0,
	USUARIO_TAREA_attr,
	DESC_TAREA_attr,
	PRIORIDAD_TAREA_attr,
	ID_TAREA_attr,
	__TAREA_attr_MAX
};

#define __TAREA_MAX (__TAREA_MAX - 1)

#define xfree(ptr)	free((void *)ptr);//?¿?¿¿¿

typedef struct tarea;

struct tarea *alloc_tarea(void);
void free_tarea(struct tarea * t);
bool is_set_tarea(const struct tarea *t,uint16_t attr);
const void *curso_tarea_attr_get_data(struct tarea *t, uint16_t attr);
uint32_t curso_tarea_attr_get_u32(struct tarea *t, uint16_t attr);
const char *curso_tarea_attr_get_str(struct tarea *t, uint16_t attr);
void set_tarea_data_len(struct tarea *t,uint16_t attr,uint32_t data);//?¿¿?¿? mas parametros?
void set_tarea_data(struct tarea *t, uint16_t attr, const void *data,uint32_t data_len);
void set_tarea_u32(struct tarea *t, uint16_t attr, uint32_t data);
void  unset_tarea(struct tarea *t,uint16_t attr);
int imprimir_tarea_snprintf(char *buf,size_t size,struct tarea *t);


#include "tarea.h"

enum {
	CURSO_GESTOR_ATTR_TAREA,
	CURSO_GESTOR_ATTR_NUM_TAREAS,
	__CURSO_GESTOR_ATTR_MAX
};

#define CURSO_GESTOR_ATTR_MAX (__CURSO_GESTOR_ATTR_MAX - 1)

struct gestor_tarea;

struct gestor_tarea *curso_gestor_alloc(void);
void curso_gestor_free(struct gestor_tarea *);
void curso_gestor_attr_unset_tarea(struct gestor_tarea *ges, uint32_t pos);
void curso_gestor_attr_set_str(struct gestor_tarea *ges, uint16_t attr, const char *data);
void curso_gestor_attr_set_tarea(struct gestor_tarea *ges, uint16_t attr, struct tarea *t);
uint32_t curso_gestor_attr_get_u32(struct gestor_tarea *ges, uint16_t attr);
const char *curso_gestor_attr_get_str(struct gestor_tarea *ges, uint16_t attr);
struct tarea *curso_gestor_attr_get_tarea(struct gestor_tarea *ges, uint16_t attr, uint32_t pos);
int curso_gestor_snprintf(char *buf, size_t size, struct gestor_tarea *ges);


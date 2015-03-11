#include "tarea.h"
#include <string.h>

struct tarea
{
        char  *nombre_tarea;
        char  *desc_tarea;
        uint32_t id;
        char *usuario;
        uint32_t prioridad;
	
	uint32_t flags;
};

struct tarea *tarea_alloc(void)
{
	return (struct tarea *)malloc(sizeof(struct tarea));
}

void free_tarea(struct tarea * t)
{
	if (t->flags & (1 << NOMBRE_TAREA_attr))
		xfree(t->nombre_tarea);

	if (t->flags & (1 << USUARIO_TAREA_attr))
		xfree(t->usuario);

	if(t->flags &(1 << DESC_TAREA_attr))
		xfree(t->desc_tarea);

	xfree(t);
}
bool is_set_tarea(const struct tarea * t,uint16_t attr)
{

	return t->flags & (1 << attr);
}

const void *curso_tarea_attr_get_data(struct tarea *t, uint16_t attr)
{
	if (!(t->flags & (1 << attr)))
		return NULL;
	
	switch (attr) {
	case NOMBRE_TAREA_attr:
		return t->nombre_tarea;
	case DESC_TAREA_attr:
		return t->desc_tarea;
	case USUARIO_TAREA_attr:
		return t->usuario;
	case ID_TAREA_attr:
		return &t->id;
	case PRIORIDAD_TAREA_attr:
		return &t->prioridad;
	}
	return NULL;
}
uint32_t curso_tarea_attr_get_u32(struct tarea *t, uint16_t attr)
{
	const void *ret = curso_tarea_attr_get_data(t, attr);
	return ret == NULL ? 0 : *((uint32_t *)ret);

}

const char *curso_tarea_attr_get_str(struct tarea *t, uint16_t attr)
{
	return curso_tarea_attr_get_data(t, attr);
}

void set_tarea_data_len(struct tarea *t,uint16_t attr,const void *data,uint32_t data_len)
{
	if(attr > __TAREA_attr_MAX)
		return;

	switch (attr){
	case NOMBRE_TAREA_attr:
		if(t->nombre_tarea)
			xfree(t->nombre_tarea);

		t->nombre_tarea = strdup(data);
		break;
	case USUARIO_TAREA_attr:
		if(t->usuario)
			xfree(t->usuario);
		
		t->usuario = strdup(data);
		break;
	case DESC_TAREA_attr:
		if(t->desc_tarea)
			xfree(t->desc_tarea);

		t->desc_tarea = strdup(data);
		break;
	case ID_TAREA_attr:
		 t->id = *((uint32_t *)data);
                 break;
	case PRIORIDAD_TAREA_attr:
		t->prioridad = *((uint32_t *)data);
		break;
	}	  
        t->flags |= (1 << attr);
}

void set_tarea_data(struct tarea *t, uint16_t attr, const void *data)
{
	set_tarea_data_len(t, attr, data, 0);
}

void set_tarea_u32(struct tarea *t, uint16_t attr, uint32_t data)
{
	set_tarea_data_len(t, attr, &data, sizeof(uint32_t));
}

void unset_tarea(struct tarea *t, uint16_t attr)
{
	if(!(t->flags & (1 << attr)))
		return;

	switch(attr){
	case NOMBRE_TAREA_attr:
		if(t->nombre_tarea){
			xfree(t->nombre_tarea);
			t->nombre_tarea = NULL;
		}
		break;
	case USUARIO_TAREA_attr:
		if(t->usuario){
			xfree(t->usuario);
			t->usuario = NULL;
		}
		break;
	case DESC_TAREA_attr:
		if(t->desc_tarea){
			xfree(t->desc_tarea);
			t->desc_tarea = NULL;
		}
		break;
	case ID_TAREA_attr:
		break;
	case PRIORIDAD_TAREA_attr:
		break;

	}
	//trasladar un bit para AND conjugado??
	t->flags &= ~(1 << attr);
}

int imprimir_tarea(char *buf,size_t size,struct tarea *t)
{

	int i,ret = 0;
	
	ret = snprintf(buf,size,"La tarea número %d  está enviada por %s. Se llama %s y la descripción es %s \n",
								t->id,t->usuario,t->nombre_tarea,t->desc_tarea);
	return ret;
}

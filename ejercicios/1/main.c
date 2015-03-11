#include "tarea.h"

int main(void)
{
	struct tarea * tarea1;
	char info[500];

	tarea1 = tarea_alloc();

	set_tarea_data(t1, NOMBRE_TAREA_attr, "COMPRAR PAN");
	set_tarea_data(t1, USUARIO_TAREA_attr, "CARLOS_PEREZ");
	set_tarea_data(t1, DESC_TAREA_attr, "5 ANDALUZAS");
	set_tarea_u32(t1, CURSO_TAREA_ATTR_ID, 0);
	set_tarea_u32(t1, CURSO_TAREA_ATTR_PRIORIDAD, 0);

	imprimir_tarea(info, sizeof(info), t1);
	printf("INFORMACION RESPECTO A LA TAREA %s : %s\n",t1->NOMBRE_TAREA_attr, info);

	free_tarea(t1);
	return 0;
}

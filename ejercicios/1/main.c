#include "tarea.h"

int main(void)
{
	struct tarea * tarea1;
	char info[500];

	tarea1 = tarea_alloc();

	set_tarea_data(tarea1, NOMBRE_TAREA_attr, "COMPRAR PAN");
	set_tarea_data(tarea1, USUARIO_TAREA_attr, "CARLOS_PEREZ");
	set_tarea_data(tarea1, DESC_TAREA_attr, "5 ANDALUZAS");
	set_tarea_u32(tarea1, ID_TAREA_attr, 0);
	set_tarea_u32(tarea1, PRIORIDAD_TAREA_attr, 0);

	imprimir_tarea(info, sizeof(info), tarea1);
	printf("INFORMACION RESPECTO A LA TAREA: %s\n",info);

	free_tarea(tarea1);
	return 0;
}

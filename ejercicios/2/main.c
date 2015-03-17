#include "gestor_tarea.h"

int main(void)
{
	struct tarea *tarea1, *tarea2, *tarea3;
	struct gestor_tarea *gest;
	char info[4000];

	tarea1 = curso_tarea_alloc();

	curso_tarea_attr_set_str(tarea1, CURSO_TAREA_ATTR_NOMBRE, "COMPRA");
	curso_tarea_attr_set_str(tarea1, CURSO_TAREA_ATTR_DES, "Hacer la compra en el mercadona");
	curso_tarea_attr_set_u32(tarea1, CURSO_TAREA_ATTR_ID, 4);
	curso_tarea_attr_set_str(tarea1, CURSO_TAREA_ATTR_USUARIO, "Alberto");
	curso_tarea_attr_set_u32(tarea1, CURSO_TAREA_ATTR_PRIORIDAD, 1);

	tarea2 = curso_tarea_alloc();

	curso_tarea_attr_set_str(tarea2, CURSO_TAREA_ATTR_NOMBRE, "LAVAVAJILLAS");
	curso_tarea_attr_set_str(tarea2, CURSO_TAREA_ATTR_DES, "Poner lavavajillas despues de almorzar");
	curso_tarea_attr_set_u32(tarea2, CURSO_TAREA_ATTR_ID, 3);
	curso_tarea_attr_set_str(tarea2, CURSO_TAREA_ATTR_USUARIO, "Jaime");
	curso_tarea_attr_set_u32(tarea2, CURSO_TAREA_ATTR_PRIORIDAD, 0);

	tarea3 = curso_tarea_alloc();

	curso_tarea_attr_set_str(tarea3, CURSO_TAREA_ATTR_NOMBRE, "BOMBILLAS");
	curso_tarea_attr_set_str(tarea3, CURSO_TAREA_ATTR_DES, "Ir a a la ferretería");
	curso_tarea_attr_set_u32(tarea3, CURSO_TAREA_ATTR_ID, 1);
	curso_tarea_attr_set_str(tarea3, CURSO_TAREA_ATTR_USUARIO, "Jose");
	curso_tarea_attr_set_u32(tarea3, CURSO_TAREA_ATTR_PRIORIDAD, 2);

	gest = curso_gestor_alloc();


	curso_gestor_attr_set_tarea(gest, CURSO_GESTOR_ATTR_TAREA,
					   tarea1);

	curso_gestor_attr_set_tarea(gest, CURSO_GESTOR_ATTR_TAREA,
					   tarea2);

	curso_gestor_attr_set_tarea(gest, CURSO_GESTOR_ATTR_TAREA,
					   tarea3);

	curso_gestor_snprintf(info, sizeof(info), gest);
	printf("%s", info);

	curso_gestor_attr_unset_tarea(gest, 2);

	curso_gestor_snprintf(info, sizeof(info), gest);
	printf("%s", info);
	
	curso_gestor_free(gest);
	return 0;
}

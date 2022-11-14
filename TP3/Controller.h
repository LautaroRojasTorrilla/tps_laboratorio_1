int controller_buscaMaxId(LinkedList* pArrayListJugador);

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
int controller_agregarJugador(LinkedList* pArrayListJugador);
int controller_editarJugador(LinkedList* pArrayListJugador);
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_listarJugadores(LinkedList* pArrayListJugador);
int controller_listarJugadoresConPais(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_listarJugadoresConvocadosConPais(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_convocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_buscarJugID(LinkedList* pArrayListJugador, char* mensaje, char* mensajeError);
int controller_cargarJugIDModoTexto(char* path, char* id);

int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_buscarSelID(LinkedList* pArrayListSeleccion, char* mensaje, char* mensajeError);





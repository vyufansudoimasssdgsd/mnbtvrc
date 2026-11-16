#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//revisar unistd.h sleep(1)

typedef struct
{
	char nombre[30];
	char tipo[20];
	float poder;
	int costo_energia; //restar a PE
} ataque;

typedef struct
{
	char nombre[30];
	char tipo[20];
	float PV; //PV, puntos vida
	int PE; //PE, puntos energia
	ataque mov_1;
	ataque mov_2;
	int ind_1;
	int ind_2;
} pokemon;

ataque* leer_ataques(int *tamano_at)
{
	//10. Implemente una funcion leer_ataques()
	//que genere un array de 25 ataques, a partir del archivo ataques.txt.

	//crear vector dinamico
	ataque *vector_ataques = NULL;

	//abrir archivo
	FILE *archivo = fopen("ataques.txt","rt");
	if(archivo == NULL) {
		printf("ERROR AL LEER ATAQUES, REVISAR CODIGO\n");
		return NULL; //revisar que esto se pueda
	}

	//leer cada parte con fscanf
	ataque temporal_at;
	int size_vector=-1;
	while ( fscanf(archivo, "%s %s %f %i",
	               temporal_at.nombre,temporal_at.tipo, //guardar en temporal
	               &temporal_at.poder,&temporal_at.costo_energia) == 4 )
	{
		//size ++
		size_vector++;

		//realloc
		ataque *temporal_fallo = (ataque *) realloc (vector_ataques,sizeof(ataque) * (size_vector+1) );
		if(temporal_fallo == NULL) {
			free(vector_ataques);
			return NULL; //revisar si se puede esto y antes
		}

		vector_ataques = temporal_fallo;
		//guardar array de ataques de f(x)
		vector_ataques[size_vector] = temporal_at;
	} //Agregar lo de feof

	//cerrar el archivo
	fclose(archivo);

	//guardar tamano_at
	*tamano_at=size_vector+1;

	//devlver el vector lleno
	return vector_ataques;

}

pokemon* leer_pokedex( ataque vector_ataques[], int* tamano_p)
{
	//crear vector dinamico
	pokemon *vector_pokemon = NULL;

	//abrir archivo
	FILE *archivo = fopen("pokedex_gen1.txt","rt");
	if(archivo == NULL) {
		printf("ERROR AL LEER POKEDEX, REVISAR CODIGO\n");
		return NULL;
	}

	//leer cada parte con fscanf porque es siempre mismo orden
	pokemon temporal_pk; //guardar en temporal
	int size_vector=-1;
	while ( fscanf(archivo, "%s %s %f %i %i %i",
	               temporal_pk.nombre,temporal_pk.tipo,
	               &temporal_pk.PV,&temporal_pk.PE,&temporal_pk.ind_1, &temporal_pk.ind_2) == 6 )
	{
		//size ++
		size_vector++;

		//realloc del vector dinamico
		pokemon *temporal_fallo = (pokemon *) realloc (vector_pokemon,sizeof(pokemon) * (size_vector+1) );
		if(temporal_fallo == NULL) {
			free(vector_pokemon);
			return NULL; //revisar si se puede esto y antes
		}
		//guardar dinamico si salio bien el realloc
		vector_pokemon = temporal_fallo;

		//guardar 2 ataques de los pokemones en el temporal
		temporal_pk.mov_1=vector_ataques[temporal_pk.ind_1];
		temporal_pk.mov_2=vector_ataques[temporal_pk.ind_2];

		//guardar temporal en vector dinamico con todos los pokemones
		vector_pokemon[size_vector] = temporal_pk;
	}

	//cerrar el archivo
	fclose(archivo);

	//tamano_p
	*tamano_p=size_vector+1;

	//devlver el vector lleno
	return vector_pokemon;

}

pokemon* buscar_pokemon(pokemon vector_pokemon[], char p_ingresado[], int tamano_p)
{
	for(int i=0; i<tamano_p; i++) {
		//si el nombre ingresado y del pokemon calzan...
		if(strcmp(vector_pokemon[i].nombre,p_ingresado) == 0) {
			return &vector_pokemon[i];
		}
	}
	return NULL;
}

void mostrarEstado(pokemon vector_pokemon[], char p_ingresado[], int tamano_p)
{
	//buscar en el vector de pokedex al pokemon
	int flag_encontrado = 0;
	pokemon *pokemon_puntero = buscar_pokemon(vector_pokemon,p_ingresado,tamano_p);
	if(pokemon_puntero != NULL) flag_encontrado = 1;

	if(flag_encontrado) {
		pokemon pokemon_struct = *pokemon_puntero;
		if(pokemon_struct.PV < 0)printf("EL pokemon %s, de tipo %s , tiene PS = 0.00 y PE %i\n",pokemon_struct.nombre,pokemon_struct.tipo,pokemon_struct.PE);
		else printf("EL pokemon %s, de tipo %s , tiene PS = %.2f y PE %i\n",pokemon_struct.nombre,pokemon_struct.tipo,pokemon_struct.PV,pokemon_struct.PE);
		printf("mov_1 = %s , tipo %s , poder %.2f, CE %i \n",pokemon_struct.mov_1.nombre,pokemon_struct.mov_1.tipo,pokemon_struct.mov_1.poder,pokemon_struct.mov_1.costo_energia);
		printf("mov_2 = %s , tipo %s , poder %.2f, CE %i \n\n",pokemon_struct.mov_2.nombre,pokemon_struct.mov_2.tipo,pokemon_struct.mov_2.poder,pokemon_struct.mov_2.costo_energia);
	}
	else printf("El pokemon no fue encontrado o el nombre fue escrito de manera incorrecta\n");

}

int tipo_segun_clima(char tipo_mov[],int clima)
{
	if(clima == 0) { //0 = soleado
		if(strcmp(tipo_mov,"planta") == 0)return 1;
		if(strcmp(tipo_mov,"fuego") == 0)return 1;
		if(strcmp(tipo_mov,"tierra") == 0)return 1;
		if(strcmp(tipo_mov,"volador") == 0)return 1;
		if(strcmp(tipo_mov,"dragon") == 0)return 1;
	}
	if(clima == 1) { // 1 = Lluvioso
		if(strcmp(tipo_mov,"agua") == 0)return 1;
		if(strcmp(tipo_mov,"electrico") == 0)return 1;
		if(strcmp(tipo_mov,"insecto") == 0)return 1;
	}
	if(clima == 2) { // 2 = Semi_nublado
		if(strcmp(tipo_mov,"normal") == 0)return 1;
		if(strcmp(tipo_mov,"roca") == 0)return 1;
		if(strcmp(tipo_mov,"psiquico") == 0)return 1;
		if(strcmp(tipo_mov,"fantasma") == 0)return 1;
	}
	if(clima == 3) { // 3 = Nublado
		if(strcmp(tipo_mov,"hada") == 0)return 1;
		if(strcmp(tipo_mov,"lucha") == 0)return 1;
		if(strcmp(tipo_mov,"veneno") == 0)return 1;
		if(strcmp(tipo_mov,"hielo") == 0)return 1;
	}
	return 0;
}

void simular_ataque(pokemon *p1, pokemon *p2, int mov_elegido, int clima)
{
	if(mov_elegido == 1) {
		if( (p1->PE - p1->mov_1.costo_energia) >= 0) {
			//restar PE al atacante
			p1->PE-=p1->mov_1.costo_energia;
			printf("Le quedan %i PE al pokemon %s\n",p1->PE,p1->nombre);

			//ver potenciar_clima
			int potenciar_clima = tipo_segun_clima(p1->mov_1.tipo,clima);
			if(potenciar_clima)printf("Se potencio el ataque gracias al clima\n");

			//restar vida al defensor
			if(potenciar_clima) p2->PV-=((p1->mov_1.poder)*(1.5));
			else p2->PV-=p1->mov_1.poder;

			//imprimir mensaje (CORREGIDO)
			if(potenciar_clima) printf("El pokemon %s ataco con %s a %s, realizando %.2f de daño\n",p1->nombre,p1->mov_1.nombre,p2->nombre,(p1->mov_1.poder)*(1.5));
			else printf("El pokemon %s ataco con %s a %s, realizando %.2f de daño\n",p1->nombre,p1->mov_1.nombre,p2->nombre,p1->mov_1.poder);
		}
		else {
			printf("El pokemon no tiene suficiente PE, por lo que ocupa COMBATE\n");

			//ver potenciar_clima de combate
			int potenciar_clima = tipo_segun_clima("normal",clima);
			if(potenciar_clima)printf("Se potencio el ataque gracias al clima\n");

			//restar vida al defensor
			if(potenciar_clima) p2->PV-=15;
			else p2->PV-=10;

			//restar vida al atacante
			p1->PV-=5;

			//imprimir mensaje
			if(potenciar_clima) printf("El pokemon %s ataco con COMBATE a %s, realizando %.2f de daño\n",p1->nombre,p2->nombre,15.0);
			else printf("El pokemon %s ataco con COMBATE a %s, realizando %.2f de daño\n",p1->nombre,p2->nombre,10.0);
			printf("Oh no, el pokemon se ha hecho 5 de daño a si mismo\n");
		}
	}
	else if (mov_elegido == 2) {
		//mov_2

		if( (p1->PE - p1->mov_2.costo_energia) >= 0) {
			//restar PE al atacante
			p1->PE-=p1->mov_2.costo_energia;
			printf("Le quedan %i PE al pokemon %s\n",p1->PE,p1->nombre);

			//ver potenciar_clima
			int potenciar_clima = tipo_segun_clima(p1->mov_2.tipo,clima);
			if(potenciar_clima)printf("Se potencio el ataque gracias al clima\n");

			//restar vida al defensor
			if(potenciar_clima) p2->PV-=((p1->mov_2.poder)*(1.5));
			else p2->PV-=p1->mov_2.poder;

			//imprimir mensaje
			if(potenciar_clima) printf("El pokemon %s ataco con %s a %s, realizando %.2f de daño\n",p1->nombre,p1->mov_2.nombre,p2->nombre,(p1->mov_2.poder)*(1.5));
			else printf("El pokemon %s ataco con %s a %s, realizando %.2f de daño\n",p1->nombre,p1->mov_2.nombre,p2->nombre,p1->mov_2.poder);
		}
		else {
			printf("El pokemon no tiene suficiente PE, por lo que ocupa COMBATE\n");

			//ver potenciar_clima de combate
			int potenciar_clima = tipo_segun_clima("normal",clima);
			if(potenciar_clima)printf("Se potencio el ataque gracias al clima\n");

			//restar vida al defensor
			if(potenciar_clima) p2->PV-=15;
			else p2->PV-=10;

			//restar vida al atacante
			p1->PV-=5;

			//imprimir mensaje
			if(potenciar_clima) printf("El pokemon %s ataco con COMBATE a %s, realizando %.2f de daño\n",p1->nombre,p2->nombre,15.0);
			else printf("El pokemon %s ataco con COMBATE a %s, realizando %.2f de daño\n",p1->nombre,p2->nombre,10.0);
			printf("Oh no, el pokemon %s se ha hecho 5 de daño a si mismo\n",p1->nombre);
		}

	}
}

void simularCombate(pokemon *p1, pokemon *p2, pokemon vector_pokemon[], int tamano_p)
{
	//sale un clima random por combate
	int clima=rand()%4;
	if (clima == 0) printf("[CLIMA ACTUAL: SOLEADO]\n");
	if (clima == 1) printf("[CLIMA ACTUAL: LLUVIOSO]\n");
	if (clima == 2) printf("[CLIMA ACTUAL: SEMI-NUBLADO]\n");
	if (clima == 3) printf("[CLIMA ACTUAL: NUBLADO]\n");

	//ocupar contador par o impar para decidir de quien es el turno
	int turno=0;
	int mov_elegido;
	int flag_ko=1;

	//guardar PV y PE antes del combate para luego curarlos

	float PV_de_p1 = p1->PV;
	int PE_de_p1 = p1->PE;
	float PV_de_p2 = p2->PV;
	int PE_de_p2 = p2->PE;

	while (flag_ko) { //mientras uno siga vivo
		if(turno%2 == 0) { // turno p1
			printf("\nEs el turno del pokemon %s \nPV=%.2f-----PE=%i\n",p1->nombre,p1->PV,p1->PE);
			printf("1-%s tipo %s (ATK=%.2F|CE=%i)\n",p1->mov_1.nombre,p1->mov_1.tipo,p1->mov_1.poder,p1->mov_1.costo_energia);
			printf("2-%s tipo %s (ATK=%.2F|CE=%i)\n",p1->mov_2.nombre,p1->mov_2.tipo,p1->mov_2.poder,p1->mov_2.costo_energia); // CORREGIDO
			do {
				printf("Elijo... (-1 para terminar): ");
				
				// Si scanf no lee un numero
				if (scanf("%i", &mov_elegido) != 1) {
					while(getchar() != '\n'); // Limpia el buffer
					mov_elegido = 0; // Le damos un valor inválido
				}
				
				// El bucle se repite si el valor es distinto de 1 Y de 2 Y de -1
				// por lo tanto solo puede salir si cumple alguna de las 3
			} while (mov_elegido != 1 && mov_elegido != 2 && mov_elegido != -1);
			
			if(mov_elegido != -1) {
				simular_ataque(p1,p2,mov_elegido,clima);
			}
			else if(mov_elegido == -1) {
				printf("Combate finalizado de manera prematura\n");
				flag_ko=0; //aca funciona
			}

			if (p2->PV <= 0)flag_ko=0;
			if (p1->PV <= 0)flag_ko=0;
		}
		else { //turno p2
			printf("\nEs el turno del pokemon %s \nPV=%.2f-----PE=%i\n",p2->nombre,p2->PV,p2->PE);
			printf("1-%s tipo %s (ATK=%.2F|CE=%i)\n",p2->mov_1.nombre,p2->mov_1.tipo,p2->mov_1.poder,p2->mov_1.costo_energia);
			printf("2-%s tipo %s (ATK=%.2F|CE=%i)\n",p2->mov_2.nombre,p2->mov_2.tipo,p2->mov_2.poder,p2->mov_2.costo_energia);
			
			// CORREGIDO: Eliminado el printf duplicado de "Elijo..." que estaba aquí antes
			do {
				printf("Elijo... (-1 para terminar): ");
				
				if (scanf("%i", &mov_elegido) != 1) {
					while(getchar() != '\n');
					mov_elegido = 0;
				}
				
			} while (mov_elegido != 1 && mov_elegido != 2 && mov_elegido != -1);
			
			if(mov_elegido != -1) {
				simular_ataque(p2,p1,mov_elegido,clima);
			}
			else if(mov_elegido == -1) {
				printf("Combate finalizado de manera prematura\n");
				flag_ko=0;
			}
            if (p1->PV <= 0)flag_ko=0;
            if (p2->PV <= 0)flag_ko=0;
		}
		turno++;
	}


	//si p1 o p2 se debilita
	if(p1->PV <=0)printf("El pokemon %s esta KO, ha ganado %s\n",p1->nombre,p2->nombre);
	else printf("El pokemon %s tiene PV=%.2f\n",p1->nombre,p1->PV);

	if(p2->PV <=0)printf("El pokemon %s esta KO, ha ganado %s\n",p2->nombre,p1->nombre);
	else printf("El pokemon %s tiene PV=%.2f\n",p2->nombre,p2->PV);

	//restaurar vida y PE para el proximo combate
	p1->PV = PV_de_p1;
	p1->PE = PE_de_p1;
	p2->PV = PV_de_p2;
	p2->PE = PE_de_p2;

}

int sumar_pokemon(pokemon *vector_pokemon, int tamano_p)
{
    int flag_encontrado=1; //empieza true 
    pokemon nuevo_pokemon; //struct temporal
    
    //escanear el nombre
    printf("ingrese el nombre a ingresar a la pokedex del pokemon: ");
    scanf(" %29[^\n]",nuevo_pokemon.nombre);
    
    //el tipo, que coinicida con los existentes
    printf("Tipos disponibles:\n-----Soleado:\nplanta\nfuego\ntierra\ndragon\nvolador\n");
    printf("-----Lluvioso:\nagua\nelectrico\ninsecto\n");
    printf("-----Semi-Nublado:\nnormal\nroca\npsiquico\nfantasma\n");
    printf("-----Nublado:\nhada\nlucha\nveneno\nhielo\n");
    printf("ingrese el tipo del pokemon a ingresar a la pokedex del pokemon:");
    
    do{
        scanf(" %29[^\n]",nuevo_pokemon.tipo);
        //ver si coincide con los tipos existentes
		if(strcmp(nuevo_pokemon.tipo,"planta") == 0)flag_encontrado = 0;
		if(strcmp(nuevo_pokemon.tipo,"fuego") == 0)flag_encontrado = 0;
		if(strcmp(nuevo_pokemon.tipo,"tierra") == 0)flag_encontrado = 0;
		if(strcmp(nuevo_pokemon.tipo,"volador") == 0)flag_encontrado = 0;
		if(strcmp(nuevo_pokemon.tipo,"dragon") == 0)flag_encontrado = 0;
		if(strcmp(nuevo_pokemon.tipo,"agua") == 0)flag_encontrado = 0;
		if(strcmp(nuevo_pokemon.tipo,"electrico") == 0)flag_encontrado = 0;
		if(strcmp(nuevo_pokemon.tipo,"insecto") == 0)flag_encontrado = 0;
		if(strcmp(nuevo_pokemon.tipo,"normal") == 0)flag_encontrado = 0;
		if(strcmp(nuevo_pokemon.tipo,"roca") == 0)flag_encontrado = 0;
		if(strcmp(nuevo_pokemon.tipo,"psiquico") == 0)flag_encontrado = 0;
		if(strcmp(nuevo_pokemon.tipo,"fantasma") == 0)flag_encontrado = 0;
		if(strcmp(nuevo_pokemon.tipo,"hada") == 0)flag_encontrado = 0;
		if(strcmp(nuevo_pokemon.tipo,"lucha") == 0)flag_encontrado = 0;
		if(strcmp(nuevo_pokemon.tipo,"veneno") == 0)flag_encontrado = 0;
		if(strcmp(nuevo_pokemon.tipo,"hielo") == 0)flag_encontrado = 0;
		//si no, printear mensaje de reintentar
		if(flag_encontrado)printf("El tipo no existe o esta mal escrito, vuelva a intentarlo ");
    }while (flag_encontrado);
    
    //PV <= 550 PE <= 130
    do{
        printf("Ingrese los PV del pokemon (Max 550) ");
        scanf("%f",&nuevo_pokemon.PV);
    }while(nuevo_pokemon.PV > 550 || nuevo_pokemon.PV < 0);
    
    do{
        printf("Ingrese los PE de del pokemon (Max 130) ");
        scanf("%i",&nuevo_pokemon.PE);
    }while(nuevo_pokemon.PE > 130 || nuevo_pokemon.PE < 0);
    
    //printear lista de ataques
    
    printf("Ataques disponibles:\n");
    
    FILE *archivo= fopen("ataques.txt","rt");
    if(archivo == NULL) return -1;
    
    int i=0;
    ataque temporal_print; //crear temporal ataque
    
    while (fscanf(archivo,"%s %s %f %i",temporal_print.nombre,temporal_print.tipo,&temporal_print.poder,&temporal_print.costo_energia) == 4){
        printf("%i- %s %s %.0f %i\n",i,temporal_print.nombre,temporal_print.tipo,temporal_print.poder,temporal_print.costo_energia);
        i++;
    }
    
    
    
    //que ingrese el numero de index del ataque y de ahi ctr c a lo de pokedex 
    
    
}

int main()
{
	srand(time(NULL));

	int input_usuario;
	int tamano_p;
	int tamano_at;

	//leer ataque de txt
	ataque *vector_ataques = leer_ataques(&tamano_at);
	if( vector_ataques == NULL) return EXIT_FAILURE;

	//leer pokedex
	pokemon *vector_pokemon = leer_pokedex(vector_ataques, &tamano_p);
	if( vector_pokemon == NULL) return EXIT_FAILURE;

	do {
		printf("\n-----------------MENU----POKEMON-----------------\n");
		printf("1-Agregar Pokemon (disponible gen1,2,3)\n");
		printf("2-Ver estado pokemon elegido\n");
		printf("3-Combatir pokemones\n");
		printf("4-Terminar ejecucion\nElijo... ");

		if (scanf("%i", &input_usuario) != 1) {
			while(getchar() != '\n'); // Limpia el buffer
			input_usuario = 0; // Para que no se salga
		}

		if(input_usuario == 1) {
			printf("funicon por añadir\n");
			sumar_pokemon(vector_pokemon,tamano_p);
		}
		if(input_usuario == 2) {
			char pokemon_elegido[30];
			printf("Que pokemon desea ver (Ej: Cubone) ");
			scanf(" %29[^\n]",pokemon_elegido);
			mostrarEstado(vector_pokemon,pokemon_elegido,tamano_p);
		}
		if(input_usuario == 3) {
			char pokemon_elegido_1[30];
			char pokemon_elegido_2[30];

			printf("Ingrese pokemon_1 (atacante) ");
			scanf(" %29[^\n]",pokemon_elegido_1);

			//buscar los pokemones ingresados
			pokemon *p1=buscar_pokemon(vector_pokemon,pokemon_elegido_1,tamano_p);
			//Si no se encuentran decir cual estuvo mal escrito
			if(p1 == NULL) printf("El Primer pokemon ingresado esta mal escrito o no existe \n");

			else {
				printf("Ingrese pokemon_2 (defensor) ");
				scanf(" %29[^\n]",pokemon_elegido_2);

				pokemon *p2=buscar_pokemon(vector_pokemon,pokemon_elegido_2,tamano_p);
				if(p2 == NULL) printf("El Segundo pokemon ingresado esta mal escrito o no existe \n");
				else simularCombate(p1,p2,vector_pokemon,tamano_p);
			}

		}
	} while (input_usuario != 4);

	free(vector_pokemon);
	free(vector_ataques);
	return 0;
}
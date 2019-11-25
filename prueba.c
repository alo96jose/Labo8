#include <stdio.h>
#include <stdlib.h>

typedef struct pos_t{
        int data; //**< data */
        struct pos_t* next; //**< pointer to next element */
} pos_t;

pos_t* createList(int first_value){
//Con esta función creo mi primer nodo (la cabeza), el cual me retorna el puntero a este nodo, el cual será utilizado por otras
//funciones para ingresar a la lista.

        pos_t* head = (pos_t *)calloc(2,sizeof(pos_t));  //Reservo espacio de memoria para la cabeza.
        if (head == NULL){  //Si sistema no nos brinda memoria
                printf("Error: Memoria no asignada para nodo cabeza \n");
                return 1;
        }
        head -> data = first_value; //Aquí le estoy asignando al dato de la estructura (en .h) el entero que ingreso como first_value.
        head -> next = NULL; //Aquí hago que next (nodo siguiente) sea null.
        return head;  //Retorno el puntero que apunta a ese espacio de memoria.
}

int push_front(pos_t** head, int new_value){
        // Esta función recibe el puntero que guarda la dirección del puntero head
        // Tengo que asignarle la dirección del puntero head al nuevo puntero head
        // y la antigua dirección pasa a hacer ahora el "segundo" nodo.

        pos_t* newhead = (pos_t *)calloc(2,sizeof(pos_t));  //Reservo espacio de memoria para la NUEVA cabeza.
	//if (head->next == NULL){  //Primero se verifica si lista esta vacía.
        //        head -> next = nodo;
        if (newhead == NULL){  //Si sistema no nos brinda memoria
                printf("Error: Memoria no asignada para nodo NUEVA cabeza \n");
                return 1;
        }
        newhead -> data = new_value;
        newhead->next = *head; //Aquí hago que next (nodo siguiente) apunte al nodo que ANTES ERA HEAD.
        *head = newhead;
	return 0;
}
void printList(pos_t* head){ //A la hora de llamarse debe darse como argumento el head correspondiente.

        pos_t* ptraux = head; //Esto para que nuestro apuntador apunte al primer elemento de la lista.
        while (ptraux != NULL){
                printf("%d \n", ptraux -> data);
                ptraux = ptraux -> next; //Esto para que vaya recorriendo la lista de 1 en 1.
	}
}

int freeList(pos_t* head){
        pos_t *ptr = NULL; //Se inicializa un puntero ptr que apunta a NULL.
        while (head != NULL){
                ptr = head; //Ahora puntero auxiliar ptr apunta a la misma dirección que head.
		head = head -> next; //La dirección recibida por argumento por head ahora apunta al nodo siguiente.
		free(ptr);}
	printf("Lista ha sido vaciada \n");
	return 3;
}

int insertElement(pos_t** phead, int pos, int new_value){ //Recibe el puntero que apunta al puntero del primer elemento de la lista.
	pos_t* aux = *phead;
	pos_t* nodo = (pos_t *)calloc(2,sizeof(pos_t));  //Reservo espacio de memoria para el nuevo nodo.
	if (nodo == NULL){  //Si sistema no nos brinda memoria
                printf("Error: Memoria no asignada para nuevo nodo \n");
                return 1;
	}
	nodo->data = new_value;
	if (aux->next == NULL){  //Primero se verifica que lista no esté vacía.
		aux->next = nodo;
	}else{
		int posicion = 0;
		while(posicion < pos-1 &&  aux->next){
			aux = aux->next;
			posicion++;
		}
		nodo -> next = aux -> next; //Aquí se reasegura lo que hace la siguiente línea.
		aux -> next = nodo; //Aquí como estamos en el nodo n, hacemos que este puntero apunte al siguiente.
	}
}
int push_back(pos_t* head, int new_value){
        pos_t *ptr = head;            // Debo crear un puntero que me apunte al puntero del head. 
        while (ptr -> next != NULL){  // En el while tengo que escribir la forma de que ese puntero cambie al otro puntero del otro nodo 
               *ptr = next;            // y así consecutivamente.
               if (ptr -> next = NULL){
                   pos_t* back = (pos_t *)calloc(size_t pos_t,size_t sizeof(pos_t));//Reservo memoria para el nuevo nodo (la cola).
                   if (pos_t* head == NULL){  //Si sistema no nos brinda memoria
                         printf("Error: Memoria no asignada para nuevo nodo \n");
                         return 1;
		   }
                   ptr = back;
                   back -> data = new_value;
                   back -> next = NULL;
                   return 0;    
                   }
        }
}

int main(int argc, char **argv){
	pos_t* head = NULL;
	//Llamo a la función createList(), la cual me retorna un puntero de tipo pos_t llamado head.
	head = createList(1); //Ésta función me retorna puntero a head de tipo pos_t
	/**Llamando función para añadir nuevo nodo al inicio de lista. */
	push_front(&head,2);
	push_front(&head,3);
	push_front(&head,4);
	push_front(&head,5);
	insertElement(&head,3,1000);
	push_back(&head,9);
	/**Llamando función para imprimir lista */
	printList(head);
	//** Ahora se vacea la lista */
	freeList(head);
	return 10;
}

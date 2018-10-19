#include <stdio.h>
#include <pthread.h>
#define NB_WAITER = 4;
#define NB_TABLES = 8;

//fifo de consitions = les serveurs doivent le traiter

typedef enum {INSTALL, ORDER, BILL} kind_task_t;

typedef struct{
    kind_task_t kind;
    int client_id;
} task_t;

typedef struct Element{
    pthread_cond_t cond;
    task_t task;
    Element* next;
};

typedef struct Queue{
    Element* head;
    int size;
};

sem_t SEM_WAITER;
sem_t SEM_TABLES;

int FREE_WAITER[NB_WAITER];

int sem_init(SEM_WAITER,0,NB_WAITER);
int sem_init(SEM_TABLES,0,NB_TABLES);



void client_get_waiter(int id, kind_task_t task)(

    pthread_cond_wait(&client_empilé);
    //Semaphore unique pour chaque client, à mettre dans la pile
    

)


void client(int id){
//serveur installe le client dans une table
int serveur = client_get_waiter(id,INSTALL);
int table = get_client_table(id,serveur);

client_release_waiter(id,serveur);
}

void waiter(int id){ //Le id du waiter à affecter a un task
    while(service_en_cours()){
        task_t t = waiter_get_task(id);
        switch (t.kind) {

            case INSTALL:
            waiter_do_installatin(id,t);
            break;

            case ORDER:
            waiter_do_order(id,t);
            break;

            case BILL:
            waiter_do_bill(id,t);
            break;
        }
        waiter_task_done(id,t);
    }
}






void main(int argc, char const *argv[]) {



  return 0;
}

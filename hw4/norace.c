#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
#define LOOPS 1000000
int money_on_hand = 0;
int money = 2000000;
int num1;
int num2;


void Depositing(){
  for (int i=0; i<LOOPS; i++) {
    money_on_hand = money_on_hand + 1;
  }
}

void Withdrawing(){
  for (int i=0; i<LOOPS; i++) {
    money_on_hand = money_on_hand - 1;
  }
}

void person(){
  Depositing();
  Withdrawing();

  if (money != 2000000) {
    printf("Error !\n");
  }
}

void *ATM1()
{
  for (int i=0; i<LOOPS; i++) {
    pthread_mutex_lock( &mutex1 );
    money = money + 1;
    pthread_mutex_unlock( &mutex1 );
  }
  return NULL;
}


void *ATM2()
{
  for (int i=0; i<LOOPS; i++) {
    pthread_mutex_lock( &mutex1 );
    money = money - 1;
    pthread_mutex_unlock( &mutex1 );
  }
  return NULL;
}

int main() 
{
  printf("Initial money = %d\n", money);
  pthread_t thread1, thread2;

  pthread_create(&thread1, NULL, ATM1, NULL);
  pthread_create(&thread2, NULL, ATM2, NULL);

  pthread_join( thread1, NULL);
  pthread_join( thread2, NULL);
  
  person();

  printf("money = %d\nmoney_on_hand = %d\n", money, money_on_hand);
}

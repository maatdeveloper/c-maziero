#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void disparo_timer (int signum)
{
   printf ("Recebi o sinal %d\n", signum) ;
}
 
int main ()
{  
   struct itimerval timer ;
   struct sigaction action ;
 
   // define a ação para o sinal SIGALRM
   action.sa_handler = disparo_timer ;
   sigemptyset (&action.sa_mask);
   action.sa_flags = 0;
   sigaction (SIGALRM, &action, 0);
 
   // ajusta valores do temporizador
   timer.it_interval.tv_usec = 0;  // disparos sucessivos, micro-segundos
   timer.it_interval.tv_sec = 1;   // disparos sucessivos, segundos
   timer.it_value.tv_usec = 0;     // primeiro disparo, micro-segundos
   timer.it_value.tv_sec = 3 ;     // primeiro disparo, segundos
 
   // arma o temporizador
   setitimer (ITIMER_REAL, &timer, NULL) ;
 
   // laço vazio
   while (1)
     sleep (1);  
}
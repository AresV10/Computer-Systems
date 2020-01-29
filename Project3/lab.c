int main(void) {
  printf("L0\n");
  if(fork()!= 0){
    printf("L1\n");
    if(fork() == 0){
      printf("L2\n");
      fork();
    }
  }
  fork();
  printf("Bye\n");
  //return 0;
}
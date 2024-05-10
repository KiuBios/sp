#include "../net.h"
#include <pthread.h>

int main(int argc, char *argv[]) {
  int port = (argc >= 2) ? atoi(argv[1]) : PORT;
  char *host = (argc >= 3) ? argv[2] : "localhost";
  net_t net;
  net_init(&net, TCP, CLIENT, port, host);
  net_connect(&net);
  char cmd[SMAX], output[SMAX];
  printf("connect to server %s success!\n", net.serv_ip);
  printf("%s $ \n", net.serv_ip);           // 印出提示訊息
  while (1) {
    printf("%s", cmd);
    if (strncmp(cmd, "exit", 4)==0) break;   // 若是 exit 則離開

    sleep(2);                               // 休息一秒鐘
    int n = read(net.sock_fd, output, SMAX); // 讀取 server 傳回來的訊息
    if (n > 0){
      output[n-1] = '\0';                   // 字串結尾，把最後一個 \n 去掉!
      puts(output);                         // 顯示回應訊息
    }
  }
  close(net.sock_fd);
  return 0;
}
#ifndef CLIENT_H
#define CLIENT_H

#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_PATH "/usr/local/var/run/suricata/suricata-command.socket"
#define VERSION "{\"version\": \"0.1\"}"
#define CMD_PCAP "{\"command\": \"pcap-file\", \"arguments\": { \"filename\": \"%s\", \"output-dir\": \"%s\"}}"
#define RCV_MAX 4096
#define TIMEOUT 1000000

/* Connection to Suricata - return the socket */
int suricata_connect();

/* Close the socket */
int suricata_close(int socket);

/* Send a command to Suricata and read the result */
int suricata_send(char *cmd, int socket);

/* Return the command to analyse pcap files */
char* suricata_cmd_pcaps(char *pcap, char *dir);

#endif /* !CLIENT_H */

//CLIENT SERVER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    int vowel_count;
    
    // 1. Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    
    // 2. Define server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // 3. Connect to server
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    
    // 4. Get input from user
    printf("Enter a string: ");
    fgets(buffer, 1024, stdin);
    buffer[strcspn(buffer, "\n")] = 0;  // Remove newline
    
    // 5. Send to server
    send(sock, buffer, strlen(buffer), 0);
    
    // 6. Receive result
    read(sock, &vowel_count, sizeof(vowel_count));
    printf("Number of vowels: %d\n", vowel_count);
    
    close(sock);
    return 0;
}
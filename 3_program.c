#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int count_vowels(char *str) {
    int count = 0;
    for(int i=0; str[i]!='\0'; i++) {
        char ch = tolower(str[i]);
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            count++;
    }
    return count;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1, addrlen = sizeof(address);
    char buffer[1024] = {0};
    int vowel_count;
    
    // 1. Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    // 2. Set socket options
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    // 3. Bind
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    
    // 4. Listen
    listen(server_fd, 3);
    printf("Server listening on port 8080...\n");
    
    // 5. Accept connection
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    
    // 6. Read data from client
    read(new_socket, buffer, 1024);
    printf("Received: %s\n", buffer);
    
    // 7. Process: Count vowels
    vowel_count = count_vowels(buffer);
    
    // 8. Send result back
    send(new_socket, &vowel_count, sizeof(vowel_count), 0);
    printf("Sent vowel count: %d\n", vowel_count);
    
    close(new_socket);
    close(server_fd);
    return 0;
}


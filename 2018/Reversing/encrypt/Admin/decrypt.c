#include <arpa/inet.h>
#include <gmp.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

#define PORT 1337

void abrt_handle(int sig_num) {
    signal(SIGABRT, abrt_handle);
    printf("Wrong Key!! Can't decrypt this message!!!!");
    fflush(stdout);
}

int choose_key(void) {
    int t = rand() % 4;
    int keys[5] = {262145, 131071, 65537, 1048577, 16777217};
    return keys[t];
}

char * send_data(int ch) {
    struct sockaddr_in address;
    int sock = 0, valread, e_key;
    struct sockaddr_in serv_addr;
    char number[10];
    char key_store[10];
    char * buffer = calloc(1, 1024);
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return NULL;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "13.126.147.4", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return NULL;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return NULL;
    }

    snprintf(number, 6, "%05d", ch);
    send(sock, &number, strlen(number), 0);
    e_key = choose_key();
    printf("The key chosen is : %d\n", e_key);
    sprintf(key_store, "%09d", e_key);
    send(sock, &key_store, strlen(key_store), 0);
    valread = read(sock, buffer, 1024);
    return buffer;
}


int main(void)
{
    int ch, e_key;
    char c;
    char *d_key = malloc(1024);
    char *ebuffer;
    char key_store[10];
    char *mod = "18555329826150997941554975730342706939638443847743281139897229406594174887411734691322647951918332331910186854856806754411325122122453171002729931206539671443547875037300667637534797175629615128599852810542016254132613403743376742763246443433239842897285674842267367465004382729783498464902061032064207299289588996523440448819726882367047888166990479237806327114212200392568126999394147492069048274200645340284285172427217202731011154491180170887889050728200703209091947405212049254364524967279130819680609739386389565010425701435481286234715263261008109696324185537221327927921655608349700203076000902104960423587103";
    mpz_t n, d, pt, ct;
    mpz_init(pt);
    mpz_init(ct);
    mpz_init_set_str(n, mod, 10);
    signal(SIGABRT, abrt_handle);
    srand(time(0));

    printf("Welcome to Let's Decrypt.\n");
    printf("Do you know the key? : ");
    scanf("%c", &c);
    if ( c != 'y' ) {
        printf("You need the key\n");
        exit(-1);
    }
    printf("Enter which message to decrypt :  ");
    scanf("%d", &ch);
    ebuffer = send_data(ch);

    mpz_init_set_str(ct, ebuffer, 10);
    printf("Enter your key now : ");
    scanf("%1024s", d_key);
    mpz_init_set_str(d, d_key, 10);
    mpz_powm(pt, ct, d, n);

    char buffer[64];
    mpz_export(buffer, NULL, 1, 1, 0, 0, pt);
    printf("\nThe Message that was encrypted: %s\n", buffer);

    mpz_clears(pt, ct, n, d, NULL);
    return 0;
}

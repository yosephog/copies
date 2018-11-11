
struct a2 {
    int b;
    int length;
    char* streng;
}

struct a {
    int b;
    int length;
    char s[];
}__attribute__((packed));

extern int errno;

main {
    struct a *peker = malloc(sizeof(struct a) + strlen(input_string));
    printf("%d\n", sizeof(struct a), strlen() );


    char *melding = malloc(meldingsize);    

    melding[0] = jobinfo;


    struct a2 *peker2 = malloc(sizeof(tsruct a));
    a2->streng = malloc(strlen(intpu_string));


    free(a);

    free(a2->streng);
    free(a2);

    char* tmep = malloc(sizoef(a) + strlen);
    strcpy();

    write(sd, a, a->length); //imploikasjoner??

    write(sd, a2, sizeof(a));
    write(sd, a2->streng, a->length);


    size_t sent_data = 0;
    melding[];
    char* send_from = melding;

    while(sent_data < data_to_send_length) {
        sent_data += write(sd, send_from);
        send_form += sent_data;
    }o

    listen(sd, 0);

    accept();
    if(errno == ECONNREFUSED) 
\       smart

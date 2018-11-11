typedef uint32_t in_addr_t;

struct in_addr {
	in_addr_t s_addr;
};

typedef unsigned short int sa_family_t;
struct sockaddr_in {
	/* __SOCKADDR_COMMON(sin_) */
	sa_family_t sin_family;			/* Address family */
	in_port_t sin_port;				/* Port number */
	struct in_addr sin_addr;		/* Internet address */



	/* padding */
	unsigned char sin_zero[sizeof(struct sockaddr) -
				__SOCKADDR_COMMON_SIZE -
				sizeof(in_port_t) -
				sizeof(struct in_addr)];
};


struct person {
	char* name;
	unsigned int age;
};

int person_get_age(struct person* p);
int person_set_age(struct person* p, int new_age);
char* person_get_name(struct person* p);
int person_set_name(struct person* p, char* s);
int person_check_valid(struct person* p);
struct person* person_init(void);


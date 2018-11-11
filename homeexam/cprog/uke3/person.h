
struct person{
   char* name;
   unsigned int age;
};
void set_age(struct person* p,unsigned int a);
int get_age(struct person* p);
void set_name(struct person* p,char* namee);
char* get_name(struct person* p);
struct person* init(void);

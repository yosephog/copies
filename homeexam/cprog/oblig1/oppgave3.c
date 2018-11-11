struct datetime{
   int hour,min,sec,year;
};
struct timerange{
  struct datetime* dte;
};
struct datetime* init_datetime(struct datetime* dt,int h,int m,int s,int y){
  dt->hour=h;
  dt->min=m;
  dt->sec=s;
  dt->year=y;
  return dt;
}
void datetime_set_date(struct datetime* dt,int y){
   dt->year=y;
}
void datetime_set_time(struct datetime* dt,int h,int m,int s){
  dt->hour=h;
  dt->min=m;
  dt->sec=s;
}
void set_time_range(struct timerange* tr,struct datetime* d){
  tr->dte=d;
}
int main(void){
    struct datetime* t1=malloc(sizeof(struct datetime));
    struct datetime* t2=malloc(sizeof(struct datetime));
    init_datetime(t1,12,20,30,2018);
    init_datetime(t2,11,10,20,2017);
    printf("the date time is %d:%d:%d - %d\n",t1->hour,t1->min,t1->sec,t1->year );

     struct timerange* tr=malloc(sizeof(struct timerange));
     set_time_range(tr,t2);
     printf("%d\n",tr->dte->hour );

  free(t1);
   return 0;
 }

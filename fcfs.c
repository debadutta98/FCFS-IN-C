 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>
 void  completion_time(int comp[],int init[],int arr[],int bur[],int d)
 {
 int i=0,k;
 for(;i<d;)
 {
 if(i==0){
 comp[i]=comp[i]+bur[i];
  init[i]=arr[i];
  i++;
}
 else{
 if(comp[i-1]>=arr[i]){
	init[i]=comp[i-1];
 comp[i]=comp[i-1]+bur[i];
 i++;
}
 else if(comp[i-1]<arr[i])
 {
 k=arr[i]-comp[i-1];
 init[i]=comp[i-1]+k;
 comp[i]=init[i]+bur[i];
 	i++;
 }
}
}
 }
 void swap(int* xp, int* yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void selectionSort(int arr[], int n,int bur[]) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n - 1; i++) { 
        min_idx = i; 
        for (j = i + 1; j < n; j++) 
            if (arr[j] <= arr[min_idx]) 
                min_idx = j; 
        swap(&arr[min_idx], &arr[i]); 
        swap(&bur[min_idx],&bur[i]);
    } 
} 
int tat_find(int tat[],int comp[],int arr[],int d)
 {
 	int i;
 	double sum=0.0;
 	for(i=0;i<d;i++)
 	{
 		tat[i]=comp[i]-arr[i];
 		sum=sum+(double)(comp[i]-arr[i]);
	 }

	 return sum;
 }
 int wt_find(int wt[],int bur[],int tat[],int d)
 {
 	int i=0;
 double sum=0.0;
 	for(i=0;i<d;i++)
 	{
 		wt[i]=tat[i]-bur[i];
 		sum=sum+(double)(tat[i]-bur[i]);
	 }
	 
	 return sum;
 }
 
 int rt_find(int rt[],int arr[],int init[],int d)
 {
 	int i=0;
 	double sum=0.0;
 	for(i=0;i<d;i++)
 	{
 		rt[i]=init[i]-arr[i];
 		sum=sum+(double)rt[i];
	 }

	 return sum;
 }
 void display(int pro[],int arr[],int bur[],int comp[],int tat[],int wt[],int rt[],int d,double avg_wt,double avg_tat){
 	int i;
 	printf("\nprocess no\tArrival time\tBurst time\tcompletion time\ttat\twt\trt\n");
 	for(i=0;i<d;i++)
 	{
 		printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d\t%d\n",pro[i],arr[i],bur[i],comp[i],tat[i],wt[i],rt[i]);
	 }
	 printf("\naverage wating time =%lf",avg_wt);
	 printf("\nturn around time=%lf",avg_tat);
 }
 void main()
 {
 	int i,d,a,b,c;
 	printf("enter the number of process");
 	scanf("%d",&d);
 	int pro[d],arr[d],bur[d];
 	for(i=0;i<d;i++)
 	{
 	printf("enter the process");
 	scanf("%d",&a);
	 pro[i]=a;
	 printf("enter the arrival time of the process");	
	 scanf("%d",&b);
	 arr[i]=b;
	 printf("enter the brusttime of the process");
	 scanf("%d",&c);
	 bur[i]=c;
	 	}
	 selectionSort(arr,d,bur);	
	int comp[d],tat[d],wt[d],rt[d],init[d];
	comp[0]=0;
completion_time(comp,init,arr,bur,d);
double avg_tat=tat_find(tat,comp,arr,d);
double avg_wt=wt_find(wt,bur,tat,d);
double response_time=rt_find(rt,arr,init,d);
double avg_w=(avg_wt/(double)d);
double avg_t=(avg_tat/(double)d);
display(pro,arr,bur,comp,tat,wt,rt,d,avg_w,avg_t);
	getch();
 }

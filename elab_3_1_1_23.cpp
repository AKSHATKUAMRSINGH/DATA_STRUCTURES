#include<stdio.h> 
#include<stdlib.h> 
typedef struct{ 
    int v; 
    int w; 
    int wei; 
}edge; 
      
int cmpfunc(const void *a,const void *b){ 
    edge *ia=(edge *)a; 
    edge *ib=(edge *)b; 
    return((ia->wei)-(ib->wei)); 
} 
int id[1000001],sz[1000001]; 
     
int root(int i){ 
    while(i!=id[i]){ 
     id[i]=id[id[i]]; 
     i=id[i]; 
    } 
    return i; 
} 
void uni(int p,int q){ 
    int i,j; 
    i=root(p); 
    j=root(q); 
    if(i==j) 
     return; 
    if(sz[i]<sz[j]){ 
     id[i]=j; 
     sz[j]+=sz[i]; 
    } 
    else{ 
     id[j]=i; 
     sz[i]+=sz[j]; 
    } 
} 
      
      
int main(){ 
    int n,m,i,j,l,q,p; 
    long long int k,sum=0; 
    scanf("%d %d %lld",&n,&m,&k); 
    edge e=(edge)malloc(m*sizeof(edge)); 
    int w=(int)malloc(n*sizeof(int)); 
    for(i=0;i<=n;i++){ 
     id[i]=i; 
     sz[i]=1; 
    }  
    sz[0]=0; 
    for(i=0;i<m;i++){ 
     scanf("%d %d %d",&l,&q,&p); 
     e[i].v=l; 
     e[i].w=q; 
     e[i].wei=p; 
    } 
    qsort(e,m,sizeof(edge),cmpfunc); 
    j=0; 
    for(i=0;i<m;i++){ 
     p=e[i].v; 
     q=e[i].w; 
     if(root(p)!=root(q)){ 
      w[j++]=e[i].wei; 
      sum+=e[i].wei; 
      uni(p,q); 
     } 
    } 
  
    if(k<n-1||j<n-1) 
     printf("-1\n"); 
    else{ 
     int count=0; 
     i=j-1; 
     while(j>=0&&sum>k){ 
      sum=(sum+1)-w[i]; 
      w[i--]=1; 
      count++; 
     } 
  printf("%d\n",count); 
    } 
    return 0; 
}
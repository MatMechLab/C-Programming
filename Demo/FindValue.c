#include <stdio.h>

int findVal(const int a[],const int n,const int val,int *firstid,int *lastid){
    int count=0;
    *firstid=-1;*lastid=-1;
    for(int i=0;i<n;i++){
        if(a[i]==val){
            count+=1;
            if(count==1) *firstid=i;
            *lastid=i;
        }
    }
    return count;
}
int main(){
    int a[8]={1,2,3,3,4,5,6,6};
    int FirstIndex,LastIndex;
    int TargetVal=6;
    int Count=findVal(a,8,TargetVal,&FirstIndex,&LastIndex);
    if(Count){
        printf("we find %d, its first index=%d, last index=%d, it apears %d times\n",TargetVal,
                                                                                     FirstIndex,
                                                                                     LastIndex,
                                                                                     Count);
    }
    else{
        printf("Ooopus, we can\'t find %d\n",TargetVal);
    }
    return 0;
}
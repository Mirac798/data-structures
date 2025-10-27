#include <iostream>
#include <string>
using namespace std;


void bubbleSort(int d[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(d[j]<d[j+1]){
                swap(d[j],d[j+1]);
            }
        }
    }
}

void yazdir(int d[],int n){
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int d[]={1,5,2,67,8,23,78};
    int n=sizeof(d)/sizeof(d[0]);
    cout<<"Siralama Oncesi"<<endl;
    yazdir(d,n);
    cout<<"Siralama Sonrasi"<<endl;
    bubbleSort(d,n);
    yazdir(d,n);




    return 0;
}


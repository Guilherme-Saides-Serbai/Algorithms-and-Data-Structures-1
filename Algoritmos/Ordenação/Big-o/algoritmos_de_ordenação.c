int selection_sort(int v[],int n){
    int position_min=0;//O(1)
    for(int i=0;i<n;i++){//O(N)
        if(v[i]<v[position_min]){//O(1)
            position_min=i;
        }
    }
    int j=0;
    if(v[j]>v[position_min]){
        int temp=v[j];
        v[j]=v[position_min];
        v[position_min]=temp;
        j++;
    }

}


int bublle_sort(int v[],int n){
    for(int i=0;i<n-1;i++){// O(N)
        for(int e=0;e<n-1;e++){// O(N)
            if(v[i]>v[i+1]){//O(1)
                int temp=v[i];
                v[i]=v[i+1];
                v[i+1]=temp;
        }
        }
    }
}
// O(N)x O(N)=O(N^2)
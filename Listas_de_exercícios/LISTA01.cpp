#include<iostream>
#include<string>
#include <stdbool.h>
#include <stdlib.h> 
using namespace std;
int stringFindFirst(const string &s, char c) {
    int tamanho = s.size();
    for(int i = 0; i < tamanho; i++) {
        if(s[i] == c) {
            return i;
        }
    }
    return -1;
}

bool isLetter(char c){
    string letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int tamanho=letras.size();
    for(int i=0;i<tamanho;i++){
        if(c==letras[i]){
            return true;
        }
    }
    return false;
}

bool checkName(string s){
    int tamanho=s.size();
    for(int i=0;i<tamanho;i++){
        if(isLetter(s[i]) != true && s[i] != ' '){
            return false;
        }
    }
    return true;
}

int* createArray(int n, bool asc){
    int * vector=(int *) malloc(n*sizeof(int));
    if(vector==NULL){
        printf("erro ao alocar memória !");
        return 0;
    }
    int temp=1;
    if(asc==true){
       for(int i=0;i<n;i++){
          vector[i]=temp;
          temp++;
    }
}
    else{
        for(int i=n-1;i>=0;i--){
           vector[i]=temp;
           temp++;
        }
    }
    return vector;
}

int* arrayConcat(int* v1, int n1, int* v2, int n2){
    int * v3=(int*)malloc((n1+n2)*sizeof(int));
    if(v3==NULL){
        printf("erro ao alocar memória !");
        return 0;
    }
    for(int i=0;i<n1;i++){
        v3[i]=v1[i];
    }
    for(int i=0;i<n2;i++){
        v3[n1+i]=v2[i];
    }
    return v3;
}

int* arrayMerge(int* v1, int n1, int* v2, int n2) {
    int *v3 = (int*)malloc((n1 + n2) * sizeof(int));
    if (v3 == NULL) {
        printf("Erro ao alocar memória!");
        return NULL;
    }

    int i = 0, j = 0, k = 0; 

    while (i < n1 && j < n2) {
        if (v1[i] < v2[j]) {
            v3[k++] = v1[i++];
        } else {
            v3[k++] = v2[j++];
        }
    }
    while (i < n1) {
        v3[k++] = v1[i++];
    }
    while (j < n2) {
        v3[k++] = v2[j++];
    }

    return v3;
}

int main(){
    //teste first find
    string str = "texto de teste";
    char ch = 't';
    cout << "First Find: " << stringFindFirst(str, ch) << endl;
    printf("\n\n");
    
    //teste is_letter
    char teste = 'A';
    cout << "isletter:" << isLetter(teste) << endl;
    printf("\n\n");
    
    //teste checkName
    string teste2= "Chuck Kick Norris";
    bool check = checkName(teste2);
    cout << "checkName:" << check << endl;
    printf("\n\n");
    
    //teste createArray
    int n=10;
    bool v=0;
    int * pointer= createArray(n,v);
    for(int i = 0; i < n; i++)
    {
         cout << "createArray:" << pointer[i] << endl;
    }printf("\n\n");

    //teste ArrayConcat
    int n1=5;
    int n2=3;
    int v1[n1]={1,10,20,30,40};
    int v2[n2]={10,2,56};
    int * p=arrayConcat(v1,n1,v2,n2);
    for(int i=0;i<n1+n2;i++){
        cout << "ArrayConcat:" << p[i] << endl;
    }printf("\n\n");

    //teste ArrayMerge
    int vector1[4] = {1, 3, 5, 7};
    int vector2[3] = {2, 4, 6};
    int length1 = 4;
    int length2 = 3;

    int * result = arrayMerge(vector1, length1, vector2, length2);
    for (int i = 0; i < n1 + n2; i++) {
         cout << "ArrayMerge:" << result[i] << endl;
        }
    return 0;
}



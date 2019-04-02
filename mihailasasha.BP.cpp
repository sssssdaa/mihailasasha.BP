#include<fstream>
using namespace std;
int S,n,V[100];

int read_data(){
    ifstream f("input.dat");
    f>>S>>n;
    for(int i=1;i<=n;i++){
        f>>V[i];
    }
}

int sort_data(){
    int loc=0;
    for(int i=1;i<=n;i++){
        int maxim=INT_MIN;
        for(int j=i;j<=n;j++){
            if(V[j]>maxim){
                maxim=V[j];
                loc=j;
            }
        }
        swap(V[i],V[loc]);
    }
}

int greedy(){
    int nr=0;
    for(int i=1;i<=n;i++){
        while(S>V[i]){
            S=S-V[i];
            nr++;
        }
    }
    return nr;
}

int print_data(){
    ofstream g("output.dat");
    g<<greedy();
}

int main(){
    read_data();
    sort_data();
    print_data();
    return 0;
}

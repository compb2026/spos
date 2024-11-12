#include<bits/stdc++.h>
using namespace std;
struct Process{
    int id;
    int at;
    int bt;
    int wt;
    int tat;
};
bool comp(Process a,Process b){
    return a.id<b.id;
}

float avgWaitingTime(vector<Process>&p){
    p[0].wt=0;
    float val=0;
    for(int i=1;i<p.size();i++){
        p[i].wt=p[i-1].wt+p[i-1].at+p[i-1].bt-p[i].at;
        if(p[i].wt<0) p[i].wt=0;
        val+=p[i].wt;
    }
    return float(val/float(p.size()));
}
float avgTurnAroundTime(vector<Process>&p){
    p[0].tat=p[0].bt;
    float val=p[0].bt;
    for(int i=1;i<p.size();i++){
        p[i].tat=p[i].bt+p[i].wt;
        val+=p[i].tat;
    }
    return float(val/float(p.size()));
}


int main(){
    int n;
    cout<<"enter number of process : ";
    cin>>n;
    vector<Process> p(n);
    for(int i=0;i<n;i++){
        cout<<"ENTER id at bt  of "<<i+1<<" process :";
        p[i].id=i;
        cin>>p[i].at>>p[i].bt;
    }
    sort(p.begin(),p.end(),comp);
    cout<<avgWaitingTime(p);
    cout<<endl;
    cout<<avgTurnAroundTime(p);
    cout<<endl;

    cout<<"WT TAT"<<endl;
    for(int i=0;i<n;i++){
        cout<<p[i].wt<<" "<<p[i].tat<<endl;
    }



}
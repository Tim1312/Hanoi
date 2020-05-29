#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

void chek(string b1[],string b2[],string b3[], int jk){   
    cout << ""  << endl;
for(int r=0; r < jk ;r ++ ){
    cout << b1[r]<<' '<<b2[r]<<' '<<b3[r] << endl;

}
}

void movedisk(string b1[],string b2[],string b3[],int ot,int ku,string nd,int a){ 
string mdisk;
mdisk+=nd;
int i=0;
int flag=0;
int chekvoid=0;
if(ku==ot){ cout << "НАЙН!!!" << endl; return;}

if(ot==1){
    while((b1[i]==nd)&&(flag==0)){i++;chekvoid++;  if(chekvoid >=a){flag++; }}
    if(flag==1){cout << "НЕЧЕГО ДВИГАТЬ !!!" << endl; return;}
    mdisk.swap(b1[i]);
}
if(ot==2){
    while((b2[i]==nd)&&(flag==0)){i++;chekvoid++;  if(chekvoid>=a){flag++;  }}
    if(flag==1){cout << "НЕЧЕГО ДВИГАТЬ !!!" << endl; return;}
    mdisk.swap(b2[i]);
}
if(ot==3){
    while((b3[i]==nd)&&(flag==0)){i++;chekvoid++;  if(chekvoid>=a){flag++;}}
    if(flag==1){cout << "НЕЧЕГО ДВИГАТЬ !!!" << endl; return;}
    mdisk.swap(b3[i]);
}

//!!!!!!!!!!!!!
chekvoid=0;
i=0;
if(ku==1){
    for(i=a;i>=0;i--){
        if(b1[i]==nd){

                if((flag==0)||(i==a)){

                b1[i].clear(); mdisk.swap(b1[i]); chekvoid++; break;}}
    }}


if(ku==2){
    for(i=a;i>=0;i--){
        if(b2[i]==nd){

                if((flag==0)||(i==a)){


                b2[i].clear(); mdisk.swap(b2[i]); chekvoid++; break;}}
}}
if(ku==3){
    for(i=a;i>=0;i--){

                if((flag==0)||(i==a)){
        if(b3[i]==nd){ b3[i].clear(); mdisk.swap(b3[i]); chekvoid++; break;}}
}}


}

int chekstatus(string b[], int jk,string nd){
 int flag=0;
for(int r=0; r < jk ;r ++ ){
    if(b[r]!=nd){return 1;}
}

return 0;}




void Towers(int number, int from, int to, int free)
{
    if(number!=0)
    {
        Towers(number-1, from, free, to);
    cout<<"\n  Снимаем "<<number<<"-й диск с "<<from<<"-го стержня и одеваем его на "<<to<<"-й стержень";
    Towers(number-1,  free, to, from);
    }
}



int main()
{  int a;
   int winluse;
   int command[3];
   string x;
   string d;
   d+="@";
   x+="|";
    setlocale(LC_ALL, "Russian");
    cout << "введите количество дисков:" ;
    cin >> a ;
    cout << "количество дисков:"; cout << a << endl;

    if(a>14){cout <<"НЕ МНОГОВАТО ????";
                    exit(1);};

    if(a<2){cout <<"НЕ МАЛОВАТО ????";
                    exit(1);};

    int z =0;

    map<int,string>colc ;  
    while(z<a){
        colc[z]=d;
        z++;
        d+="@";
    }

string disk[a];     
string pustot;
 for (z = 0; z != a; ++z){
        for(int f=0;f!=a-z-1;f++){
          pustot+=" ";
         }

disk[z]+= pustot+colc[z]+x+colc[z]+pustot;
pustot.clear();
 }

string nodisk;
for(z=0;z!=a;z++){
    nodisk+=" ";

}
  nodisk+="|";
 for(z=0;z!=a;z++){
    nodisk+=" ";

}

int b = a;
b++;
string b1[a]; 
string b2[a];
string b3[a];
for(int it=0; it<a; it++ ){
 b1[it]+= disk[it];
}
for(int it=0; it<a; it++ ){
 b2[it]+= nodisk;
}
for(int it=0; it<a; it++ ){
 b3[it]+= nodisk;
}

colc.clear();



 cout << "ИГРАТЬ 1"  << endl;
 cout << "показать решение 2" <<endl;
 cout << "выход 0" <<endl;
 chek(b1,b2,b3,a);
 cin >> command[0] ;
if(command[0]==0){exit(2);};
if(command[0]==1){

do{cout << "ПОМНИ НЕЛЬЗЯ СТАВИТЬ БОЛЬШИЙ ДИСК НА МЕНЬШИЙ"  << endl;
  cout << "ВВЕДИТЕ ОТКУДА и КУДА:";
                                    cin >> command[1] >> command[2]; cout<< ' ' << endl;


                if((command[1]==0)||(command[2]==0)){break;}
movedisk(b1,b2,b3,command[1],command[2],nodisk,a);
chek(b1,b2,b3,a);
if((chekstatus(b1,a,nodisk)+ chekstatus(b2,a,nodisk)+ chekstatus(b3,a,nodisk))==1){break;}
}while((command[1]!=0)||(command[2]!=0)||(winluse==1));

}

if(command[0]==2){Towers(a,1,2,3);}


                     cout << "                        "  << endl;
                     cout << "          ИГРА ЗАВЕРШЕНА"  << endl;
    return 0;
}

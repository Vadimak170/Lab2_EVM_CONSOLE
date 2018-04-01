#include <iostream>
#include <windows.h>
using namespace std;
typedef int (*func)(int,int);
int main()
{func returnSum, returnMinus, returnUmnozhenie,returnDelenie;
 HINSTANCE  ident=LoadLibrary(TEXT("DinLib.dll"));
 int vibor,a,b;
    if(ident==NULL)
        {cout<<"FAIL"<<endl; return 0;}
returnSum=(func) GetProcAddress(ident, "_ZN6DinLib5summaEii");
returnMinus=(func) GetProcAddress(ident, "_ZN6DinLib5minusEii");
returnUmnozhenie=(func) GetProcAddress(ident, "_ZN6DinLib10umnozhenieEii");
returnDelenie=(func) GetProcAddress(ident, "_ZN6DinLib7delenieEii");
cout<<"Enter a:";
    cin>>a;
cout<<"Enter b:";
    cin>>b;
cout<<"What do you want?\n1)Sum\n2)Minus\n3)Umnozhenie\n4)Delenie";
    cin>>vibor;
switch(vibor){
    case 1:cout<<returnSum(a,b);break;
    case 2:cout<<returnMinus(a,b);break;
    case 3:cout<<returnUmnozhenie(a,b);break;
    case 4:cout<<returnDelenie(a,b);break;
    }
    FreeLibrary(ident);
    system("pause");
    return 0;
}

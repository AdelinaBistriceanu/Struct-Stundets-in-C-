#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <cstring>
using namespace std;
struct student
{
    char nume[20],prenume[20],specializarea[20],telefon[10];
    int an,matricol;
    float media;
} s[100];
int n,opt,poz,opt1,an,j,i;
char temp[30],spcializare[30];
ifstream f("studenti.txt");
void citire(student v[100],int &n)
{
    f>>n;
    for(int i=0;i<=n-1;i++)
    {
        f>>v[i].nume;
        f>>v[i].prenume;
        f>>v[i].matricol;
        f>>v[i].specializarea;
        f>>v[i].telefon;
        f>>v[i].an;
        f>>v[i].media;
    }
}
void adaugare(student v[100],int &n)
{
    ofstream f("studenti.txt");
    n++;
    cout<<"Numele: ";cin>>v[n].nume;
    cout<<"Prenumele: ";cin>>v[n].prenume;
    cout<<"Matricol: ";cin>>v[n].matricol;
    cout<<"Specializare: ";cin>>v[n].specializarea;
    cout<<"Telefon: ";cin>>v[n].telefon;
    cout<<"An: ";cin>>v[n].an;
    cout<<"Media: ";cin>>v[n].media;
    f<<n<<endl;
    for(int i=0;i<=n-1;i++)
    {
        f<<v[i].nume<<endl;
        f<<v[i].prenume<<endl;
        f<<v[i].matricol<<endl;
        f<<v[i].specializarea<<endl;
        f<<v[i].telefon<<endl;
        f<<v[i].an<<endl;
        f<<v[i].media<<endl;
    }
}
void afisare(student v[100], int n)
{
    for(int i=0;i<=n-1;i++)
    {
        cout<<v[i].nume<<endl;
        cout<<v[i].prenume<<endl;
        cout<<v[i].matricol<<endl;
        cout<<v[i].specializarea<<endl;
        cout<<v[i].telefon<<endl;
        cout<<v[i].an<<endl;
        cout<<v[i].media<<endl;
        cout<<endl;
    }
}
void stergere(student v[100], int &n)
{
    int nr,i,poz;
    cout<<"Introduceti numarul matricol al studentului: ";
    cin>>nr;
    for(i=0;i<=n-1;i++)
        if(nr==v[i].matricol) poz=i;
    if(poz>n) cout<<"Nu exista numarul matricol!"<<endl<<endl;
    else
    {
        for(i=poz;i<n;i++) v[i]=v[i+1];
        n=n-1;
        cout<<"Studentul a fost sters."<<endl<<endl;
        ofstream f("studenti.txt");
        f<<n<<endl;
        for(int i=1;i<=n;i++)
        {
            f<<v[i].nume<<endl;
            f<<v[i].prenume<<endl;
            f<<v[i].matricol<<endl;
            f<<v[i].specializarea<<endl;
            f<<v[i].telefon<<endl;
            f<<v[i].an<<endl;
            f<<v[i].media<<endl;
        }
    }
}
int main()
{
    citire(s,n);
    f.close();
    while(opt!=5)
    {
        system("cls");
        cout<<endl<<"Facultatea de Matematica"<<endl<<endl;
        cout<<"1.Afisare studenti"<<endl;
        cout<<"2.Adaugare student"<<endl;
        cout<<"3.Stergere student"<<endl;
        cout<<"4.Modificare date student"<<endl;
        cout<<"5.Media:"<<endl;
        cout<<"6.Iesire"<<endl<<endl;
        cout<<"Introduceti optiunea: ";
        cin>>opt;
        switch (opt)
        {
            case 1:{system("cls");
            cout<<("Afisarea studentilor")<<endl<<endl;
            afisare(s,n);
            break; }

            case 2:{system("cls");
            cout<<("Adaugarea unui student")<<endl<<endl;
            adaugare(s,n);
            break;}

            case 3:{system("cls");
            cout<<("Stergerea unui student")<<endl<<endl;
            stergere(s,n);
            break;
            }
            system("pause");

            case 4:{system("cls");int i;
            cout<<"Modificare date"<<endl<<endl;
            cout<<"Introduceti numar matricol: ";
            int nr_matr;
            cin>>nr_matr;
            for(i=0;i<=n-1;i++)
                if(nr_matr==s[i].matricol)poz=i;
            if(poz>n)cout<<"Nu exista.";
            else while(opt1!=7)
            {
                cout<<"1.Nume: "<<endl;
                cout<<"2.Prenume: "<<endl;
                cout<<"3.Nr. matricol: "<<endl;
                cout<<"4.Specializare: "<<endl;
                cout<<"5.Telefon: "<<endl;
                cout<<"6.An: "<<endl;
                cout<<"7.Iesire"<<endl;;
                cout<<"Introduceti optiunea: "<<endl;
                cin>>opt1;
                switch (opt1)
                {
                case 1: {cout<<"Introduceti noul nume: ";
                cin>>s[poz].nume;
                  break; }
                case 2: {cout<<"Introduceti noul prenume: ";
                cin>>s[poz].prenume;
                  break; }
                case 3: {cout<<"Introduceti noul numar matricol: ";
                cin>>s[poz].matricol;
                  break; }
                case 4: {cout<<"Introduceti noua specializare: ";
                cin>>s[poz].specializarea;
                  break; }
                case 5: {cout<<"Introduceti noul numar de telefon: ";
                cin>>s[poz].telefon;
                  break; }
                case 6: {cout<<"Introduceti noul an: ";
                cin>>s[poz].an;
                  break; }

                }

            }
            break;}
            case 5:{student aux;
                for (int i=0;i<=n-1;i++)
                for(int j=i+1;j<=n;j++)
                       {if (strcmp(s[i].nume,s[j].nume)>0)
                               {aux=s[i];
                                s[i]=s[j];
                                s[j]=aux;}
                        }break;}

            case 6:{cout<<"Introduceti anul:";cin>>an;
                for (int i=0; i<=n-1;i++)
                        if (an==s[i].an)
       {cout<<s[i].nume<<endl;
        cout<<s[i].prenume<<endl;
        cout<<s[i].matricol<<endl;
        cout<<s[i].specializarea<<endl;
        cout<<s[i].telefon<<endl;
        cout<<s[i].an<<endl;
        cout<<s[i].media<<endl;
        cout<<endl;}break;}
        case 7:{char spec[20];
            cout<<"Introduceti Specializarea:";cin>>spec;
                for (int i=0; i<=n-1;i++)
                        if (strcmp(spec,s[i].specializarea)==0)
    {cout<<s[i].nume<<endl;
        cout<<s[i].prenume<<endl;
        cout<<s[i].matricol<<endl;
        cout<<s[i].specializarea<<endl;
        cout<<s[i].telefon<<endl;
        cout<<s[i].an<<endl;
        cout<<s[i].media<<endl;
        cout<<endl;}
        system("pauze");break;
    }

        case 8:{student aux;

            for(i=0;i<=n-1;i++)
                for(j=i+1;j<=n;j++)
            {
                if(s[i].media<=s[j].media)
                {
                    aux=s[i];
                    s[i]=s[j];
                    s[j]=aux;
                }
                for(i=0;i<=2;i++)
                    cout<<s[i].media;
            }}
}}}

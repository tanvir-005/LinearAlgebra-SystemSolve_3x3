#include<bits/stdc++.h>
using namespace std;

int n=3, i, j, k;
double sys[10][10], temp[10], x1, x2, x3, x4, x5;

void input();
void output();
void steps_3();

void input()
{
    cout<<"Enter augmented matrix elements:\n";
    for(i=0; i<n; i++)
    {
        for(j=0; j<=n; j++)
        {
            cin>>sys[i][j];
        }
    }
    cout<<"\nAugmented form:\n";
    output();
}

void output()
{
    cout<<'\n';
    for(i=0; i<n; i++)
    {
        for(j=0; j<=n; j++)
        {
            cout<<setprecision(3)<<sys[i][j]<<"\t";
            if(j==n-1) cout<<"| ";
        }
        cout<<'\n';
    }
}

void steps_3()
{
    double f=0;

    if(sys[0][0]==0)
    {
        if(sys[1][0]!=0)
        {
            f=2;
            for(k=0; k<=n; k++)
            {
                temp[k]=sys[0][k];
                sys[0][k]=sys[1][k];
                sys[1][k]=temp[k];
            }
        }
        else
        {
            f=3;
            for(k=0; k<=n; k++)
            {
                temp[k]=sys[0][k];
                sys[0][k]=sys[2][k];
                sys[2][k]=temp[k];
            }
        }
        output();
        cout<<"Interchanging R1 and R"<<f<<'\n';
    }

    if(sys[0][0]!=1)
    {
        f=sys[0][0];
        for(k=0; k<=n; k++)
        {
            sys[0][k]/=f;
        }
        output();
        cout<<"R1' = R1/"<<f<<'\n';
    }

    if(sys[1][0]!=0)
    {
        if(sys[1][0]>0)
        {
            f=sys[1][0];
            for(k=0; k<=n; k++)
            {
                sys[1][k]=sys[1][k]-(sys[0][k]*f);
            }
            output();
            if(f!=1) cout<<"R2' = R2 - "<<f<<"R1\n";
            else cout<<"R2' = R2 - R1\n";
        }
        else
        {
            f=sys[1][0];
            for(k=0; k<=n; k++)
            {
                sys[1][k]=sys[1][k]+(sys[0][k]*abs(f));
            }
            output();
            if(f!=-1) cout<<"R2' = R2 + "<<abs(f)<<"R1\n";
            else cout<<"R2' = R2 + R1\n";
        }
    }

    if(sys[2][0]!=0)
    {
        if(sys[2][0]>0)
        {
            f=sys[2][0];
            for(k=0; k<=n; k++)
            {
                sys[2][k]=sys[2][k]-(sys[0][k]*f);
            }
            output();
            if(f!=1) cout<<"R3' = R3 - "<<f<<"R1\n";
            else cout<<"R3' = R3 - R1\n";
        }
        else
        {
            f=sys[2][0];
            for(k=0; k<=n; k++)
            {
                sys[2][k]=sys[2][k]+(sys[0][k]*abs(f));
            }
            output();
            if(f!=-1) cout<<"R3' = R3 + "<<abs(f)<<"R1\n";
            else cout<<"R3' = R3 + R1\n";
        }
    }

    if(sys[1][1]==0)
    {
        if(sys[2][1]!=0)
        {
            for(k=0; k<=n; k++)
            {
                temp[k]=sys[1][k];
                sys[1][k]=sys[2][k];
                sys[2][k]=temp[k];
            }
            output();
            cout<<"Interchanging R2 and R3\n";
        }
        else if(sys[1][2]==0 && sys[2][2]!=0)
        {
            for(k=0; k<=n; k++)
            {
                temp[k]=sys[1][k];
                sys[1][k]=sys[2][k];
                sys[2][k]=temp[k];
            }
            output();
            cout<<"Interchanging R2 and R3\n";
        }
        if(sys[1][2]!=0)
        {
            if(sys[1][2]!=1)
            {
                f=sys[1][2];
                for(k=0; k<=n; k++)
                {
                    sys[1][k]/=f;
                }
                output();
                cout<<"R2' = R2/"<<f<<"\n";
            }
        }
    }
    if(sys[1][1]!=0)
    {
        if(sys[1][1]!=1)
        {
            f=sys[1][1];
            for(k=0; k<=n; k++)
            {
                sys[1][k]/=f;
            }
            output();
            cout<<"R2' = R2/"<<f<<"\n";
        }
    }
    if(sys[2][1]!=0)
    {
        if(sys[2][1]>0)
        {
            f=sys[2][1];
            for(k=0; k<=n; k++)
            {
                sys[2][k]=sys[2][k]-(sys[1][k]*f);
            }
            output();
            if(f!=1) cout<<"R3' = R3 - "<<f<<"R2\n";
            else cout<<"R3' = R3 - R2\n";
        }
        else
        {
            f=sys[2][1];
            for(k=0; k<=n; k++)
            {
                sys[2][k]=sys[2][k]+(sys[1][k]*abs(f));
            }
            output();
            if(f!=-1) cout<<"R3' = R3 + "<<abs(f)<<"R2\n";
            else cout<<"R3' = R3 + R2\n";
        }
    }
    if(sys[2][2]!=0)
    {
        if(sys[2][2]!=1)
        {
            f=sys[2][2];
            for(k=0; k<=n; k++)
            {
                sys[2][k]/=f;
            }
            output();
            cout<<"R3' = R3/"<<f<<"\n";
        }
        x3=sys[2][3];
        x2=sys[1][3]-(sys[1][2]*x3);
        x1=sys[0][3]-(sys[0][2]*x3)-(sys[0][1]*x2);
        cout<<"(x1, x2, x3) = ("<<x1<<", "<<x2<<", "<<x3<<").";
    }
    else
    {
        if(abs(sys[2][0])+abs(sys[2][1])+abs(sys[2][1])==0)
        {
            if(abs(sys[2][3])==0)
            {
                cout<<"Free variables\n";
            }
            else
            {
                cout<<"No solution\n";
            }
        }
    }
}


int main()
{
    input();
    if(n==3) steps_3();
    return 0;
}

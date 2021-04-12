#include <iostream>
#include<conio.h>
#include<ctime>

using namespace std;

int m[4][4] = {0}, t[4][4] = {0}, hs;

void print()
{
    cout<<"  ____________________\n";
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(m[i][j]==0)
                cout<<"  | |";
            else
                cout<<"  |"<<m[i][j]<<"|";
        }
        cout<<"\n  ____________________\n\n";
    }
}

void moveup()
{
    for(int j=0;j<4;j++)
    {
        int a=0;
        for(int i=1;i<4;i++)
        {
            if(m[i][j]!=0)
            {
                if(m[i-1][j]==0 || m[i-1][j]==m[i][j])
                {
                    if(m[a][j]==m[i][j])
                    {
                        m[a][j]*=2;
                        m[i][j]=0;
                    }
                    else if(m[a][j]==0)
                    {
                        m[a][j]=m[i][j];
                        m[i][j]=0;
                    }
                    else
                    {
                        m[++a][j]=m[i][j];
                        m[i][j]=0;
                    }
                }
                else
                    a++;
            }
        }
    }
}

void movedown()
{
    for(int j=0;j<4;j++)
    {
        int a=3;
        for(int i=2;i>=0;i--)
        {
            if(m[i][j]!=0)
            {
                if(m[i+1][j]==0 || m[i+1][j]==m[i][j])
                {
                    if(m[a][j]==m[i][j])
                    {
                        m[a][j]*=2;
                        m[i][j]=0;
                    }
                    if(m[a][j]==0)
                    {
                        m[a][j]=m[i][j];
                        m[i][j]=0;
                    }
                    else
                    {
                        m[--a][j]=m[i][j];
                        m[i][j]=0;
                    }
                }
                else
                    a--;
            }
        }
    }
}

void moveright()
{
    for(int i=0;i<4;i++)
    {
        int a=3;
        for(int j=2;j>=0;j--)
        {
            if(m[i][j]!=0)
            {
                if(m[i][j+1]==0 || m[i][j+1]==m[i][j])
                {
                    if(m[i][a]==m[i][j])
                    {
                        m[i][a]*=2;
                        m[i][j]=0;
                    }

                    else if(m[i][a]==0)
                    {
                        m[i][a]=m[i][j];
                        m[i][j]=0;
                    }

                    else
                    {
                        m[i][--a]=m[i][j];
                        m[i][j]=0;
                    }
                }
                else
                    a--;
            }
        }
    }
}


void moveleft()
{
    for(int i=0;i<4;i++)
    {
        int a=0;
        for(int j=1;j<4;j++)
        {
            if(m[i][j]!=0)
            {
                if(m[i][j-1]==0 || m[i][j-1]==m[i][j])
                {
                    if(m[i][a]==m[i][j])
                    {
                        m[i][a]*=2;
                        m[i][j]=0;
                    }
                    else if(m[i][a]==0)
                    {
                        m[i][a]=m[i][j];
                        m[i][j]=0;
                    }
                    else
                    {
                        m[i][++a]=m[i][j];
                        m[i][j]=0;
                    }
                }
                else
                    a++;
            }
        }
    }
}


int same()      //function to check if the temporary array and the main array
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(t[i][j]!=m[i][j])        //checking for not equal as it will take less iterations and time to find a dissimilar cell
                return 0;
        }
    }
    return 1;
}

void add()      //function to add a 4 or a 2 randomlu
{
    int a, b, c;
    srand(time(0));
    if(((rand()%4)/2)==0)
        c=4;
    else
        c=2;
    while(1)
    {
        a=rand()%4;
        b=rand()%4;
        if(m[a][b]==0)
            m[a][b]=c;
        break;
    }
}

int notloser()  //function to check if the game is over
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(m[i][j]==m[i+1][j])
                return 1;
            if(m[i][j]==m[i][j+1])
                return 1;
        }
    }

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(m[i][j]==0)
                return 1;
        }
    }

    return 0;
}

void highscore()
{
    int temp=m[0][0];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(m[i][j]>=temp)
                temp=m[i][j];
        }
    }
    hs=temp;
}


int main()
{
    int i,j,a,b,c,d;
    char ch;
    srand(time(0));
    a=rand()%4;
    b=rand()%4;
    while(1)
    {
        c=rand()%4;
        d=rand()%4;
        if(a!=c && b!=d)
            break;
    }
    m[a][b]=4;
    m[c][d]=2;

    cout<<"\n\n";
    print();

    while(1)
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                t[i][j]=m[i][j];
        cout<<" Enter in w, a, s or d for up, left, down or right\n\n\n  ";
        cin>>ch;

        if(ch =='w'|| ch=='W')
            moveup();
        else if(ch=='s' || ch=='S')
            movedown();
        else if(ch== 'a' || ch=='A')
            moveleft();
        else if(ch=='d'||ch=='D')
            moveright();
        else if(ch=='p' ||ch=='P')
            exit(2);
	else
	    continue;

        if(same()==0)
            add();
        system("cls");
        highscore();
        cout<<"\n\t Score :"<<hs<<"\n";
        print();


        if(notloser()==0)
        {
            highscore();
            cout<<"\t\tGAME OVER\n\tThe HIGHSCORE is "<<hs;
            cout<<"\n\t\tPress any key to exit the program";
            getch();
            break;
        }


    }
}

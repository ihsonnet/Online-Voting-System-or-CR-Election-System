//Basic Version

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

/*struct studentinfo
{
  int id;
  int lastdigitphone;
  bool isvotedone;
  int candidateidvote;
};*/

int main()
{
  int NumCan,i,j,NumStu,VoteFor[10],Vote,max;
  char CanName[10][1000],id[100][1000],ch;
  cout<<endl<<"                     Online Voting System / CR Election System                   "<< endl;
  cout<<"                     _________________________________________                   "<< endl;
  cout<<endl<< ":::::::::: ADMIN PANEL ::::::::::" << endl;
  cout<<endl<< "Number of Candidate: ";
  cin>>NumCan;
  if(NumCan>1)
  {
      for(i=1;i<=NumCan;i++)
      {
        cout<<"Candidate-"<<i<<" Name: ";
        cin>>CanName[i];
        VoteFor[i]=0;
      }
      cout<< "Number of Students: ";
      cin>>NumStu;
      cout <<endl<< "Thank You Admin! we are going to start our election with " <<NumStu<<" Students and "<<NumCan<<" Candidates."<<endl;
      cout<<endl<<":::::::::: VOTING PANEL ::::::::::" << endl;
      for(i=1;i<=NumStu;i++)
      {
        cout<<endl<< ":: Student "<<i<<" ::"<<endl;
        cout<<endl<< "What is your ID Number?"<<endl;
        cin>>id[i];
        cout<<endl<<"Oky! "<<id[i]<<" Please Put Your Vote:"<<endl;

        for(j=1;j<=NumCan;j++)
        {
          cout<<"Press "<<j<<" For "<<CanName[j]<<endl;
        }
        ch=getch();
        Vote=ch-48;
        //cin>>Vote;
        for(j=1;j<=NumCan;j++)
        {
          if(Vote==j)
          {
              VoteFor[j]++;
              break;
          }
        }
        system("CLS");
        cout<<endl<<"Thanks! "<<id[i]<<" For Your Vote."<<endl;
        getch();
        system("CLS");
      }
      system("CLS");
      cout<<endl<<":::::::::: RESULT PANEL ::::::::::" << endl;
      cout<<endl;
      for(j=1;j<=NumCan;j++)
      {
        cout<<CanName[j]<<" Get "<<VoteFor[j]<<" Vote."<<endl;
      }
      max=0;
      for(j=1;j<=NumCan;j++)
      {
        if(max<VoteFor[j])
        {
          max=VoteFor[j];
        }
      }
      for(j=1;j<=NumCan;j++)
      {
        if(max==VoteFor[j])
        {
          cout<<endl<<"Congratulations "<<CanName[j]<<". You are Elected as our new CR."<< endl;
          break;
        }
      }

  }
  else
  {
      cout<<endl<<"Sorry! Number of Candidate must be more than one person."<<endl;
  }
  getch();
}


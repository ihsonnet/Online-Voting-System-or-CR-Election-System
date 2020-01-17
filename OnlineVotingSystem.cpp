//with password verification
//pass:mypass

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

int main()
{
    int NumCan,isfound,i,j,NumStu,VoteFor[10],Vote,max;
    char CanName[10][1000],id[100][1000],ch;
    char pass[50];
    cout<<endl<<"                     Online Voting System / CR Election System                   "<< endl;
    cout<<"                     _________________________________________                   "<< endl;
    cout<<endl<<"                        :::::::::: ADMIN PANEL ::::::::::" << endl;
    cout<<endl<<"================================================================================="<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl<< "    Number of Candidate: ";
    cin>>NumCan;
    if(NumCan>1)
    {
        for(i=1; i<=NumCan; i++)
        {
            cout<<"    Candidate-"<<i<<" Name: ";
            cin>>CanName[i];
            VoteFor[i]=0;
        }
        cout<< "    Number of Students: ";
        cin>>NumStu;
        cout <<endl<< "  Thank You Admin! we are going to start our election with " <<NumStu<<" Students and "<<NumCan<<" Candidates."<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"================================================================================="<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"                            Enter The Password: ";
        cin>>pass;
        while(strcmp(pass,"mypass")!=0)
        {
          cout<< endl;
              cout<<endl<<"                            Wrong Password! Try Again."<<endl;
              cout<<endl;
              cout<<"                       Enter The Correct Password: ";
          cin>>pass;
          cout<<endl;
        }
        system("CLS");
        for(i=1; i<=NumStu; i++)
            {
                cout<<endl<<"                     Online Voting System / CR Election System                   "<< endl;
                cout<<"                     _________________________________________                   "<< endl;
                cout<<endl<<"                        :::::::::: VOTING PANEL ::::::::::" << endl;
                cout<<endl<<"                                   Student - "<<i<<endl;
                cout<<endl<<"================================================================================="<<endl;
                cout<<endl;
                cout<<endl;
                FILE *filepointer;
                char datatoberead[50];
                filepointer = fopen("ID.txt","r");
                char inputid[50];
                cout<<endl<<"                             Enter Your ID: ";
                cin >> inputid;
                strcat(inputid,"\n");
                int c=0;
                while(fgets(datatoberead,50,filepointer)!=NULL)
                {
                    c++;
                    if(strcmp(inputid,datatoberead)==0)
                    {
                        cout << "                                    Data found!" << endl;
                        FILE *filepointer2;
                        char datatoberead2[50];
                        filepointer2 = fopen("Name.txt","r");
                        int d=0;
                        while(fgets(datatoberead2,50,filepointer2)!=NULL)
                        {
                            d++;
                            if(c==d)
                            {
                                cout<<endl<<endl<<"    Name: "<<datatoberead2<<endl;
                                cout<<"    ID: "<<inputid<<endl;
                            }

                        }
                        fclose(filepointer2);
                        fclose(filepointer);
                        break;
                    }
                    //else
                    //{
                    //cout << "Sorry ID Not Found! or you type wrong ID. Please Try Again."<< endl;
                    //t++;
                    //break;
                    //}
                }
                cout<<endl<<"                  ==========================================="<<endl;
                cout<<endl;
                cout<<endl;

                for(j=1; j<=NumCan; j++)
                {
                    cout<<"                              Press "<<j<<" For "<<CanName[j]<<endl;
                }
                cout<<endl;
                cout<<endl<<"                  ==========================================="<<endl;
                cout<<endl<<"    Now, Please Put Your Vote: ";
                ch=getch();
                Vote=ch-48;
                cout<<"(Hidden)";
                //cin>>Vote;

                FILE *filepointer3;
                char datatobewrite[50];
                strcpy(datatobewrite,inputid);
                filepointer3 = fopen("VoteDoneBy.txt","a");
                if ( strlen (  datatobewrite  ) > 0 )
                {
                    fputs(datatobewrite, filepointer3) ;
                }

                fclose(filepointer3) ;

                FILE *filepointer4;
                char datatobewrite2[50];
                strcpy(datatobewrite2,inputid);
                strcat(datatobewrite2,CanName[Vote]);
                strcat(datatobewrite2,"\n");
                filepointer4 = fopen("VoteDetails.txt","a");
                if ( strlen (  datatobewrite2  ) > 0 )
                {
                    fputs(datatobewrite2, filepointer4) ;
                }

                fclose(filepointer4) ;

                for(j=1; j<=NumCan; j++)
                {
                    if(Vote==j)
                    {
                        VoteFor[j]++;
                        break;
                    }
                }
                cout<<endl;
                cout<<endl;
                cout<<endl<<"                  Thanks"<<id[i]<<" For Your Vote.(Press Enter for Next)"<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"================================================================================="<<endl;
                getch();
                system("CLS");
            }
            system("CLS");
            cout<<endl<<"                     Online Voting System / CR Election System                   "<< endl;
            cout<<"                     _________________________________________                   "<< endl;
            cout<<endl<<"                        :::::::::: RESULT PANEL ::::::::::" << endl;
            cout<<endl<<"================================================================================="<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"                            Enter The Password: ";
            cin>>pass;
            while(strcmp(pass,"mypass")!=0)
            {
              cout<< endl;
              cout<<endl<<"                            Wrong Password! Try Again."<<endl;
              cout<<endl;
              cout<<"                       Enter The Correct Password: ";
              cin>>pass;
              cout<<endl;
            }
            cout<<endl;
            cout<<endl;
            cout<<endl<<"                  ==========================================="<<endl;
            cout<<endl;
            cout<<endl;
            for(j=1; j<=NumCan; j++)
            {
                cout<<"                              "<<CanName[j]<<" Get "<<VoteFor[j]<<" Vote."<<endl;
            }
            cout<<endl;
            cout<<endl;
            cout<<endl<<"                  ==========================================="<<endl;
            max=0;
            for(j=1; j<=NumCan; j++)
            {
                if(max<VoteFor[j])
                {
                    max=VoteFor[j];
                }
            }
            for(j=1; j<=NumCan; j++)
            {
                if(max==VoteFor[j])
                {
                    cout<<endl;
                    cout<<endl<<"           Congratulations "<<CanName[j]<<". You are Elected as our new CR."<< endl;
                    break;
                }
            }
            cout<<endl;
            cout<<endl;
            cout<<"================================================================================="<<endl;
        }
    else
    {
        cout<<endl<<"Sorry! Number of Candidate must be more than one person."<<endl;
    }
    getch();
}



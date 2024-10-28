#include <bits/stdc++.h>
using namespace std;
struct record
{
    int id;
    string name;
    string phone;
    string blood_group;
    string city;
};
struct record2
{
    int id;
    string name;
    int age;
    string phone;
    string profession;
    string vaccine="Not_vaccinated";
    int choice;
};

void updateList(record (&List)[10000], int index, int maxSize)
{
    for(int j=index; j<maxSize-1; j++)
    {
        List[j].id=List[j+1].id-1;
        List[j].name=List[j+1].name;
        List[j].phone=List[j+1].phone;
        List[j].blood_group=List[j+1].blood_group;
    }
}
void donorList(record (&List)[10000], int maxSize)
{
    if(maxSize==0)
    {
        printf("Donor list is empty\n");
        return;
    }
    printf("\n\t\t  Current all donors list: \n");
    for(int j=1; j<maxSize; j++)
    {
        printf("Id: %d\n",List[j].id);
        cout<<"Name: "<<List[j].name<<"\n";
        cout<<"Phone: "<<List[j].phone<<"\n";
        cout<<"Blood group: "<<List[j].blood_group<<"\n";
        cout<<"City: "<<List[j].city<<"\n\n";
    }
}
//covid project
void covidList(record2 (&List)[10000], int maxSize,vector<pair<int,int>>&Operation_Data)
{
    if(Operation_Data.size()==0)
    {
        printf("covid List is empty\n");
        return;
    }
    printf("\n\t  Current all register people list: \n");
    int idd;
    for(int j=0; j<Operation_Data.size(); j++)
    {
        idd=Operation_Data[j].second;
        printf("Id: %d\n",List[idd].id);
        cout<<"Name: "<<List[idd].name<<"\n";
        cout<<"Age: "<<List[idd].age<<"\n";
        cout<<"Phone: "<<List[idd].phone<<"\n";
        cout<<"Profession: "<<List[idd].profession<<"\n";
        cout<<"Vaccine status: "<<List[idd].vaccine<<"\n";
        cout<<"Choice: "<<List[idd].choice<<"\n\n";
    }
}
int operation(record2 (&List)[10000], int maxSize,vector<pair<int,int>>&Operation_Data)
{

    for(int j=0; j<Operation_Data.size(); j++)
    {
        int id=Operation_Data[j].second;
        if(List[id].vaccine=="Not_vaccinated")
        {
            cout<<"\n\t  The most qualified person for vaccine: \n";
            cout<<"Name: "<<List[id].name<<"\n";
            cout<<"Age: "<<List[id].age<<"\n";
            cout<<"Phone: "<<List[id].phone<<"\n";
            cout<<"Profession: "<<List[id].profession<<"\n";
            cout<<"Vaccine status: "<<List[id].vaccine<<"\n";
            cout<<"Choice: "<<List[id].choice<<"\n\n";
            List[id].vaccine="Vaccinated";
            return id;
        }
    }
    return -1;
}
//blood bank project
int main()
{
    int n,day;


    puts("Press 1: Blood bank project\n");
    puts("Press 2: Covid-19 Vaccine Project\n");
    scanf("%d",&n);
    while(n==1)
    {
        printf("\t\t======================================\n");
        printf("\t\t    Welcome to Blood Bank Project     \n");
        printf("\t\t======================================\n");
        record donor[10000];
        int choice,current_size_donor=1,current_size_patient=1;
        while(1)
        {
            printf("\nPress 1: For update donor list\nPress 2: To view available donor list\nPress 3: For donor search\nor press any key to terminate program\n\n");
            scanf("%d",&choice);
            if(choice==1)
            {
                if(current_size_donor==10000)
                {
                    printf("Donor list is full\n");
                    continue;
                }

                donor[current_size_donor].id=current_size_donor;

                printf("Donor Name: ");
                cin>>donor[current_size_donor].name;

                printf("Donor Phone Number: ");
                cin>>donor[current_size_donor].phone;

                printf("Donor Blood Group: ");
                cin>>donor[current_size_donor].blood_group;

                printf("Donor City: ");
                cin>>donor[current_size_donor].city;

                printf("How many days before you last donated blood: ");
                scanf("%d",&day);

                if(day<=56)
                    printf("Donor is not eligible\n");

                current_size_donor++;
            }
            else if(choice==2)
                donorList(donor,current_size_donor);
            else if(choice==3)
            {
                record patient;
                printf("Patient Name: ");
                cin>>patient.name;

                printf("Patient Phone Number: ");
                cin>>patient.phone;

                printf("Patient Blood Group: ");
                cin>>patient.blood_group;

                printf("Patient City: ");
                cin>>patient.city;

                int result =0;
                for(int j=1; j<current_size_donor; j++)
                {
                    if(patient.blood_group==donor[j].blood_group && donor[j].city == patient.city)
                    {
                        printf("\n\t One of Blood donor is available according to blood group and city: \n");
                        printf("Id: %d\n",donor[j].id);
                        cout<<"Name: "<<donor[j].name<<"\n";
                        cout<<"Phone: "<<donor[j].phone<<"\n";
                        cout<<"Blood group: "<<donor[j].blood_group<<"\n";
                        cout<<"City: "<<donor[j].city<<"\n\n";
                        updateList(donor,j,current_size_donor);
                        current_size_donor--;
                        result=1;
                        break;
                    }

                }
                if(result==0)
                    puts("No donor was found");

            }
            else
                break;
        }
    }


    ///Covid-19 project
    while(n==2)
    {

        printf("\t\t====================================================\n");
        printf("\t\t    Welcome to Covid-19 Vaccine giving project     \n");
        printf("\t\t====================================================\n");
        record2 covid_vacc[10000];
        int vaccine[]= {10000,10000,10000,10000},current_size_covid=1,choice;
        vector<pair<int,int>>Operation_Data;
        while(1)
        {
            printf("\nPress 1: To register for first vaccine\nPress 2: To view registered list\nPress 3: For most qualified candidate\nor press any key to terminate program\n\n");
            scanf("%d",&choice);
            if(choice==1)
            {
                covid_vacc[current_size_covid].id=current_size_covid;

                printf("Name: ");
                cin>>covid_vacc[current_size_covid].name;

                printf("Age: ");
                cin>>covid_vacc[current_size_covid].age;

                printf("Phone number: ");
                cin>>covid_vacc[current_size_covid].phone;

                printf("Profession: ");
                cin>>covid_vacc[current_size_covid].profession;

                printf("Which type of vaccine you want to inject?\ntype 1 for Moderna\ntype 2 for Phifzer\ntype 3 for Astrozenica\n\n");
                cin>>covid_vacc[current_size_covid].choice;


                Operation_Data.push_back({covid_vacc[current_size_covid].age,covid_vacc[current_size_covid].id});
                current_size_covid++;

            }
            else if(choice==2)
                covidList(covid_vacc,current_size_covid,Operation_Data);
            else if(choice==3){
                    sort(Operation_Data.rbegin(),Operation_Data.rend());///pair, vector's pair, vector's pair sorting
                    int id=operation(covid_vacc,current_size_covid,Operation_Data);
                    if(id<0){
                        puts("No one available to be vaccinated\n");
                        continue;
                    }
                    if(vaccine[1]>0 || vaccine[2]>0 || vaccine[3]>0){
                        if(vaccine[covid_vacc[id].choice]==0){
                            if(covid_vacc[id].choice+1<=3 && vaccine[covid_vacc[id].choice]+1>0) covid_vacc[id].choice++;
                            else if(covid_vacc[id].choice+2<=3 && vaccine[covid_vacc[id].choice]+2>0) covid_vacc[id].choice+=2;
                            else if(covid_vacc[id].choice-1>=1 && vaccine[covid_vacc[id].choice]-1>0) covid_vacc[id].choice--;
                            else if(covid_vacc[id].choice-2>=1 && vaccine[covid_vacc[id].choice]-2>0) covid_vacc[id].choice-=2;

                            vaccine[covid_vacc[id].choice]--;
                        }
                        else{
                            vaccine[covid_vacc[id].choice]--;
                        }
                    }
                    else puts("No vaccine is available");
                }
                else break;
            }
        }
}

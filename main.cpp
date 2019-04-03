#include<bits/stdc++.h>
using namespace std;
void main_menu();
void sort_data();
void add_data();
void update_data();
void delete_data();
float calculate_gpa();
float cal_cgpa();
float calculate_gpa()
{
    int n;
    cout<<"Enter number of course : ";
    cin>>n;
    int i,a;
    float credit,full_credit=0;
    double sum=0;
    int count=0;
    for(i=0;i<n;i++)
    {
        cout<<" Enter the credit of "<<i+1<<"th subject :";
        cin>>credit;
        cout<<"Enter "<<i+1<<"th subject marks :";
        cin>>a;
        if(a>=80)
        {
            sum+=4.0*credit;
            full_credit+=credit;
        }
        else if(a>=75)
        {
            sum+=3.75*credit;
            full_credit+=credit;
        }
        else if(a>=70)
        {
            sum+=3.5*credit;
            full_credit+=credit;
        }
        else if(a>=65)
        {
            sum+=3.25*credit;
            full_credit+=credit;
        }
        else if(a>=60)
        {
            sum+=3.0*credit;
            full_credit+=credit;
        }
        else if(a>=55)
            {sum+=2.75*credit;
            full_credit+=credit;
            }
        else if(a>=50)
            {sum+=2.5*credit;
            full_credit+=credit;
            }
        else if(a>=45)
            {sum+=2.25*credit;
            full_credit+=credit;
            }
        else if(a>=40)
            {
                sum+=2.0*credit;
            full_credit+=credit;
            }
        else
            count++;

    }
    double x=(sum)/full_credit;
    cout<<"Your gpa is "<<x<<endl;
    if(count>0)
        cout<<"you failed in : "<<count<<" subject "<<endl;

}
float cal_cgpa()
{
    cout<<"Enter term number : "<<endl;
    int n;
    cin>>n;
    int i;
    float gpa,sum;
    for(i=0;i<n;i++)
    {
        cout<<"Enter "<<i+1<<"th term gpa : ";
        cin>>gpa;
        sum+=gpa;
    }
    cout<<endl<<"Your cgpa is "<<sum/(float)n<<endl;

}

namespace database
{
    class student
    {
    protected:
        string name;
    public:
        int roll;
    public:
        virtual void getinfo()
        {
            cout<<"Enter your roll(int): ";
            cin>>roll;
            cout<<"Enter your name: ";
            cin>>name;
        }
    };
    class data:public student
    {
    protected:
        float cgpa;
    public:
        data()///default
        {
            roll=0;
            name="";
            cgpa=0.0;
        }
        data(int roll,string name,float cgpa)///parameterized
        {
            this->roll=roll;
            this->name=name;
            this->cgpa=cgpa;
        }
        data(const data &pip)///copy constructor
        {
            roll=pip.roll;
            name=pip.name;
            cgpa=pip.cgpa;
        }
        void getinfo();
        friend ostream& operator<<(ostream &out,database::data &abc);
        friend istream& operator>>(istream &in,database::data &abc);
        friend ifstream& operator>>(ifstream &pip,data &abc);
        friend ofstream& operator<<(ofstream &pip,data &abc);
    };
    void data::getinfo()
        {
            cout<<"Enter your roll: ";
            cin>>roll;
            cout<<"Enter your name: ";
            cin>>name;
            cout<<"Now you have to put your cgpa "<<endl;
            cout<<"If you don't know cgpa or gpa you can calculate this "<<endl;
            cout<<"1.press 1 for entering cgpa \n2.press 2 for calculating cgpa\n";
            cout<<"3.press 3 for calculating gpa "<<endl;
            int pip;
            cout<<"Enter your choice : ";
            cin>>pip;
            if(pip==1)
            {
                cout<<"Enter your cgpa : ";
                cin>>cgpa;
            }
            else if(pip==2)
            {
                cal_cgpa();
                cout<<"Enter your cgpa: ";
                cin>>cgpa;
            }
            else if(pip==3)
            {
                calculate_gpa();
                cout<<"1.press 1 for calculating cgpa\n2.press 2 for entering cgpa"<<endl;
                int ppp;
                cout<<"Enter your choice : ";
                cin>>ppp;
                if(ppp==1)
                    {cal_cgpa();
                    cout<<"Enter your cgpa: ";
                    cin>>cgpa;
                    }
                else if(ppp==2)
                {
                    cout<<"Enter cgpa : ";
                    cin>>cgpa;
                }

            }
        }
ostream& operator<<(ostream &out,database::data &abc)
{
    out<<"Roll: "<<abc.roll<<endl;
    out<<"Name : "<<abc.name<<endl;
    out<<"CGPA : "<<abc.cgpa<<endl;
}
istream& operator>>(istream &in,database::data &abc)
{
    cout<<"Enter your roll: ";
    in>>abc.roll;
    cout<<"Enter your name: ";
    in>>abc.name;
    cout<<"Enter your cgpa: ";
    in>>abc.cgpa;
}
ifstream& operator>>(ifstream &pip,data &abc)
{
    pip>>abc.roll;
    pip>>abc.name;
    pip>>abc.cgpa;
}
ofstream& operator<<(ofstream &pip,data &abc)
{
    pip<<setw(10)<<setiosflags(ios::left)<<abc.roll;
    pip<<setw(10)<<setiosflags(ios::left)<<abc.name;
    pip<<setw(10)<<setiosflags(ios::left)<<abc.cgpa<<endl;
}
class ftr
{
public:
    bool operator()(database::data x,database::data y)
    {
        return x.roll<y.roll;
    }
};
}
void delete_data()
{
    system("cls");
    system("color 1A");
    int num;
    cout<<"Enter a num you wanted to delete: ";
    cin>>num;
    using namespace database;
    vector<data>vec;
    data cd;
    ifstream fin("output.txt");
    string a;
    getline(fin,a);
    int p=0;
    while(!fin.eof())
    {
        fin>>cd;
        if(cd.roll==num)
        {
            p=1;
        }
        else
            vec.push_back(cd);
    }
    ///vec.pop_back();
    fin.close();
    if(p==0)
        cout<<num<<" Not found "<<endl;
    else
    {
        ofstream fout("output.txt");
        vector<data>::iterator dd;
        fout<<a<<endl;
        cout<<"Ater deleting the contents of roll no. "<<num<<endl;
        for(dd=vec.begin();dd!=vec.end();dd++)
           {
            fout<<*dd;
            cout<<*dd;
           }
    }


    cout<<endl<<endl<<"\t\t1.press 1 for go to main menu "<<endl;
    cout<<"\t\t2.press 2 for exit"<<endl;
    int bla_bla;
    cout<<"\t\t\tEnter your choice : ";
    cin>>bla_bla;
    if(bla_bla==1)
        main_menu();
    else
        return ;

}
void sort_data()
{

    using namespace database;
    data bbb;

    vector<data>vec;

    ifstream fin("output.txt");
    string bb;
    getline(fin,bb);
    while(!fin.eof())
    {
        fin>>bbb;
        vec.push_back(bbb);
    }
    fin.close();
    vec.pop_back();
    ofstream ft("output.txt");
    sort(vec.begin(),vec.end(),ftr());
    vector<data>::iterator ttt;
    ft<<bb<<endl;
    cout<<"\n\n\nAfter sorted"<<endl<<endl<<endl;
    for(ttt=vec.begin();ttt<vec.end();ttt++)
    {
        ft<<*ttt;
        cout<<*ttt<<endl;
    }


    cout<<endl<<endl<<"\t\t1.press 1 for go to main menu "<<endl;
    cout<<"\t\t2.press 2 for exit"<<endl;
    int bla_bla;
    cout<<"\t\t\tEnter your choice : ";
    cin>>bla_bla;
    if(bla_bla==1)
        main_menu();
    else
        return ;


}
void add_data()
{
    system("cls");
    system("color 0B");
    using namespace database;
    data pip;
    pip.getinfo();
    ofstream fout("output.txt",fstream::app);
    fout<<pip;
    fout.close();


    cout<<endl<<endl<<"\t\t1.press 1 for go to main menu "<<endl;
    cout<<"\t\t2.press 2 for exit"<<endl;
    int bla_bla;
    cout<<"\t\t\tEnter your choice : ";
    cin>>bla_bla;
    if(bla_bla==1)
        main_menu();
    else
        return ;
}
void search_data()
{
    using namespace database;
    ifstream fin("output.txt");
    string a;
    data xy;
    cout<<"Enter a roll number you want to search: "<<endl;
    int num,x=0;
    cin>>num;
    cin.ignore();
    string ara;
    cout<<"Enter your name : "<<endl;
    getline(cin,ara);
    getline(fin,a);

    while(!fin.eof())
    {
        fin>>xy;
        if(xy.roll==num)
        {
            cout<<"Hey   ,"<<ara<<"  Here is the Contents of your searched roll number "<<endl;
            cout<<xy<<endl;
            x=1;
            break;
        }
    }
    if(x==0)
        cout<<"Hey , "<<ara<<" "<<num<<" roll is Not found in the database"<<endl;



    cout<<endl<<endl<<"\t\t1.press 1 for go to main menu "<<endl;
    cout<<"\t\t2.press 2 for exit"<<endl;
    int bla_bla;
    cout<<"\t\t\tEnter your choice : ";
    cin>>bla_bla;
    if(bla_bla==1)
        main_menu();
    else
        return ;


}
void update_data()
{
    system("cls");
    system("color 0B");
    using namespace database;
    int num;
    cout<<"Enter the roll no. which data you wanted to update: ";
    cin>>num;
    vector<data>vec;
    data cd;
    ifstream fin("output.txt");
    string a;
    getline(fin,a);
    int p=0;
    vector<data>::iterator it;
    while(!fin.eof())
    {
        fin>>cd;
        if(cd.roll==num)
        {
            p=1;
            cout<<"Enter your new roll,name and cgpa : "<<endl;
            cin>>cd;
            vec.push_back(cd);
        }
        else
            vec.push_back(cd);
    }
    vec.pop_back();
    fin.close();
    ofstream fout("output.txt");
    fout<<a<<endl;
    for(it=vec.begin();it!=vec.end();it++)
    {
        fout<<*it;
        cout<<*it<<endl;
    }
    if(p==0)
        cout<<num<<"roll is not found"<<endl;

    cout<<endl<<endl<<"\t\t1.press 1 for go to main menu "<<endl;
    cout<<"\t\t2.press 2 for exit"<<endl;
    int bla_bla;
    cout<<"\t\t\tEnter your choice : ";
    cin>>bla_bla;
    if(bla_bla==1)
        main_menu();
    else
        return ;
}
void main_menu()
{
    using namespace database;
    cout<<"1.press 1 for insert student data"<<endl;
    cout<<"2.press 2 for update a data"<<endl;
    cout<<"3.press 3 for delete a data"<<endl;
    cout<<"4.press 4 for sort by roll number or show"<<endl;
    cout<<"5.press 5 for calculating gpa "<<endl;
    cout<<"6.press 6 for calcultaing cgpa"<<endl;
    cout<<"7.press 7 for exit"<<endl;
    int choice;
    cout<<endl<<endl<<"\t\tEnter your choice: ";
    cin>>choice;
    if(choice==1)
        add_data();
    else if(choice==2)
        update_data();
    else if(choice==3)
        delete_data();
    else if(choice==4)
        sort_data();
    else if(choice==5)
        {
            calculate_gpa();
            cout<<endl<<endl<<"\t\t1.press 1 for go to main menu "<<endl;
    cout<<"\t\t2.press 2 for exit"<<endl;
    int bla_bla;
    cout<<"\t\t\tEnter your choice : ";
    cin>>bla_bla;
    if(bla_bla==1)
        main_menu();
    else
        return ;
        }

    else if(choice==6)
    {
        cal_cgpa();
        cout<<endl<<endl<<"\t\t1.press 1 for go to main menu "<<endl;
    cout<<"\t\t2.press 2 for exit"<<endl;
    int bla_bla;
    cout<<"\t\t\tEnter your choice : ";
    cin>>bla_bla;
    if(bla_bla==1)
        main_menu();
    else
        return ;
    }
    else if(choice==7)
        return;
    else
        cout<<"Invalid choice "<<endl;
}
int main()
{
    using namespace database;
    main_menu();
    ///add_data();
    ///add_data();
    ///sort_data();
    ///calculate_gpa();
    ///cal_cgpa();
    ///data ab;
    ///cout<<ab[1];
    ///delete_data();
    ///update_data();
    ///search_data();
}

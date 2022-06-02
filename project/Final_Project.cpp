#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
struct Donor
{
	string donname;
	string donblood;
	string donphone;
};
void Input_Name(Donor array[100]){
	int providers;
	ofstream file;
	file.open("bds_donor_data.txt",ios::app);
	cout<<"Enter number of donors you want to add: ";
	cin>>providers;
	for(int i=0;i<providers;i++)
	{
		cout<<"\t\tMember: "<<i+1<<endl;
		cin.ignore();
		cout<<"Full name: ";
		getline(cin,array[i].donname);
		cout<<"Blood Group: ";
		cin>>array[i].donblood;
		cout<<"Enter phone number:";
		cin>>array[i].donphone;
		
		file<<array[i].donname<<endl;
		file<<array[i].donblood<<endl;
		file<<array[i].donphone<<endl;
		}
	file.close();
	cout<<endl;
}
void Read_Data(Donor array[100],int h)
{
	ifstream file;
	file.open("bds_donor_data.txt",ios::app);
	
	while(!file.eof()){
		getline(file,array[h].donname);
		getline(file,array[h].donblood);                       
		getline(file,array[h].donphone);
	h++;	
	}
	file.close();
	cout<<endl<<endl;
	cout<<" Name:\t"<<"  Blood type:\t"<<"Phone number: \n\n";
	for(int j=0;j<h;j++)
	{
		cout<<" "<<array[j].donname<<"       "<<array[j].donblood<<"              "<<array[j].donphone<<endl;
	}
}
 void Search_By_Name(string a, Donor array[100],int h,int m)
	{
		int beta=0;
	cout<<"Enter name: ";
	cin.ignore();
	getline(cin,a);
	ifstream file;
	file.open("bds_donor_data.txt",ios::app);
	while(!file.eof()){
	getline(file,array[h].donname);	
	getline(file,array[h].donblood);
	getline(file,array[h].donphone);
	h++;
	}
	for(int f=0;f<h;f++)
	{if (a==array[f].donname)
	{  
		cout<<"Name: "<<array[f].donname<<endl;
		cout<<"Blood Group: "<<array[f].donblood<<endl;
		cout<<"Phone: "<<array[f].donphone<<endl;
	beta=1;
	}
}
 if(beta==0){
	cout<<"No name matched with your search: ";
	}
	}
	void Search_By_Blood(string b, Donor array[100],int h, int m)
	{
		int found =0;
		cout<<"Enter blood type: ";
		cin>>b;
		ifstream file;
		file.open("bds_donor_data.txt",ios::app);
		while(!file.eof())
		{
			getline(file,array[h].donname);	
			getline(file,array[h].donblood);
			getline(file,array[h].donphone);
		h++;
		}
		for (int f=0;f<h;f++)
		{
			if(b==array[f].donblood)
			{
				cout<<"Name: "<<array[f].donname<<endl;
				cout<<"blood: "<<array[f].donblood<<endl;
				cout<<"phone number: "<<array[f].donphone<<endl;
					found=1;					
			}
  		}
		if(found==0){
			cout<<"No blood donor matched with your search"<<endl<<endl;
		}
	}
	void Update(string b, Donor array[100],int h, int m)
	{   int found=0;
		cout<<"Enter name: ";
		cin.ignore();
		getline (cin,b);
		ifstream file;
		file.open("bds_donor_data.txt",ios::app);
	while(!file.eof())
	{
		getline(file,array[h].donname);	
			getline(file,array[h].donblood);
			getline(file,array[h].donphone);
			h++;
	}
	file.close();
	ofstream subs;
	subs.open("substitute.txt");
	for (int f=0;f<h;f++){
		if(b!=array[f].donname){
			subs<<array[f].donname<<endl;
			subs<<array[f].donblood<<endl;
			subs<<array[f].donphone<<endl;
		}		
	if(b==array[f].donname)
	{  found=1;
		cout<<"Enter updated name: ";
		getline(cin,array[f].donname);
		subs<<array[f].donname<<endl;
		cout<<"Enter updated blood type: ";
		cin>>array[f].donblood;
		subs<<array[f].donblood<<endl;
		cout<<"Enter updated phone number: ";
		cin>>array[f].donphone;
		subs<<array[f].donphone<<endl;
	h++;
	}
}
subs.close();
remove("bds_donor_data.txt");
rename("substitute.txt","bds_donor_data.txt");
	if(found=0){
		cout<<"No person matched your search"<<endl<<endl;}
	}
	
	void Remove_Record(string b, Donor array[100],int h,int m)
	{
	cout<<"Enter name: ";
	cin.ignore();
	getline(cin,b);
	ifstream file;
	file.open("bds_donor_data.txt",ios::app);
	while(!file.eof())
	{
	getline(file,array[h].donname);
	getline(file,array[h].donblood);
	getline(file,array[h].donphone);
	h++;
	}
	file.close();
	ofstream subs;
	subs.open("substitute.txt");
	for(int f=0;f<h;f++){
		if(b!=array[f].donname)
		{
			subs<<array[f].donname<<endl;
			subs<<array[f].donblood<<endl;
			subs<<array[f].donphone<<endl;
		}
		if(b==array[f].donname)
		{
			m++;
		}
	}
	subs.close();
	remove("bds_donor_data.txt");
	rename("substitute.txt","bds_donor_data.txt");
	if(m==0)
	{
		cout<<"No person matched your search"<<endl<<endl;
	}
}
int main()
{
	Donor don[100],don1[100],don2[100],don3[100],don4[100],don5[100], don6[100];
	
	string avail;
	string identity;
	string redbloodcell;
	string updation;
	string removal;
	int i=0,j=0,k=0,b=0,v=0,p=0,u=0,t=0,x,y,z;
	cout<<"\t\t---------------------------------"<<endl;
	cout<<"\t\t  PUCIT BLOOD DONOR SOCIETY\n";
	cout<<"\t\t---------------------------------"<<endl;
	while (true)
	{
		cout<<"\n\t1.Add a new member"<<endl;
		cout<<"\t2.View the list of donors"<<endl;
		cout<<"\t3.Search record based on name"<<endl;
		cout<<"\t4.Search record based on blood"<<endl;
		cout<<"\t5.Update record"<<endl;
		cout<<"\t6.Remove record"<<endl;
		cout<<"\t7.Exit Program"<<endl;
		
			int choice;
			cin>>choice;
			while(choice<=0 || choice >7)
			{
				cout<<"Pick an option from 1 to 6";
				cout<<"\nEnter";
				cin>>choice;
			}
			if(choice==1)
			{
				Input_Name(don);
				i++;
				continue;
			}
			if(choice==2)
			{
				Read_Data(don1,j);
				continue;
			}
			if(choice==3)
			{
				Search_By_Name(identity,don2,i,k);
				continue;
			}
			if(choice==4)
			{
				Search_By_Blood(redbloodcell,don3,b,v);
				continue;
			}
			if(choice==5)
			{
				Update(updation,don4,p,u);
			}
			if(choice==6)
			{
				Remove_Record(removal,don6,y,t);
				continue;
			}
			if(choice==7)
			{
				cout<<"\n\n\tPROGRAM EXITED! :)\n";
			break;
			}
	}
return 0;
}




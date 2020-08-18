#include<iostream>
#include<fstream>
using namespace std;

class teacher{
	public:
	
	string name,surename,gender;
	int age;
		public:
	
		void set_name(string n)
		{
			name=n;
		}
		void set_surname(string s)
		{
			surename=s;
		}
		void set_gender(string g)
		{
			gender=g;
		}
		void set_age(int a)
		{
			age=a;
		}
		
	
		string get_name()
		{
			return this->name;
		}
		string get_surename()
		{
	      return this->surename;
		}
        string get_gender()
        {
        	return this->gender;
		}
		int get_age()
		{
			return this->age;
		}
};

class product{
   
   public:
   static string data_file;
   string iteme_name,item_id;
   int price;
   
   	
   	void set_item_name(string n)
   	{
   		this->iteme_name=n;
	}
	void set_item_id(string i)
	{
		this->item_id=i;
	}
	void set_price(int p)
	{
		this->price=p;
	}

	string get_item_name()
	{
		return this->iteme_name;
	}
	string get_item_id()
	{
		return this->item_id;
	}
	int get_price()
	{
		return this->price;
	}
    
	string get_data_file()
	{
			return this->data_file;
	}
};


class customer:public teacher{
     // Attributes
	 static string data_file;
	 string c_id;
     public:
     	// GETTERS
     	product p;
		 void set_customerid(string s)
     	{
     		this->c_id=s;
		}
		//SETTERS
        string get_customerid()
        {
        	return this->c_id;
		}
		string get_data_file()
		{
			return this->data_file;
		}

};

string customer :: data_file="teacher";
string product :: data_file="data";


class data{
	public:
	customer C[100];
	product P[100];
	int psize,csize;
	data()
	{  
	    
	   string c_id,name,sure,gend,iname,iid;
	   int pric,age;
	   ifstream cfile;
	   cfile.open("teacher.txt");
	   
	   if(cfile){
	   	int i=0;
		while(!cfile.eof())
	   	{   // READING CUSTOMER RECORD FROM DATA FILE CUSTOMER.TXT
	   		csize=i;
			cfile>>c_id>>name>>sure>>gend>>age>>iid>>iname>>pric;
	   	    C[i].set_age(age);C[i].set_customerid(c_id);C[i].set_gender(gend);C[i].set_name(name);C[i].set_surname(sure);
			C[i].p.set_item_id(iid);C[i].p.set_item_name(iname);C[i].p.set_price(pric);
			i++;
			
		}
	   }
	   else
	   cout<<"ERROR IN CUSTOMR FILE";
	   cfile.close();
	   
	   ifstream pfile;
	   pfile.open("data.txt");
	   
	   if(pfile){
		int x=0;
		while(!pfile.eof())
	   	{   // READING PRODUCT RECORD FROM DATA FILE PRODUCT.TXT
	   		psize=x;
			pfile>>iid>>iname>>pric;
	        P[x].set_item_id(iid);P[x].set_item_name(iname);P[x].set_price(pric); 		
			x++;
			
			
		}
		
	   }
	   pfile.close();
	}
	
	
	//SHOW PRODUCT RECORD
	void show_product()
	{   
		for(int i=0;i<=psize;i++)
		{
			cout<<P[i].get_item_id()<<"\t"<<P[i].get_item_name()<<"\t"<<P[i].get_price()<<endl;
		}
	}
	

    void show_customer()
    {
    	for(int i=0;i<=csize;i++)
		{
			cout<<C[i].get_age()<<"\t"<<C[i].gender<<"\t"<<C[i].get_customerid()<<"\t"<<
			C[i].get_gender()<<"\t"<<C[i].get_name()<<"\t"<<C[i].get_surename()<<endl;
		}
	}

    void search_product()
    {   string s;
    	cout<<" ENTER ID ";
    	cin>> s;
    	for(int i=0;i<=psize;i++)
    	{
    		if(P[i].get_item_id()==s)
    		{cout<<P[i].get_item_id()<<"\t"<<P[i].get_item_name()<<"\t"<<P[i].get_price()<<endl;
    		return;
			}
		}
		cout<<"Record not found ";
	}
	void searc_customer(){
		string s;
    	cout<<" ENTER ID ";
    	cin>> s;
    	for(int i=0;i<=csize;i++)
    	{
    		if(C[i].get_customerid()==s)
    		{
			cout<<P[i].get_item_id()<<"\t"<<P[i].get_item_name()<<"\t"<<P[i].get_price()<<endl;
    		return;
			}
		}
		cout<<"Record not found ";
	}
	
	void add_customer()
	{   string c_id,name,sure,gend,iname,iid;
	    int pric,age;
	    cout<<"Entre Teacher id ";
	    cin>>c_id;
		cout<<"entre name  ";
		cin>>name;
		cout<<"entre surename  ";
		cin>>sure;
		cout<<"Entre gender ";
		cin>>gend;
		cout<<"Entre Course name ";
		cin>>iname;
		cout<<"Entre credit hours ";
		cin>>iid;
		cout<<"Entre course code";
		cin>>age;
		cout<<"Entre course timig ";
		cin>>pric;
		csize++;
		C[csize].set_age(age);C[csize].set_customerid(c_id);C[csize].set_gender(gend);C[csize].set_name(name);
		C[csize].set_surname(sure);C[csize].p.set_item_id(iid);C[csize].p.set_item_name(iname);C[csize].p.set_price(pric);
	    
	}
  
    void delete_customer()
    {   string s;
    	cout<<"Entre ID";
    	cin>>s;
    	int i=0;
		for( i=0;i<=csize;i++)
    	{
    		if(C[i].get_customerid()==s)
    		{
			 break;
			}
		}
		while(i<csize)
		{
			C[i]=C[i+1];
			i++;
		}
		csize--;
	}
	void deleteproduc()
    {   string s;
    	cout<<"Entre ID";
    	cin>>s;
    	int i=0;
		for( i=0;i<=psize;i++)
    	{
    		if(P[i].get_item_id()==s)
    		{
			 break;
			}
		}
		while(i<psize)
		{
			P[i]=P[i+1];
			i++;
		}
		psize--;
	}
	
	void update_customer()
	{
		string c_id,name,sure,gend,iname,iid;
	    int pric,age;
	    string s;
    	cout<<"Enter ID";
    	cin>>s;
		for(int i=0;i<=csize;i++){
		if(C[i].get_customerid()==s)
		{
		
		cout<<"Enter Teacher  id ";
	    cin>>c_id;
		cout<<"Enter name  ";
		cin>>name;
		cout<<"Enter surename  ";
		cin>>sure;
		cout<<"Enter gender ";
		cin>>gend;
		cout<<"Enter course name ";
		cin>>iname;
		cout<<"Enter course id ";
		cin>>iid;
		cout<<"Enter credit hours";
		cin>>age;
	
		C[i].set_age(age);C[i].set_customerid(c_id);C[i].set_gender(gend);C[i].set_name(name);
		C[i].set_surname(sure);C[i].p.set_item_id(iid);C[i].p.set_item_name(iname);C[i].p.set_price(pric);
	     return;
	    }
	  }
	}
	
   void menu()
   { char c;
    while(true){
	
	system("cls");
   	cout<<"1.ADD Teacher DATA\n";
   	cout<<"2.Show  Teacher Data\n";
   	cout<<"3.Search Teacher DATA\n";
   	cout<<"4.Seach Teacher DATA\n";
   	cout<<"5.Delete  Teacher DATA\n";
   	cout<<"6.Update Teacher DATA\n";
    cout<<"7.EXIT\n";
	cout<<"Entre choice ";
   cin>>c;
   switch(c)
   {
   	case'1':
   		system("cls");
   		this->add_customer();
   		system("pause");
   		break;
   	case '2':
   		system("cls");
   		this->show_customer();
   		system("pause");
   		break;
  // case '3':
   	//    system("cls");
   	//	this->show_product();
   	//	system("pause");
   	//	break;
   case '3':
   	system("cls");
   		this->searc_customer();
   		system("pause");
   		break;
   	case '4':
   		system("cls");
   		this->search_product();
   		system("pause");
   		break;
   	case '5':
   		system("cls");
   		this->delete_customer();
   		system("pause");
   		break;
   	case '6':
   		system("cls");
   		this->update_customer();
   		system("pause");
   		break;
   	case '7':
   		exit(1);
	   default:
   		break;
   }
   }
   }
};

int main()
{
	data D;
    	D.menu();
}

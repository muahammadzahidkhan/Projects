#include<iostream>
#include<vector>
#include<string>
using namespace std;
//class representing product
class product
  {
	 private:
		    string p_name;
		   public:
		    int p_quantity;
		    double p_purchaseprice;
		    double p_saleprice;
		//constructor
		product(const string& name,int quantity,double purchaseprice,double saleprice)
		{
		  p_name=name;
		p_quantity=quantity;
		p_purchaseprice=purchaseprice;
		p_saleprice=saleprice;
	};
	void display() //function
	{
		cout<<"product name:"<<p_name<<endl;
		cout<<"quantity: "<<p_quantity<<endl;
		cout<<"purchase price:"<<p_purchaseprice<<endl;
		cout<<"saleprice :"<<p_saleprice<<endl;
		cout<<"total value:"<<p_quantity*p_purchaseprice<<endl;
		cout<<endl;
	}
	void sell(int quantitytosell)  //function
	{
		if (quantitytosell<=0){
		cout<<"invalid quantity.please enter a postive value"<<endl;
	}
	if(quantitytosell>p_quantity){
		cout<<"insafficiant quantity"<<endl;
	}
	  else {
	  	p_quantity-=quantitytosell;
	  	cout<<quantitytosell<<".."<<p_name<<"\tare sold."<<endl;
	  }
    }
	  string getname()  //  use getter function for product name
	  {
	  return p_name;
	}	
};

class inventroy   //another class
{
	private:
	vector<product>products;
	public:
		void addproduct()  //function 
		{
			string name;
			int quantity;
			double purchaseprice;
			double saleprice;
			cout<<"enter product name:";
			cin>>name;
			cout<<"enter quantity:";
			cin>>quantity;
			cout<<"purchase price:";
			cin>>purchaseprice;
			cout<<"saleprie:";
			cin>>saleprice;  
			product p(name,quantity,purchaseprice,saleprice);//create a producrt object and push it to the vector
			products.push_back(p);
		}
		void displayinventory()   //function
		{
			for( int i=0;i<products.size(); ++i){
				products[i].display();  // calling display
			}
		}
		void sellproduct(){   //function
			string name;
			int quantitytosell;
			cout<<"enter product name:"<<endl;
			cin>>name;
			cout<<"enter product quantity :"<<endl;
			cin>>quantitytosell;
			for(int i=0;i<name.size(); ++i)
			{
				if (products[i].getname()==name)  //use getter function
				{
					products[i].sell(quantitytosell);
					return;
				}
				}
			cout<<"product not found."<<endl;
	}
};
int main()
{
	inventroy shop;  //shop is object of the inventroy class
     int choice;
     do    //use do while loop
     {
     	cout<<"\t1 add product"<<endl;
     	cout<<"\t2 display product "<<endl;
     	cout<<"\t3 sell product"<<endl;
     	cout<<"\t4 exit "<<endl;
     	cout<<"\tenter your choice:"<<endl;
     	cin>>choice;
     	switch(choice){   //switch statment 
     		case 1:
     			shop.addproduct();  //function call
     			break;
     			case 2:
     				shop.displayinventory();  //funtion call
     				break;
     				case 3:
     					shop.sellproduct();   // funtion call
     					break;
     					case 4:
     						cout<<"exiting programm..."<<endl;
     						break;
     						default: 
     						cout<<"invalid choice.please try again ."<<endl;
     						break;
		 }
		 cout<<endl;
		 	 }
		 	 while(choice!=4);
		 	 return 0;
}

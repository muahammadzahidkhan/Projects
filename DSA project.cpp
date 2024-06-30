#include<iostream>
#include<iomanip>
using namespace std;
class product 
{
    public:
	   string name;
	   int quantity;
   	   double purprice;
	   double saleprice;
	   product* next ;
	
};
//class representing product
class inventory
  {
	 private:
		    product * head=NULL;
		    double totalprofit;
		public:
			inventory()
			{
				totalprofit = 0;
			}
             void insert()
              {
            	string name;
    	        int purprice;
    	        cout<<"enter name of the product\n";
    	        cin>>name;
    	        cout<<"enter purprice\n";
    	        cin>>purprice;
    	        int result= search(name,purprice);
    	          if (result==-1)
    	           {
    		          add_product(name,purprice);
		           }else{
			               cout<<result<<"  quantity are added\n";
	                   	}
	          }
             void add_product(string name,int purprice)
	          {
	            	product * temp = new product();
	//	cout<<"enter a product\n";
	//	cin>>temp->name;
	                temp->name=name;
	//	cout<<"enter quantity\n";
	//	cin>>temp->quantity;
	                temp->purprice=purprice;
		            
	            	cout<<"slaeprice\n";
             		cin>>temp->saleprice;
             		cout<<"enter quantity\n";
             		cin>>temp->quantity;
		
	            	product * tail = head;
    	             if (head==NULL)
    	               {
    		              head = temp;
		               }else{
			                  while(tail->next)
			                {
				                tail = tail->next;
			                }
			                tail->next = temp;
		                }
       
	            }
	        void display()
	          {
	          	   sorting();
	              cout<<"\t****All iteams of inventory*****\n";
	              product * temp = head;
            	  cout<<"\tname"<<setw(12)<<"quantity"<<setw(12)<<"Pprice"<<setw(12)<<"Sprice"<<endl;
                	  if(temp==NULL)
	                  {
	  	                 cout<<"\tproduct not avalibal in shop\n ";
	                  }
	                   while(temp)
	                   {
	  	                  cout<<"\t"<<temp->name<<setw(12)<<temp->quantity;
	                      cout<<setw(12)<<temp->purprice<<setw(12)<<temp->saleprice<<endl;
						  //cout<<setw(12)<<totalprofit<<endl;
	  	                  temp =temp->next;
	                    }
	                    cout<<"\ttotal profit is = "<<totalprofit<<endl;
	 
	           }
            void sellproduct()
             {
               	string name;
              	cout<<"___***enter a product you want to sale***___\n";
    	        cin>>name;
    	        int quantity;
             	cout<<"___***enter quantity***___\n";
    	        cin>>quantity;
    	
    	        product * temp = head;
    	        product * nullptr = NULL;
    	          while(temp!=nullptr)
                  {
    		         if (temp->name==name)
		        	{
    			       sell(temp ,quantity);
    			          return ;
    			    }
	                   temp = temp->next;
		           }
	                  cout<<"___***the product not avalibal___***\n";
	         }
           	int sell(product*ptr, int quantitosell)
             {
             	product* temp = ptr;
	            if(quantitosell>temp->quantity) 
	             {
	            	cout<<"___***insficiant product***___\n";
	             }else
				  if(quantitosell<=0)
	               {
	    	         cout<<"invilade number\n";
	               }else
	                    {
		                   temp->quantity-=quantitosell;
		                   cout<<"___***"<<quantitosell<<" quantity of  "<<temp->name<<"  are sold\n";
		                  double profit= (temp->saleprice-temp->purprice)*quantitosell;
		                  cout<<"___***profit ="<<profit;
		                   Tprofit(profit); 
	                   sorting();
					    }
	          }
           	void delete_product()
	         {
		        product * temp = head;
		        string name;
		        cout<<"enter a product name you want to delete\n";
		        cin>>name;
		        product * previous = NULL;
		         while(temp){
		           if(temp->name==name)
		             {
		               if(previous)
		                 {
                 			previous->next = temp->next;
	                     }else{
		                        head = temp->next;
	                           }
	                             delete temp;
	                             cout<<"the product deleted successfuly deleted\n";
	                              return;
	                 }
	                 previous = temp;
                     temp = temp-> next;
                                }
                   cout<<"the product you want to delete not found\n";
	           }
	           int search(string name ,int purprice)
	             {
		           product * temp = head;
             	   while(temp)
		            {
		              if(temp->name==name&&temp->purprice==purprice)
		               {
		               	 int quantity;
		               	 cout<<"enter a quantity\n";
		               	 cin>>quantity;
		               	 temp->quantity+=quantity;
			             return quantity;
		               }else
					    if(temp->name==name&&temp->purprice!=purprice){
		               	// temp->purprice =0;
		               	 temp->purprice = purprice;
		               	 int sale , quantity;
		               	 cout<<"enter sale price\n";
		               	 cin>>sale;
		               	 temp->saleprice = sale;
		               	 cout<<"enter quantity\n";
		               	 cin>>quantity;
		               	 temp->quantity+=quantity;
		               	 cout<<"prices are changed\n";
		               	 return quantity;
					   }
		                temp = temp->next;
	                }
	               return -1;
	             }
	             void sorting()
	             {
	             	bool swapped;
	             	product * temp;
	             	product* ptr = NULL;
	             	
	             	if(head == NULL)
	             	{
	             		return;
					 }
					 do
				 {
					 	swapped =false;
					 	temp = head;
					 	while(temp->next!=ptr)
					 	{
					 		if(temp->quantity>temp->next->quantity)
					 		{
					 			swap(temp , temp->next);
					 			swapped = true;
							}
							temp = temp->next;
						}
						//ptr=temp;
					 }while(swapped);
					 
				 }
	             void swap(product *a , product *b)
	             {
	                string tempname = a->name;
	                double temppurprice = a->purprice;
	                double tempsaleprice = a->saleprice;
					int tempquantity = a->quantity;
					
					a->name = b->name;
					a->purprice = b->purprice;
					a->saleprice = b->saleprice;
					a->quantity = b->quantity;
					
					b->name =  tempname;
					b->purprice = temppurprice ;
					b->saleprice = tempsaleprice ;
					b->quantity = tempquantity;
					
				 }
				 void Tprofit(double price)
				 {
					 totalprofit+= price; 
				 }
};

int main()
{
	inventory shop;     //shop is object of the inventroy class
     int choice;
     
     do    //use do while loop
     {
     	cout<<"\t__________________________"<<endl;
     	cout<<"\t||   1 insert product   ||"<<endl;
     	cout<<"\t||   2 display product  ||"<<endl;
     	cout<<"\t||   3 sale product     ||"<<endl;
     	cout<<"\t||   4 delete product   ||"<<endl;
     	cout<<"\t||   5 exit             ||"<<endl;
     	cout<<"\t__________________________"<<endl;
     	cout<<"\tenter your choice:"<<endl;
     	cin>>choice;
     	
     	switch(choice){   //switch statment 
     		case 1:
     			shop.insert();  //function call
     			break;
     			
     			case 2:
     				shop.display();  //funtion call
     				break;
     				
     				case 3:
     					shop.sellproduct();   // funtion call
     					break;
     					
     					case 4:
     						 shop.delete_product();
     						 break;
     					case 5:
     						cout<<"exiting programm..."<<endl;
     						break;
     						
     						default: 
     						cout<<"invalid choice.please try again ."<<endl;
     						break;
		 }
		 
		 cout<<endl;
		 	 }
		 	 while(choice!=5);
		 
		 
		 	 return 0;

}

#include<iostream>
using namespace std;

class Polynomial
{
	int degree ;
	int arr[1000];
	
	 public:
	 	
	 	Polynomial()
	 	{
	 		degree=1;
		}
		Polynomial(int deg)
		{
			
			cout<<"enter the degree of polynomial  "<<deg<<" : "<<endl;
			cin>>degree;
			degree++;	
		}
		~Polynomial()
        {
             cout<<"Destructor calls"<<endl ;
        }
     
        Polynomial operator +(Polynomial d)
		{
			Polynomial p;
			p.degree=this->degree>=d.degree? this->degree:d.degree;
			for(int i=0;i<p.degree;i++)
			{
				if(i>=this->degree)
				  this->arr[i]=0;
				if(i>=d.degree)
				  d.arr[i]=0;
				  p.arr[i]=d.arr[i]+this->arr[i];  
			}
			return p;
		}
		Polynomial operator -(Polynomial d)
		{
			Polynomial p;
			p.degree=this->degree>=d.degree? this->degree:d.degree;
			for(int i=0;i<p.degree;i++)
			{
				if(i>=this->degree)
				  this-> arr[i]=0;
				if (i>=d.degree)
				  d.arr[i]=0;
				  p.arr[i]=this->arr[i]-d.arr[i];  
			} 
		    return p;	
	    }
	    Polynomial operator =(Polynomial d)
		{
			Polynomial p;
			this->degree=d.degree;
			for(int i=0;i<this->degree;i++)
			  this->arr[i]=d.arr[i];
	    }
	    void storePolynomial()
        {
            cout<<"enter degree for first and second polynomial : "<<endl;
			for(int i=0;i<degree;i++)
			cin>>arr[i];
 	    }
 	    void display()
        {
            cout<<endl ;
            for(int i=0;i<degree;i++)
            {
            	cout<<arr[i]<<"X^"<<i;
            	if(i<degree-1)
            	  cout<<" + ";
			}
	    }
};
int main()
{
	  int degFirst=1, degSecond=2;
  Polynomial firstPolynomial(degFirst);
  Polynomial secondPolynomial(degSecond);
  Polynomial thirdPolynomial; 
  firstPolynomial.storePolynomial();
  secondPolynomial.storePolynomial(); 
  thirdPolynomial=firstPolynomial+secondPolynomial;
  Polynomial fourthPolynomial=firstPolynomial-secondPolynomial; 
  cout<<" 1st polynomial :"<<endl;
  firstPolynomial.display();
  cout<<endl;
  cout<<" 2nd polynomial : "<<endl;
  secondPolynomial.display();
  cout<<endl;
  cout<<" Addition of first and second polynomial is : "<<endl;
  thirdPolynomial.display();
  cout<<endl;
  cout<<" Subttaction of first and second polynomial is : "<<endl;
  fourthPolynomial.display();
}

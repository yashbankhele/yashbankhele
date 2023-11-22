
    #include <iostream>
    #include<string.h>
    using namespace std;
    struct node
    {
        char data;
        node *next;
    }*p = NULL, *top = NULL, *save = NULL,*ptr;

    void push(char x)
    {
        p = new node;
        p->data = x;
        p->next = NULL;
        if (top == NULL)
        {
            top = p;
        }
        else
        {
            save = top;
            top = p;
            p->next = save;
        }
    }

    char pop()
    {
        if (top == NULL)
        {
            cout<<"underflow!!";
        }
        else
        {
            ptr = top;
            top = top->next;
            return(ptr->data);
            delete ptr;
        }
    }  

    int main()
    {
        int i;
        char c[30], a, y, z;
        cout<<"enter the expression:\n";
        cin>>c;
        for (i = 0; i < strlen(c); i++)
        {
    	if ((c[i] == '(') || (c[i] == '{') || (c[i] == '['))
    	{
                push(c[i]);
    	}
    	else 
    	{
    	    switch(c[i])
    	    {
    		case ')':
                             a = pop(); 
    		         if ((a == '{') || (a == '['))
    			 {
    			     cout<<"invalid expr!!";
                               // return;
    			 }   
    			 break;
    		case '}':
                             y = pop();
    			 if ((y == '[') || (y == '('))
    			 {
    			     cout<<"invalid expr!!";
                                 //return;
    			 }   
    			 break;

    		case ']':
                             z = pop();
    			 if ((z == '{') || (z == '('))
    			 {
    			     cout<<"invalid expr!!";
                                // return;
    			 }   
    			 break;
    	    }
    	}

        }

        if (top == NULL)
        {
   	cout<<"balanced expr!!";
        }
        else
        {
    	cout<<"string is not valid.!!";
        }
        return 0;
    }

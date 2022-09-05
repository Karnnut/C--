#include <iostream>
#include "term.cpp"
using namespace std;
class Polynomial{
public:
    Poly_node* head;
    int count;
    Polynomial(){
        head = NULL;
        count = 0;
    }
    void addTerm(int coef, int exponent){
        Poly_node *newNode = new Poly_node;
        Poly_node *current = head;
        newNode -> coef = coef;
        newNode -> exponent = exponent;
        newNode -> next = NULL;
        if(count == 0){
            newNode -> next = head;
            head -> next == NULL;
            head = newNode;
            count ++;

        }else if (count == 1){
            if (exponent < head -> exponent){
                head -> next = newNode;
                newNode -> next = NULL;
                count ++;
            }else if (exponent > head -> exponent){   
                head = newNode;
                newNode -> next = current;
                count ++;
            }else{
                head -> coef += coef;
                delete newNode;
            }
        }else{
           if (exponent > head -> exponent){
                newNode -> next = head ;
                head = newNode;
                count ++;
            }else if ( exponent == head -> exponent){
                head -> coef += coef;
                delete newNode;
            }
            else{
                while(current -> next != NULL){
                    if(current -> next -> exponent > exponent){
                        current = current -> next;
                    }else{
                        break;
                    }                
                }
                if(current -> next == NULL){
                    current -> next = newNode;
                    count ++;
                }
                else if (exponent != current -> next -> exponent){
                    newNode -> next = current -> next;
                    current -> next = newNode;
                    count ++;
                }else{
                    current -> next -> coef += coef;
                    delete newNode;
                }    
            }
        }  
    }
    void printPolynomial(){
        cout<<"[ ";
        Poly_node* ptr = head;
        while(ptr!=NULL){
            if(ptr->coef==0){

            }else{
                cout<< ptr->coef<<"X^{"<<ptr->exponent<<"} ";
            }
            ptr = ptr->next;
        }
        cout<<"]\n";
    }
    void plus(Polynomial f2){
        Poly_node *current = f2.head;
        while(current != NULL){
            int cal_coef = current -> coef;
            int cal_exponent = current -> exponent;
            addTerm(cal_coef,cal_exponent);
            current = current -> next; 
        }
    }
    void minus(Polynomial f2){
       Poly_node *current = f2.head;
        while(current != NULL){
            int cal_coef = (current -> coef) * (-1);
            int cal_exponent = current -> exponent;
            addTerm(cal_coef,cal_exponent);
            current = current -> next; 
        }
    }
};
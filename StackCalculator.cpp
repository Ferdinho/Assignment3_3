//============================================================================
// Name        : StackCalculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/* This program is asking a user to input 2 large number,
and it will add them up using stacks */

#include <iostream>
#include"LinkedStack.h"
using namespace std;


int main() {

	LinkedStack<char> s1;
	LinkedStack<char> s2;
	LinkedStack<int> s3;

	string x,y;

	cout<<"Enter a very large number: ";
	cin>>x;
	for (int i= 0; i< x.size() ; i++){
		s1.push(x[i]);
	}
	cout<<"Enter a very large number: ";
	cin>>y;
	for (int i= 0; i< y.size() ; i++){
		s2.push(y[i]);
	}
	int carry = 0;
	int savedNumber;

	while(!s1.isEmpty() && !s2.isEmpty()){
		int num1 = s1.pop()-'0';
		int num2 = s2.pop() - '0' ;

		savedNumber = num1+ num2+ carry;
		if(savedNumber<10){
			carry = 0;
			s3.push(savedNumber);
		}
		else {
			carry = savedNumber/10;
			savedNumber =savedNumber%10;
		s3.push(savedNumber);
		}
	}
	while (!s1.isEmpty() && s2.isEmpty()){
		int num1 = s1.pop()-'0';
		savedNumber = num1+carry;
		if(savedNumber<10){
			carry = 0;
			s3.push(savedNumber);
		}
		else{
			carry = savedNumber/10;
			savedNumber =savedNumber%10;
			s3.push(savedNumber);
		}
	}
	while (s1.isEmpty()&& !s2.isEmpty()){
		int num2 = s2.pop() - '0' ;
		savedNumber = num2+ carry;
		if(savedNumber<10){
			carry = 0;
			s3.push(savedNumber);
		}
		else{
			carry = savedNumber/10;
			savedNumber =savedNumber%10;
			s3.push(savedNumber);
		}
	}
	if(carry != 0){
		s3.push(carry);
	}
	cout<< "The Sum "<<s3<<endl;
	return 0;
}

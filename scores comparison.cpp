#include <iostream>
#include <cmath>
using namespace std;


class Student{
    public://all variables and functions will be accessed everywhere, even outside the class

    int scores[5];//this will keep the scores for only 5 exams
    
    void input(){
        for(int i=0; i<5;i++){
        	cout<<"Enter the exam "<<i+1<<" score: ";
            cin>>scores[i];
        }
    };
    
    int sum;
    //this function will calculate the sum for all exams so that program will be able to compare using all summations
    int calculateTotalScore(){
        sum = 0;
        for(int i=0;i<5;i++){
            sum+=scores[i];
        }
        return sum;
    }
};

int main() {
    int n;
    //program will continue to execute so that you can compare yourself to others as you wish
    while(1){	
	cout<<"\n\nEnter the number of students you want to compare to, and include also you: "; // number of students plus me
    cin >> n;
    
    cout<<endl;

    Student *s = new Student[n]; // an array of total students you entered
    
    cout<<"My scores in all exams:"<<endl;
    for(int i = 0; i < 1; i++){
        s[i].input();
    };
    cout<<endl;
    
    cout <<"Scores for other "<<n-1<<" students:"<<endl;
    for(int i = 1; i < n; i++){
    	cout<<"student "<<i<<endl;
        s[i].input();
    };
    
    // calculate summation of my scores in 5 exams  
    int my_score = s[0].calculateTotalScore();

    // determine how many students scored higher than me
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();//determining the summation for each student of all 5 exams
        if(total > my_score){
            count++;
        }
    }
    
    //printing result
    cout<<endl;
    cout<<"Students with scores higher than you: "<<count;
    
    cout<<endl;
    cout<<endl;
    if(count==0){
    	cout<<"Conglatulations! You are the best";
	}
	else if(count>0){
		cout <<"you are the "<<count+1<<" student";
	}
}
    return 0;
}
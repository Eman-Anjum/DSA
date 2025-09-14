//Calculate the GPA of students using given subject grades (equal credit hours)
#include<iostream>
using namespace std;
class Result{
private:
    string name;
    float* grades;
    int subjectsEnrolled;
public:
    Result(string studentName,float* studentGrades,int count){
        name=studentName;
        subjectsEnrolled=count;
        grades=new float[subjectsEnrolled];
        for(int i=0;i<subjectsEnrolled;i++){
            grades[i]=studentGrades[i];
        }
    }
    ~Result(){
        delete[] grades;
    }
    double calculateGPA(){
        double totalGrades=0;
        for(int i=0;i<subjectsEnrolled;i++){
            totalGrades+=grades[i];
        }
        return totalGrades/subjectsEnrolled;
    }
    void displayResult(){
        cout<<"Student Name: "<<name<<endl;
        cout<<"GPA: "<<calculateGPA()<<endl;
    }
};
int main(){
    float aliGrades[]={3.66,3.33,4.0,3.0,2.66};
    float hibaGrades[]={3.33,3.0,3.66,3.0};
    float asmaGrades[]={4.0,3.66,2.66};
    float zainGrades[]={2.66,2.33,4.0};
    float faisalGrades[]={3.33,3.66,4.0,3.0,3.33};
    Result students[]={Result("Ali", aliGrades, 5),Result("Hiba", hibaGrades, 4),Result("Asma", asmaGrades, 3),Result("Zain", zainGrades, 3),Result("Faisal", faisalGrades, 5)
    };
    for(int i=0;i<5;i++){
        students[i].displayResult();
    }
    return 0;
}

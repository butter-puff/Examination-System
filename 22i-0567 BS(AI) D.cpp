#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <conio.h>
using namespace std;

const int maxquestions = 24;

class Quiz_Conduct {
protected:
    string selectcourse;
    string topictitle[3]; //three topics
    string mcq[9]; //9 mcqs per course
    string mcqoptions[9][4]; //each of the 9 mcqs has 4 options
    string truefalse[9]; //9 true/false per course
    string truefalseoptions[9][2];
    string descriptive[6]; //6 descriptive questions per course
    string correctoption[18]; //18 correct answers, 9 mcqs + 9 true/false
    string topic1_totalquestions[8][4];
    string topic2_totalquestions[8][4];
    string topic3_totalquestions[8][4];
    
    int correctanswersindex[25];
    
    

public:
	
    void read_file(string course) {
        ifstream file(course + ".txt");
        if (!file.is_open()) {
            cout << "File is not opening. Recheck." << endl;
            return;
        }
        
        for(int i=0; i<25; i++)
        {
        	correctanswersindex[i] = 0;
		}

        string line;
        int titlecount = 0;
        int mcqcount = 0;
        int correctoptcount = 0;
        int truefalsecount = 0;
        int descriptivecount = 0;
        int questioncount = 0;

        while (getline(file, line)) {
            if (line == "a5380ee") {
                getline(file, topictitle[titlecount]);
                titlecount++;
            }

            if (line == "2efcde9") {
    getline(file, mcq[mcqcount]);
    for (int i = 0; i < 4; i++) {  
        getline(file, mcqoptions[mcqcount][i]);
        size_t colonIndex = mcqoptions[mcqcount][i].find(':');
        if (colonIndex != string::npos) {
            mcqoptions[mcqcount][i] = mcqoptions[mcqcount][i].substr(colonIndex + 2);
        }
    }
    
    //If we don't do the following, the output will include the marker of the correct option as well
			//Here the text after the colons is extracted using the find function
			//std::string::npos appears when the find() operation doesn't work
			//using substr(colonsignplace+2) will get us to the position we want after :
    if (line.find("dabfac4:") != string::npos) {
        correctanswersindex[questioncount] = mcqcount;
    }
    mcqcount++;
    questioncount++;
}



            if (line == "b94d27b") {
    		getline(file, truefalse[truefalsecount]);
    		truefalsecount++;
		    for (int i = 0; i < 2; i++) {
		        getline(file, truefalseoptions[truefalsecount - 1][i]);
		        size_t colonIndex = truefalseoptions[truefalsecount - 1][i].find(':');
		        if (colonIndex != std::string::npos) {
		            truefalseoptions[truefalsecount - 1][i] = truefalseoptions[truefalsecount - 1][i].substr(colonIndex + 2);
		        }
		        if (line.find("dabfac4:") != string::npos) {
		            correctanswersindex[questioncount] = i;
		        }
		    }
		    questioncount++;
			}


            if (line == "88f7ace") {
                getline(file, descriptive[descriptivecount]);
                descriptivecount++;
                questioncount++;
            }

        }

        file.close();
    }

    void display() {
        for (int i = 0; i < 8; i++) { // initializing all the questions as empty strings
            for (int j = 0; j < 4; j++) {
                topic1_totalquestions[i][j] = " ";
                topic2_totalquestions[i][j] = " ";
                topic3_totalquestions[i][j] = " ";
            }
        }


       // Questions for Topic 1
    int topic1QuestionIndex = 0;

    for (int i = 0; i < 3; i++) {
        topic1_totalquestions[topic1QuestionIndex][0] = mcq[i]; // Inserting the MCQ question

        for (int j = 0; j < 4; j++) {
            topic1_totalquestions[topic1QuestionIndex][j + 1] = mcqoptions[i][j]; // Inserting the MCQ option
        }

        topic1QuestionIndex++;
    }

    for (int i = 0; i < 3; i++) {
        topic1_totalquestions[topic1QuestionIndex][0] = truefalse[i]; // Inserting the true/false question

        for (int j = 0; j < 2; j++) {
            topic1_totalquestions[topic1QuestionIndex][j + 1] = truefalseoptions[i][j]; // Inserting the true/false option
        }

        topic1QuestionIndex++;
    }

    for (int i = 0; i < 2; i++) {
        topic1_totalquestions[topic1QuestionIndex][0] = descriptive[i]; // Inserting the descriptive question
        topic1QuestionIndex++;
    }

    // Questions for Topic 2
    int topic2QuestionIndex = 0;

    for (int i = 3; i < 6; i++) {
        topic2_totalquestions[topic2QuestionIndex][0] = mcq[i]; // Inserting the MCQ question

        for (int j = 0; j < 4; j++) {
            topic2_totalquestions[topic2QuestionIndex][j + 1] = mcqoptions[i][j]; // Inserting the MCQ option
        }

        topic2QuestionIndex++;
    }

    for (int i = 3; i < 6; i++) {
        topic2_totalquestions[topic2QuestionIndex][0] = truefalse[i]; // Inserting the true/false question

        for (int j = 0; j < 2; j++) {
            topic2_totalquestions[topic2QuestionIndex][j + 1] = truefalseoptions[i][j]; // Inserting the true/false option
        }

        topic2QuestionIndex++;
    }

    for (int i = 2; i < 4; i++) {
        topic2_totalquestions[topic2QuestionIndex][0] = descriptive[i]; // Inserting the descriptive question
        topic2QuestionIndex++;
    }

    // Questions for Topic 3
    int topic3QuestionIndex = 0;

    for (int i = 6; i < 9; i++) {
        topic3_totalquestions[topic3QuestionIndex][0] = mcq[i]; 

        for (int j = 0; j < 4; j++) {
            topic3_totalquestions[topic3QuestionIndex][j + 1] = mcqoptions[i][j]; 
        }

        topic3QuestionIndex++;
    }

    for
(int i = 6; i < 9; i++) {
topic3_totalquestions[topic3QuestionIndex][0] = truefalse[i]; 
    for (int j = 0; j < 2; j++) {
        topic3_totalquestions[topic3QuestionIndex][j + 1] = truefalseoptions[i][j]; 
    }

    topic3QuestionIndex++;
}

for (int i = 4; i < 6; i++) {
    topic3_totalquestions[topic3QuestionIndex][0] = descriptive[i]; 
    topic3QuestionIndex++;
}

	
}

void quizrandomizer(int inputqs, int usertimeMinutes)
{
    string ans;
    srand(static_cast<unsigned int>(time(0)));
    int userinputqs = inputqs;
    int qspertopic = inputqs / 3;
    int timeLimit = usertimeMinutes * 60;

    auto startTime = std::chrono::steady_clock::now();
    auto currentTime = std::chrono::steady_clock::now();

    cout << "The quiz has started. You have " << timeLimit << " seconds left." << endl;

    for (int i = 7; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(topic1_totalquestions[i], topic1_totalquestions[j]);
    } //Using the Fischer-Yates method to shuffle

    cout << "Topic 1 Questions: " << topictitle[1] << endl;
    for (int i = 0; i < qspertopic; i++) {
        int randomIndex = rand() % 8;
        for (int j = 0; j < 4; j++) {
            cout << topic1_totalquestions[randomIndex][j] << endl;
        }
        currentTime = std::chrono::steady_clock::now();
        auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
        if (elapsedSeconds >= timeLimit) {
            cout << "Time has elapsed!" << endl;
            return;
        }
        cout << "--------------------" << endl;
        cin >> ans;
    }

    // Topic 2
    for (int i = 7; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(topic2_totalquestions[i], topic2_totalquestions[j]);
    } // Using the Fischer-Yates method to shuffle

    cout << "Topic 2 Questions: " << topictitle[2] << endl;
    for (int i = 0; i < qspertopic; i++) {
        int randomIndex = rand() % 8;
        for (int j = 0; j < 4; j++) {
            cout << topic2_totalquestions[randomIndex][j] << endl;
        }
        currentTime = std::chrono::steady_clock::now();
        auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
        if (elapsedSeconds >= timeLimit) {
            cout << "Time has elapsed!" << endl;
            return;
        }
        cout << "--------------------" << endl;
        cin >> ans;
    }
// Topic 3
    for (int i = 7; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(topic3_totalquestions[i], topic3_totalquestions[j]);
    } // Using the Fischer-Yates method to shuffle

    cout << "Topic 3 Questions: " << topictitle[3] << endl;
    for (int i = 0; i < qspertopic; i++) {
        int randomIndex = rand() % 8;
        for (int j = 0; j < 4; j++) {
            cout << topic3_totalquestions[randomIndex][j] << endl;
        }
        currentTime = std::chrono::steady_clock::now();
        auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
        if (elapsedSeconds >= timeLimit) {
            cout << "Time has elapsed." << endl;
            return;
        }
        cout << "--------------------" << endl;
        cin >> ans;
    }
    
    cout<<"This marks the end of the quiz. Thank you for attempting. You will be now redirected to the main menu"<<endl;
    
}


};

////////////////////////////////////////////////////////////////////////////////
class Teacher : public Quiz_Conduct
{
	string login;
	string password;
	string teacherlogins[11] = {"22i-0000", "22i-0001", "22i-0002", "22i-0003", "22i-0004", "22i-0005", "22i-0006", "22i-0007", "22i-0008", "22i-0009", "22i-0010"};
	
public:
Teacher()
{
	login = " ";
	password = " ";
}

void verifyTeachercredentials()
{	
	string rnum;
	bool rollnum_exists = false;
	
	while(rollnum_exists == false)
	{
		cout << "Enter your teacher ID: ";
	cin >> rnum;
	for(int i=0; i < 11; i++) {
		
		if(rnum == teacherlogins[i])
		{
			rollnum_exists = true;
			break;
		}
	}
		
		if(rollnum_exists==true)
		{
			cout<<"Correct"<<endl;
		}
		else
		cout<<"Not correct"<<endl;
	}
	
}



void assignTeacherPassword()
{	
	string userpass; // temporary password storage for verification
	bool passwordsuccess = false; //this will be used to break the loop
	
	
	cout<<"Set up a password for yourself. It needs to have minimum of 6 characters. The password must contain uppercase, lowercase, numeric digit, and special characters."<<endl;
	while(passwordsuccess == false)
	{
		cout<<"Enter password: ";
		userpass = " ";
		char enterkey = '\r';
		char backspace = '\b';
		
		char individualchar;
		 while ((individualchar = _getch()) != enterkey) 
    {
        if (individualchar == backspace)
        {
            if (!userpass.empty())
            {
                cout<<backspace<<backspace;
                userpass.erase(userpass.size() - 1);
            }
        }
        else
        {
            userpass = userpass + individualchar;
            cout << "*";
        }
    }
    cout << endl;
		
		
		bool checkpasswordsize;
		if (userpass.size()>=6)
		{
			checkpasswordsize = true;
		}
		else
		{
			checkpasswordsize = false;
		}
		
			bool specialcharcheck = false;
				for(int i=0; i<(userpass.size()); i++)
				{
					if( (userpass[i]>=32 && userpass[i]<=47) || (userpass[i]>=91 && userpass[i]<=96) || (userpass[i]>=123 && userpass[i]<=126))
					{
						specialcharcheck = true;
					}
			
				}
				
				
			bool numbercheck = false;
			 for(int i=0; i<(userpass.size()); i++)
				{
					if(userpass[i]>=48 && userpass[i]<=57)
					{
						numbercheck = true;
					}
			
				}
				
			bool lowercase = false; 
			for(int i = 0; i < userpass.size(); i++)
			{
			    if(userpass[i] >= 97 && userpass[i] <= 122)
			    {
			        lowercase = true;
			        break; // Once a lowercase character is found, no need to check further
			    }
			}

			bool uppercase = false; 
			for(int i = 0; i < userpass.size(); i++)
			{
			    if(userpass[i] >= 65 && userpass[i] <= 90)
			    {
			        uppercase = true;
			        break; // Once an uppercase character is found, no need to check further
			    }
			}

				
			if((uppercase == true) && (lowercase == true) && (numbercheck == true) && (specialcharcheck == true) && (checkpasswordsize == true))
				{	
					
					cout<<"Password verification successful."<<endl;
					password = userpass; //transferred to class variable 
					passwordsuccess = true; //loop breaks 
				}
				
			else {
				cout<<"Password entered is not correct."<<endl;
				if(uppercase == false){
					cout<<"Uppercase character missing"<<endl;
				}
				
				if(lowercase == false){
					cout<<"Lowercase character missing"<<endl;
				}
				
				if(numbercheck == false){
					cout<<"Number missing"<<endl;
				}
				
				if(specialcharcheck == false){
					cout<<"Special character missing"<<endl;
				}
				if(checkpasswordsize == false){
					cout<<"Password too short"<<endl;
				}
				
			}
	}
}

};


class Student
{
    string login;
    string rollnumdigits;
    string name;
    string password;
    int order;
    bool pf, oop, introcomp, datastruct, analysisalgo, softeng, researchmeth, bigdata, ai, dl, dip;
    /*int inputqs;
    int userTimeMinutes;*/
    

public:
	
	/*setinputqs()
	{
		cout<<"Enter how many questions you want for the quiz? It has to be a multiple of 3. Maximum 24 questions";
		cin>>inputqs;
	}
	
	setuserTimeMinutes()
	{
		cout<<"Enter in minutes the time of the quiz";
		cin>>inputqs;
	}
	
	int getinputqs()
	{
		return inputqs;
	}
	
	int getuserTimeMinutes()
	{
		return userTimeMinutes;
	}*/
	Student()
	{
		login = " ";
	    rollnumdigits = " ";
	    name = " ";
	    password = " ";
	    pf = 0;
	    oop = 0;
	    introcomp = 0;
		datastruct = 0; 
		analysisalgo = 0; 
		softeng = 0; 
		researchmeth = 0; 
		bigdata = 0;
		ai = 0;
		dl = 0;
		dip = 0;
	    
	}
    const int totalstudents = 216;
    void readStudentdata(Student students[]);
    void printStudentdata(Student students[]);
    void verifyStudentcredentials(Student students[]);
    Student& operator=(const Student& other);
    void assignPassword();
};

Student& Student::operator=(const Student& other) //operator overloading =
{
    if (this == &other)
        return *this;

    // Performing member assignment
    this->login = other.login;
    this->rollnumdigits = other.rollnumdigits;
    this->name = other.name;
    this->order = other.order;
    this->pf = other.pf;
    this->oop = other.oop;
    this->introcomp = other.introcomp;
    this->datastruct = other.datastruct;
    this->analysisalgo = other.analysisalgo;
    this->softeng = other.softeng;
    this->researchmeth = other.researchmeth;
    this->bigdata = other.bigdata;
    this->ai = other.ai;
    this->dl = other.dl;
    this->dip = other.dip;

    return *this;
}

void Student::readStudentdata(Student students[])
{
    ifstream file("studentlist.csv");
    if (!file.is_open()) {
        cout << "File is not opening. Recheck." << endl;
        return;
    }

    string line; //this will store the column heading which we don't want to read

    for (int i = 0; i < 2; i++) { //skipping the first three lines, hence we use a loop
        getline(file, line);
    }

    int studentcount = 0; //counter

    while (!file.eof() && studentcount < totalstudents) {
        getline(file, line);
        stringstream ss(line); //declaring stringstream object

        string order, rollnumdigits, name;
        string pf, oop, introcomp, datastruct, analysisalgo, softeng, researchmeth, bigdata, ai, dl, dip;
        getline(ss, order, ',');
        getline(ss, rollnumdigits, ',');
        getline(ss, name, ',');
        getline(ss, pf, ',');
        getline(ss, oop, ',');
        getline(ss, introcomp, ',');
        getline(ss, datastruct, ',');
        getline(ss, analysisalgo, ',');
        getline(ss, softeng, ',');
        getline(ss, researchmeth, ',');
        getline(ss, bigdata, ',');
        getline(ss, ai, ',');
        getline(ss, dl, ',');
        getline(ss, dip, ',');

        //converting the string to bool and setting the initial value to false, if string is 1, then display true
        bool pf_enroll = (pf == "1");
        bool oop_enroll = (oop == "1");
        bool introcomp_enroll = (introcomp == "1");
        bool datastruct_enroll = (datastruct == "1");
        bool analysisalgo_enroll = (analysisalgo == "1");
        bool softeng_enroll = (softeng == "1");
        bool researchmeth_enroll = (researchmeth == "1");
        bool bigdata_enroll = (bigdata == "1");
        bool ai_enroll = (ai == "1");
        bool dl_enroll = (dl == "1");
                bool dip_enroll = (dip == "1");

        Student new_student;
        new_student.login = "";
        new_student.rollnumdigits = rollnumdigits;
        new_student.name = name;
        new_student.order = 0;
        new_student.pf = pf_enroll;
        new_student.oop = oop_enroll;
        new_student.introcomp = introcomp_enroll;
        new_student.datastruct = datastruct_enroll;
        new_student.analysisalgo = analysisalgo_enroll;
        new_student.softeng = softeng_enroll;
        new_student.researchmeth = researchmeth_enroll;
        new_student.bigdata = bigdata_enroll;
        new_student.ai = ai_enroll;
        new_student.dl = dl_enroll;
        new_student.dip = dip_enroll;

        students[studentcount] = new_student;

        studentcount++;
    }

    file.close();
}

void Student::printStudentdata(Student students[])
{
    for (int i = 0; i < totalstudents; i++) {
        cout << "Roll Number: " << students[i].rollnumdigits << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "PF Enrollment: " << students[i].pf << endl;
        cout << "Data Structures Enrollment: " << students[i].datastruct << endl;
        cout << "INTRO COMP Enrollment: " << students[i].introcomp << endl;
        cout << "OOP Enrollment: " << students[i].oop << endl;
        cout << "Analysis of Algorithms Enrollment: " << students[i].analysisalgo << endl;
        cout << "Software Engineering Enrollment: " << students[i].softeng << endl;
        cout << "Research Methodology Enrollment: " << students[i].researchmeth << endl;
        cout << "Big Data Enrollment: " << students[i].bigdata << endl;
        cout << "AI Enrollment: " << students[i].ai << endl;
        cout << "Deep Learning Enrollment: " << students[i].dl << endl;
        cout << "Digital Image Processing Enrollment: " << students[i].dip << endl;
        cout << endl;
    }
}


void Student::assignPassword()
{	
	string userpass; // temporary password storage for verification
	bool passwordsuccess = false; //this will be used to break the loop
	
	
	cout<<"Set up a password for yourself. It needs to have minimum of 6 characters. The password must contain uppercase, lowercase, numeric digit, and special characters."<<endl;
	while(passwordsuccess == false)
	{
		cout<<"Enter password: ";
		userpass = " ";
		char enterkey = '\r';
		char backspace = '\b';
		
		char individualchar;
		 while ((individualchar = _getch()) != enterkey) 
    {
        if (individualchar == backspace)
        {
            if (!userpass.empty())
            {
                cout<<backspace<<backspace;
                userpass.erase(userpass.size() - 1);
            }
        }
        else
        {
            userpass = userpass + individualchar;
            cout << "*";
        }
    }
    cout << endl;
		
		bool checkpasswordsize;
		if (userpass.size()>=6)
		{
			checkpasswordsize = true;
		}
		else
		{
			checkpasswordsize = false;
		}
		
			bool specialcharcheck = false;
				for(int i=0; i<(userpass.size()); i++)
				{
					if( (userpass[i]>=32 && userpass[i]<=47) || (userpass[i]>=91 && userpass[i]<=96) || (userpass[i]>=123 && userpass[i]<=126))
					{
						specialcharcheck = true;
					}
			
				}
				
				
			bool numbercheck = false;
			 for(int i=0; i<(userpass.size()); i++)
				{
					if(userpass[i]>=48 && userpass[i]<=57)
					{
						numbercheck = true;
					}
			
				}
				
			bool lowercase = false; 
			for(int i = 0; i < userpass.size(); i++)
			{
			    if(userpass[i] >= 97 && userpass[i] <= 122)
			    {
			        lowercase = true;
			        break; // Once a lowercase character is found, no need to check further
			    }
			}

			bool uppercase = false; 
			for(int i = 0; i < userpass.size(); i++)
			{
			    if(userpass[i] >= 65 && userpass[i] <= 90)
			    {
			        uppercase = true;
			        break; // Once an uppercase character is found, no need to check further
			    }
			}
				
			if((uppercase == true) && (lowercase == true) && (numbercheck == true) && (specialcharcheck == true) && (checkpasswordsize == true))
				{	
					
					cout<<"Password verification successful."<<endl;
					password = userpass; //transferred to class variable 
					passwordsuccess = true; //loop breaks 
				}
				
			else {
				cout<<"Password entered is not correct."<<endl;
				if(uppercase == false){
					cout<<"Uppercase character missing"<<endl;
				}
				
				if(lowercase == false){
					cout<<"Lowercase character missing"<<endl;
				}
				
				if(numbercheck == false){
					cout<<"Number missing"<<endl;
				}
				
				if(specialcharcheck == false){
					cout<<"Special character missing"<<endl;
				}
				if(checkpasswordsize == false){
					cout<<"Password too short"<<endl;
				}
				
			}
	}
			
	
}

void Student::verifyStudentcredentials(Student students[])
{	
	string rnum;
	bool rollnum_exists = false;
	
	while(rollnum_exists == false)
	{
		cout << "Enter your roll number: ";
	cin >> rnum;
	for(int i=0; i < totalstudents; i++) {
		
		if(rnum == students[i].rollnumdigits)
		{
			rollnum_exists = true;
			break;
		}
	}
		
		if(rollnum_exists==true)
		{
			cout<<"Correct"<<endl;
		}
		else
		cout<<"Not correct"<<endl;
	}
	
}




int main() {
	
	//Declaring all the needed objects first
	Quiz_Conduct q1;
	Student* s1 = new Student[216];
	s1->readStudentdata(s1);
	Student s2;
	Teacher t1;
	
	//Declaring all the variables needed for the menu
    char menuchar;
    int time, numofqs;
    string coursename;
    bool quizflag = false;
     
    //loop for the menu begins, it only exits when you press E for Exit
    while(menuchar!='E'){
    	
	    cout<<"Are you a teacher or student? Enter T or S. Press E to exit."<<endl;
	    cin>>menuchar;
	    if(menuchar == 'T' || menuchar =='t')
	    {
	    	t1.verifyTeachercredentials();
	        t1.assignTeacherPassword();
	        cout<<"Verification complete"<<endl;
	        cout<<"A) Would you like to generate quiz?\nB) Do you want to check student details?\nC) Neither"<<endl;
	        cin>>menuchar;
	        if(menuchar == 'C')
	        {
	        	break;
			}
			
			else if(menuchar == 'B')
			{
				s2.printStudentdata(s1);
			}
			
			else if(menuchar == 'A')
			{
				quizflag = true;
				cout<<"Enter name of the course. Available courses are cs101, cs102, cs201, cs301, cs302, and se301: ";
				cin>>coursename;
				q1.read_file(coursename);
				q1.display();
				do {
			        cout << "Enter how many questions you would like in the quiz. You can enter maximum 24 questions, and a multiple of 3: ";
			        cin >> numofqs;
			        
			        if ((numofqs % 3 != 0) || (numofqs > 24)) {
			            cout << "Please enter the correct number of questions." << endl;
			        }
			    	} while ((numofqs % 3 != 0) || (numofqs > 24));
				
				cout<<"Enter the time for the quiz in minutes: ";
				cin>>time;
				cout<<"Quiz will be generated"<<endl;
			}
		}
		
		else if(menuchar == 'S' || menuchar == 's')
		{
			s2.verifyStudentcredentials(s1);
	        s2.assignPassword();
	        
	        if(quizflag==false)
	        {
	        	cout<<"The quiz has not been generated yet. Come back later"<<endl;
			}
			
			if(quizflag==true)
			{
				cout<<"Would you like to attempt quiz? Enter Y or N."<<endl;
				cin>>menuchar;
				
				if(menuchar=='y' || menuchar=='Y')
				{
					q1.quizrandomizer( numofqs,  time);
				}
				
				else if (menuchar == 'N' || menuchar == 'n')
				{
					break;
				}
				
				else
				{
					cout<<"Wrong key entered."<<endl;
				}
			}
		}
	}
return 0;}
    
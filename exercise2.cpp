




/*** 
 * In this program robot places the pegs in the slots according to user input.
 * There is one box with 9 slots in which a red peg, a green peg and a blue peg can be placed.
 * The robot asks for input about the slots to keep the peg.
 * 2D array with std::string is used to keep track of the slots.
 * The robot asks the user if they want place red pegs and if yes then in which slots.(similarly for all colors)
 * The order goes as follows first red then green and then blue. 
 * If at any time the slots get full the robot would not ask further placement question and ask to try yagain.
 * The robot at the ends asks the user to try again(y,n) if yes it runs again if no it exits.
***/






//Following libraries are used the standard input output, arrays and strings.
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>  


/*! Edits the arrays according to the input ptovided by the user.  
    \param red takes the input from user of place to put the peg.
    \param box is the array in which the robot has to place the box.
    \param correct is returned from the function back to the main.
    \param color is the color that is taken as input from the code. 
    \return correct "c" is return if the operation was successful otherwise "nc".
*/  
std::string new_box(std::string& red,std::array<std::array<std::string,3>,3>& box,std::string correct,std::string colour);

/*! To print dynamic question in problem.
    \param box takes input box to find the places left to be filled
    \return void function does not return anything
*/  

void dynamic_question(std::array<std::array<std::string,3>,3>& box);

//gobal vector to hold the value for the place left in the box
std::vector<std::string> values{};



// Function 1
std::string new_box(std::string& red,std::array<std::array<std::string,3>,3>& box,std::string correct,std::string colour){
    
    //input colour take r,g,b from the program as input
    std::string input_colur{};
    std::string white_space=" ";
    size_t pos = 0;
    //The while function makes substrings of the user input for place postion and changes its color.
    //It happens only if the conditions are met by the input values.
    while((pos = red.find(white_space)) != std::string::npos){
        
        input_colur=red.substr(0, pos);
        red.erase(0, pos + white_space.length());
       
          //if t1 is in 1-9 the program runs else exits and asks for try again.

        if(input_colur=="1" || input_colur=="2" || input_colur=="3" || input_colur=="4" || input_colur=="5" || input_colur=="6" || input_colur=="7" || input_colur=="8" || input_colur=="9" ){

            for(int i{};i<3;++i){
            
                for(int j{};j<3;++j){

                   
                    if(box.at(i).at(j)==input_colur){
                        box.at(i).at(j)=colour;
                        correct="c";
                    }
                }
            }
        }
    
        else{
            correct="nc";
            break;
        }
    }
   
   return correct;
}

// This prints the dynamic question position available
void dynamic_question(std::array<std::array<std::string,3>,3>& box){
    //global vector values is used to store the value
    values={};
    //if box.at(i).at(j) is r,g,b it is not stored in values and empty spaces are stored.
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){

            if(box.at(i).at(j)!="r" && box.at(i).at(j)!="g" && box.at(i).at(j)!="b"){
                values.push_back(box.at(i).at(j));
            }
            else{
                values.push_back(" ");
            }

        }
    }
    //empty spaces are removed.
    values.erase(std::remove(values.begin(), values.end(), " "), values.end());
    //iterator is used to print the value of the values vector.
    for (auto it = values.cbegin(); it != values.cend(); ++it)
        std::cout << " " << *it<<",";

}





int main(){
    // A string varibale Retry is defined to input run the do loop again and again untill user decides to exit.
    // An array vairable box with 3 rows and 3 columns is defined that contains slots from 1-9 in std::string.
    
    std::string Retry{};
    std::array<std::array<std::string,3>,3> box{{}};
    // This is the first do while loop that runs until the users answers "n" to Try Again(y,n)?
    do{
        // The string variable is initialised to empty again other wise the loop will run infinitely.
        // Box is initialised to the slot number.
        
        Retry={};
        box={{{"1","2","3"}, {"4","5","6"}, {"7","8","9"}}};

        // This is just to provide asthetic look to the output screen.

        std::cout<<"------------------------------------------------------"<<'\n';
        std::cout<<"EXERCISE 2"<<'\n';
        std::cout<<"------------------------------------------------------"<<'\n';

        // This displays the box array for the user.

        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                std::cout << box.at(i).at(j)<<" ";
                
                }
            std::cout<<'\n';
        }

        // This is just to provide asthetic look to the output screen.

        std::cout<<"-------------------------------------------------------"<<'\n';

        // The variable place_peg_or_not takes the input from user as "y" or "n".
        // if y then asks further question on where to place otherwise moves to the next color. 
        std::string place_peg_or_not{};
        do{
            std::cout<< "Do you want to place red pegs(y,n)?";
            std::getline(std::cin >> std::ws, place_peg_or_not);
  
        }
        while(place_peg_or_not!="y" && place_peg_or_not!="n");

        // The variable red_postion takes the user input about the postions as a string.
        // The correct vairbale is used to run the do while loop of the placement question.

        std::string red_position{};
        std::string correct{};

        do{
            // The correct variable is reintialised to empty when the loop is rerun.

            correct={};

            // If the user input y for the above question this question is displayed and asks for user input.

            if(place_peg_or_not=="y"){
        
                std::cout<< "Where do you want to place the red pegs"<<"(";
                dynamic_question(box);
                std::cout<<")?";
                std::getline(std::cin >> std::ws, red_position);
                

            }

            // Else the the program exits this loop.
            else{
                break;
            }

            red_position=red_position+" ";

            // correct calls the function new_box to place the pegs in slot input by user.
            // If input is not correct eg. 12 23 45 or ab bc db or any wrong input correct get the value "nc".
            // In such cases this do while loop is run gain. 
            correct=new_box(red_position,box,correct,"r");
        }
        while(correct!="c");

        // This is just to provide asthetic look to the output screen.

        std::cout<<"-------------------------------------------------------"<<'\n';


        // This displays the updated box array.

        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                std::cout << box.at(i).at(j)<<" ";
            }
            std::cout<<'\n';
        }

        // Just for formating
        std::cout<<'\n';

        // The variable place_peg_or_not takes the input from user as "y" or "n".
        // if y then asks further question on where to place otherwise moves to the next color.
        

        //Information on how many places still left to be filled.
        std::cout<<"Places left";
        dynamic_question(box);
        std::cout<<'\n';
        
        // if the place in the box a left then only it goes into this otherwise try again.
        if(!values.empty()){
        do{
            std::cout<< "Do you want to place green pegs(y,n)?";
            std::getline(std::cin >> std::ws, place_peg_or_not);
        }
        while(place_peg_or_not!="y" && place_peg_or_not!="n");

        // The variable red_postion takes the user input about the postions as a string.
        // The correct vairbale is used to run the do while loop of the placement question.
        //The rest of the program is similar to the above program.
        std::string green_position{};
    
        do{
            correct={};
        
            if(place_peg_or_not=="y"){
                std::cout<< "Where do you want to place the green pegs"<<"(";
                dynamic_question(box);
                std::cout <<")?"; 
                std::getline(std::cin >> std::ws, green_position);
            }
            else{
                break;
            }
   
        
        green_position=green_position+" ";
        
        correct=new_box(green_position,box,correct,"g");
        }
        while(correct!="c");

        std::cout<<"-------------------------------------------------------"<<'\n';
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                std::cout << box.at(i).at(j)<<" ";
            }
            std::cout<<'\n';
        }
        std::cout<<'\n';
        
        

        std::cout<<"Places left";
        dynamic_question(box);
        std::cout<<'\n';
        
        
        if(!values.empty()){
        do{
            std::cout<< "Do you want to place blue pegs(y,n)?";
            std::getline(std::cin >> std::ws, place_peg_or_not);
        }
        while(place_peg_or_not!="y" && place_peg_or_not!="n");

        std::string blue{};
    
        do{

            correct={};
        
            if(place_peg_or_not=="y"){
                std::cout<< "Where do you want to place the blue pegs"<<"(";
                dynamic_question(box);
                std::cout<<")?"; 
                std::getline(std::cin >> std::ws, blue);
            }
            else{
                break;
            }
        
        blue=blue+" ";

        correct=new_box(blue,box,correct,"b");
        }
        while(correct!="c");
        std::cout<<"-------------------------------------------------------"<<'\n';
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                std::cout << box.at(i).at(j)<<" ";
            }
        std::cout<<'\n';
        }
        }
        }

        std::cout<<'\n';
        std::cout<<"-------------------------------------------------------"<<'\n';
        do{
            std::cout<<"Try again(y,n)";
            std::getline(std::cin >> std::ws, Retry); 
        }
        while(Retry!="y" && Retry!="n");
    
    }
    while(Retry=="y" && Retry!="n");

}
/*** 
 * In the program robot picks up an object on the basis of user input(cube(c),ball(b),peg(p)).
 * Then prompts the user to input which gripper the robot should use(suction gripper(s),finger gripper(f))
 * Then prompts the user to which table the gripper should be put on(red(r),green(g),blue(b)).
 * Conditions are applied on each question and if inputs don'Retry match with condtions operation fails and try again is prompted
 * If all goes well it is a sucess other wise failure.
 * Input options are given with question for wrong inputs questions are asked again.
 * The program runs untill the user decides to not try again.
***/
#include<iostream>
#include<string>

int main(){
    //The variable object(user input) is the object the robot will pick up c,p and b.
    //The variable Retry(user input) is the for try again y or n.
    std::string object{};
    std::string Retry{};
 
    //The program from here is in a do while loop.
    //The outer do while loop is for the prompting the try again until user decides to stop.
    //The varibale Retry is initialize to a random string "a" so the when the loop repeats it is reinitalized.
    //Otherwise if the input is y or n the loop will run infinitely.
    do{
    Retry={};
    std::cout << "--------------------------------------------------"<<'\n';
    std::cout << "EXERCISE1"<<'\n';
    std::cout << "--------------------------------------------------"<<'\n';    

    //This do while loop prompts the question of which object to pick up.
    //Only exits when input is c or b or p.
        do{
            std::cout << "Which part to pick up (c, b, p)?";
            std::getline(std::cin >> std::ws, object);
            }
        while(object!="c" && object!="b" && object!="p");
        std::cout << "--------------------------------------------------"<<'\n';
   
    //The variable gripper(user input) is the gripper the robot will use to pick the object.
    //The do loop asks the user to input the gripper and exits only when input is s or f.
    std::string gripper{};
        do{
            std::cout <<"Which gripper to use(s,f)?";
            std::getline(std::cin >> std::ws, gripper);
         }
         while(gripper!="s" && gripper!="f");
    //Just for making the screen output asthetic
        std::cout << "--------------------------------------------------"<<'\n';
    
    //The variable table(user input) is the table on which the robot will put the object.
    //The do while loop asks the user to input the gripper and exits only when input is r or g or b.
    //Here if and else if is used to match the correct conditions provide in the question for object and gripper.
    //If conditions are not met the loop is broken by break statement and try again is prompted.
    std::string table{};
        do{
            if(object=="c"){
                if(gripper=="f"){
                    std::cout <<"Which table to use(r,g,b)?";
                    std::getline(std::cin >> std::ws, table);
                }
        
                else if(gripper=="s"){
                    std::cout << "Failure: Cannot pick up cube with suction gripper." <<'\n';
                    break;
                }
            }

            if(object=="b"){
                if(gripper=="s"){
                    std::cout <<"Which table to use(r,g,b)?";
                    std::cin >> table;
                }
          
                else if(gripper=="f"){
                    std::cout << "Failure: Cannot pick up ball with finger gripper." <<'\n';
                    break;
            }
            }
           
 
            if(object=="p"){
                if(gripper=="f"){
                    std::cout <<"Which table to use(r,g,b)?";
                    std::getline(std::cin >> std::ws, table);
                }
                else if(object=="p" && gripper=="s"){
                    std::cout << "Failure: Cannot pick up peg with suction gripper." <<'\n';
                    break;
                } 
            }                                                                               
    }
    while(table!="r" && table!="g" && table!="b");
    //Just for making the screen output asthetic
    std::cout << "--------------------------------------------------"<<'\n';

    //This if else if statement checks the conditions for the cube object.
    //Sucess if all conditions met otherwise try again is prompted.
    if(object=="c" && table=="r" && gripper =="f"){
        std::cout <<"Sucess: The cube was placed on the red table."<<'\n';
    }
    else if(object=="c" && table=="g" && gripper =="f"){
        std::cout <<"Failure: Cannot place cube on green table."<<'\n';
    }
    else if(object=="c" && table=="b"  && gripper =="f"){
        std::cout <<"Failure: Cannot place cube on blue table."<<'\n';       
    }

    //This if else if statement checks the conditions for the ball object.
    //Sucess if all conditions met otherwise try again is prompted.
    if(object=="b" && table=="g"  && gripper =="s"){
        std::cout <<"Sucess: The ball was placed on the green table."<<'\n';
    }
    else if(object=="b" && table=="r" && gripper =="s"){
        std::cout <<"Failure: Cannot place cube on red table."<<'\n';
    }
    else if(object=="b" && table=="b"  && gripper =="s"){
        std::cout <<"Failure: Cannot place cube on blue table."<<'\n';
    }

    //This if else if statement checks the conditions for the peg object.
    //Sucess if all conditions met otherwise try again is prompted.
    if(object=="p" && table=="b" && gripper =="f"){
        std::cout <<"Sucess: The peg was placed on the blue table."<<'\n';
    }
    else if(object=="p" && table=="r"  && gripper =="f"){
        std::cout <<"Failure: Cannot place cube on red table."<<'\n';
    }
    else if(object=="p" && table=="g"  && gripper =="f"){
        std::cout <<"Failure: Cannot place cube on green table."<<'\n';
    }
    //Just for making the screen output asthetic
    std::cout << "--------------------------------------------------"<<'\n';
    //This if and do while statement is used to prompt the try again on sucess or failure.
    if(Retry!="y" && Retry!="n"){
        do{
            std::cout <<"Try again(y,n)?";
            std::getline(std::cin >> std::ws, Retry);
            }
        while(Retry!="n" && Retry!="y");
        }
    //To add some space when the programs runs again to keep the output screen asthetic.
    std::cout <<'\n'<<'\n';
    }
    while(Retry=="y" && Retry!="n");    
}
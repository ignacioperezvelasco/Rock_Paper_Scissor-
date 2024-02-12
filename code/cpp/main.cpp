#include <iostream>
#include<unistd.h> 
enum types{ROCK,PAPER,SCISSOR,NONE};
int score=0;
int maxScore=score;

void PrintInstructions()
{
    std::system("clear");
    std::cout<<"Your score is: "<<score<< std::endl;
    std::cout<<"Best score: "<<maxScore<< std::endl;
    std::cout<<"Please select your choice and press 'enter':"<< std::endl<< std::endl;
    std::cout<<"    - Select paper pressing the key 'P'"<< std::endl;
    std::cout<<"    - Select rock pressing the key 'R'"<< std::endl;
    std::cout<<"    - Select scissor  pressing the key 'S'"<< std::endl;
    std::cout<<"    - Press 'E' to exit"<< std::endl << std::endl;
}

types mapInput(char x, bool firstCall)
{
    
    switch (x)
    {
    case 'p':
            return types::PAPER;
        break;
    case 'r':
            return types::ROCK;
        break;
    case 's':
            return types::SCISSOR;
        break;
    default:
        break;
    }    

        if(firstCall)
        {
            return mapInput((char) tolower(x),false); 
        }
        else            
           return types::NONE;
}
 
 void PrintPlayerChoice(types choice)
 {
    switch (choice)
    {
    case PAPER:
            std::cout<<"You have selected PAPER"<<std::endl;
        break;
    case ROCK:
            std::cout<<"You have selected ROCK"<<std::endl;
        break;
    case SCISSOR:
            std::cout<<"You have selected SCISSOR"<<std::endl;
        break;
    case NONE:
            std::cout<<"Unaviable choice"<<std::endl;
        break;
    
    default:
        break;
    }
 }
 void PrintOpponentsChoice(types choice)
 {
    switch (choice)
    {
    case PAPER:
        std::cout<<"Your opponent has selected PAPER!"<<std::endl;
        break;
    case ROCK:
        std::cout<<"Your opponent has selected ROCK!"<<std::endl;
        break;
    case SCISSOR:
        std::cout<<"Your opponent has selected SCISSORS!"<<std::endl;
        break;
    case NONE:
        std::cout<<"Unaviable choice"<<std::endl;
        break;    
    default:
        break;
    }
}

void PlayerWin()
{
    std::cout<<"You WIN!"<<std::endl;
    if(maxScore<++score)
    {
        maxScore=score;
    }

}
void PlayerLose()
{
    std::cout<<"You LOSE!"<<std::endl;
    score=0;
}

void DisplayResult(types playerChoice, types opponentsChoice)
{
        if(playerChoice==opponentsChoice)
    {
        std::cout<<"TIES!"<<std::endl;
    }
    else
    {
        switch (playerChoice)
        {
        case PAPER:
            if(opponentsChoice==SCISSOR)
                PlayerLose();
            else
                PlayerWin();
            break;
        case ROCK:

            if(opponentsChoice==PAPER)
                PlayerLose();
            else
                PlayerWin();
            break;
        case SCISSOR:

            if(opponentsChoice==ROCK)
                PlayerLose();
            else
                PlayerWin();
            break;
        case NONE:
            break;
        default:
            break;
        }
    }
}
  
void Result(char input)
{
    types playerChoice = mapInput(input,true);
    types enemyChoice = (types)(rand() % 3);

    PrintPlayerChoice(playerChoice);
    PrintOpponentsChoice(enemyChoice);
    sleep(1);
    DisplayResult(playerChoice,enemyChoice);

}

int main () 
{
    bool gameFinished=false;
    char input = (char) 0;

    //Instructions for game
    std::cout<<"Hello! Welcome to 'Papper Rock Scissor console game!" << std::endl << "Press any key to continue" ;
    std::cin.get();
    do
    {

        PrintInstructions();
        std::cin>>input;
        //check input
        std::system("clear");
        if(input == 'e' || input =='E')
            break;
        Result(input);


        sleep(5);

    } while (!gameFinished);
    std::cout<<"Thanks for playing!!"<< std::endl;
    sleep(3);
    system("clear");
    return 0;
}